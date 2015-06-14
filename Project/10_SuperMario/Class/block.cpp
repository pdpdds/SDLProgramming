/* 
File:	block.cpp
Programmers:
	Scott Grimes
	Vinny Birch
	Mike Duggan
	Kevin Sonnen
*/


#include"block.h"
#ifdef WIN32
#include "util.h"
#else
#include <sys/time.h>
#endif

#include <time.h>
#include <deque>


// Global variables used for the block's dimensions
const int BLOCK_HEIGHT = 50;
const int BLOCK_WIDTH = 50;
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;


// ========================= Constructor =============================
block::block (int windoww, int windowh, int length, int y, ifstream& infile)
{
	// Load the file and initialize block's offsets
	square = load ("block.png");
	xOffset = 0;
	yOffset = 0;
	WINDOW_WIDTH = windoww;
	WINDOW_HEIGHT = windowh;

	// Initialize Variables
		// Level length is how long the leprechaun is able to go
		levelLength = length;
		// Position is the location of the block (with respect to pixels) (therefore increments by BLOCK_WIDTH, or 50)
		int position = 0;

	// Set the base level of landscape (The floor)
	while (position <= levelLength)
	{
		// increase the size of the ground of the landscape vector
		xPositions.push_back (position);
		
		// temp vector to hold the height of the block
		vector<int> temp;
		temp.push_back (WINDOW_HEIGHT - BLOCK_HEIGHT);
		yPositions.push_back (temp);
		
		// Increase the position of the block
		position += BLOCK_WIDTH;
	}
	
	// Set the landscape based on a text file
	setLandscape( infile );
}

// ========================== Member Functions =========================
// This sets the offset of a block to a specified location
void block::setOffset (int x, int y) {
	xOffset = x;
	yOffset = y;
}

/*
i is the block's location (with repect to block count) (therefore a number like 1, 2, ... )
Only used for testing purposes
*/
int block::getY (int xpos) {
	int i = xpos / 50 + 2;

	// yPosistions[i].size() is the height of the block (not with respect to pixels, rather a level)
	return yPositions[i][yPositions[i].size () - 1];
}


// Returns the x position of the block (with repect to pixel count)
int block::getX (int x) {
	return xPositions[x];
}


// Input current block location (x) to return the height of that block with respect to pixel count
int block::getSize (int x) {
	return yPositions[x].size ();
}


/*
returns the y position of the block (relative to level, not pixel count)
(x) is the location of the block in the vector and (element) is the height of the block
*/
int block::getCurrentY (int x, int element) {
	return yPositions[x][element];
}


/*
Returns the x position of the kth block relative to the screen
*/
int block::getBlockX (int k, int center) {
	return xPositions[k] - center + WINDOW_WIDTH / 2 + BLOCK_HEIGHT;
}



//Function for the landscape, Provides ability to make new levels
void block::setLandscape ( ifstream &infile ) {
	// Initialize time for random variables
	timeval time;
	gettimeofday ( &time, NULL ); // Randomizes time
	srand ( (time.tv_sec * 1000) + (time.tv_usec / 1000) );

}


// Returns the SDL_Surface with the blocks to the main screen
SDL_Surface * block::display (SDL_Surface * window, int center, ifstream &infile) {

	// variable that determines which block is at the current center of the screen
	int currentBlock = center / 50;
	int k = center / 50 - 8;
	
	if (k < 0)
		k = 0;
		
	// goes through and displays nine blocks before and behind the center block
	for (; k < center / 50 + 8; ++k)
	{
		for (int j = 0; j < yPositions[k].size (); j++)
		{
			apply_image (square, window, NULL,
			xPositions[k] - center + WINDOW_WIDTH / 2 +
			BLOCK_HEIGHT, yPositions[k][j]);
		}
	}
	
	// For setting landscape via file input
		// Local variables
			// For the regions
			int sectionLength = 0;		// width of each section (block levels)
			int sectionLocation = 0;	// location of the section (in block levels)
			int levelLenght = 0;		// length in block levels
			
			// For the shape specifications
				// Ints for getting from the file to the deque
				int type;		// varies from 0 to 4
				int location;		// varies from 0 to 10
				int level;		// varies from 0 to 2
				int size;		// varies from 1 to 6 (depending on type)
				string comment;		// comments in the file
				
				// Deques for storing the information from the file
				deque<int> shapeType;
				deque<int> shapeLocation;
				deque<int> shapeLevel;
				deque<int> shapeSize;
		
		// Going through the file to read the input
		infile >> levelLength;
			
			while ( !infile.eof() )
			{
				// Read in from the file
				infile >> type >> location >> level >> size;
				
				// Increment the deques
				shapeType.push_back (type);
				shapeLocation.push_back (location);
				shapeLevel.push_back (level);
				shapeSize.push_back (size);
			}
						
			// location, level, size
				
			for ( int i = 0; i < shapeType.size(); i++ )
			{
				switch (shapeType[i]) // The preset types of landscape
				{
					case 0:		// for row
					{
						square = load ("block.png");
						setRow ( shapeLocation[i] - 1, shapeLevel[i], shapeSize[i] );
						break;
					}
					
					case 1:		// for vertical
					{
						square = load ("block.png");
						setVertical ( shapeLocation[i] - 1, shapeLevel[i], shapeSize[i] );
						break;
					}
					
					case 2:		// for staircase (increasing)
					{
						square = load ("block.png");
						setStaircase_INCREASE ( shapeLocation[i] - 1, shapeLevel[i], shapeSize[i] );
						break;
					}
					
					case 3:		// for staircase (decreasing)
					{
						square = load ("block.png");
						setStaircase_DECREASE ( shapeLocation[i] - 1, shapeLevel[i], shapeSize[i] );
						break;
					}
					
					case 4:		// for gap
					{
						square = load ("block.png");
						removeBlock ( shapeLocation[i] - 1, shapeSize[i] );
						break;
					}
					
					case 5:		// for inserting the flag
					{
						square = load ("flag.png");
						setFlag (window, shapeLocation[i] - 1 );
					break;
					}
					default:
					{
						square = load ("block.png");
						removeBlock ( shapeLocation[i] - 1, shapeSize[i] );
						break;
					}
				}
				
				sectionLocation++;
			}
	
	
	return window;
}



// ===================== functions for creating shapes of blocks ==================
/*
for creating a row of blocks
inputs:
	location (xpos)
	level ( 2 - 4 )
	lenght of the row of blocks
*/
void block::setRow ( int xpos, int baselevel, int length ) {

	baselevel = baselevel + 2;

	for ( int i = 0; i < length; i++ )
	{
		yPositions[xpos+i].push_back (WINDOW_HEIGHT - baselevel * BLOCK_HEIGHT);
	}
}


/*
for creating a column of blocks
inputs:
	location (xpos)
	base level ( 1 - 4 )
	height of the column
*/
void block::setVertical ( int xpos, int baselevel, int height ) {

	for ( int i = 2; i < height+2; i++ )
	
	{
		yPositions[xpos].push_back (WINDOW_HEIGHT - (baselevel+i) * BLOCK_HEIGHT);
	}
}


/*
for a staircase that increases in size from right to left
inputs:
	location (xpos)
	base level ( 1 - 4 )
	size of the staircase
*/
void block::setStaircase_INCREASE ( int xpos, int baselevel, int size ) {

	baselevel = baselevel + 2;
	
	int count = 0;

	for ( int row = 0; row < baselevel+size; row++ )
	{
		for ( int column = 0+count; column < size; column++ )
		{
			yPositions[xpos+column].push_back (WINDOW_HEIGHT - (baselevel+row) * BLOCK_HEIGHT);
		}
		count++;
	}
}

/*
for a staircase that decrases in size from right to left
inputs:
	location (xpos)
	base level ( 1 - 4 ),
	size of the staircase
*/
void block::setStaircase_DECREASE ( int xpos, int baselevel, int size ) {

	baselevel = baselevel + 2;

	int count = 0;

	for ( int column = 0; column < size; column++ )
	{
		for ( int row = 0; row < size-count; row++ )
		{
			yPositions[xpos+column].push_back (WINDOW_HEIGHT - (baselevel+row) * BLOCK_HEIGHT);
		}
		count++;
	}
}

/*
for removing a block
inputs:
	location (xpos)
	baselevel ( 1 - 4 )
*/
void block::removeBlock ( int xpos, int length ) {

	for ( int i = 0; i < length; i++ )
	{
		yPositions[xpos+i].clear();
	}
}


// Returns the length of the level
int block::getLength ()
{

	return levelLength*BLOCK_WIDTH;
}

// Sets the flag
void
block::setFlag ( SDL_Surface * window, int location ) {

	square = load ("flag.png");
	apply_image (square, window, NULL, 50*location, 0);
}









