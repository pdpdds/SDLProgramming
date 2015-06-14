/* block.h
The block class, used for instantiating the landscape of blocks
Programmers:
	Scott Grimes
	Vinny Birch
	Mike Duggan
	Kevin Sonnen
*/

#ifndef BLOCK_H
#define BLOCK_H

#include"mSDL.h"
#include<iostream>
#include<vector>
#include <iostream>
#include <cctype>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class block {
	public:
		block (int, int, int, int, ifstream& infile);	// Constructor
		
		SDL_Surface *display (SDL_Surface *, int, ifstream& infile);  // Displays the landscape on the screen
		int getY (int);	// Returns the y position of the highest block at the input x position
		int getX (int); // Returns the x position of the block requested, in terms of pixel count
		int getSize (int);	// Returns the number of blocks in a specific column
		int getCurrentY (int, int);	// Gets the y position of the input block
		int getBlockX (int k, int center); //Returns the x position of the kth block relative to the screen
		
		// Set functions
		void setOffset (int, int);
		void setLandscape (ifstream &infile);
		void setVertical ( int, int, int );
		void setRow ( int, int , int);
		void setStaircase_INCREASE ( int, int, int );
		void setStaircase_DECREASE ( int, int, int );

		void setFlag ( SDL_Surface * window, int ); // Places the flag on the screen
		void removeBlock ( int, int );	// Removes a block from the vectors
		int getLength ();	// Returns the length of the level in pixels
	  
	private:
		SDL_Surface * square;	// Surface for the image
		// Offsets for the blocks
		int xOffset;
		int yOffset;

		int WINDOW_HEIGHT;
		int WINDOW_WIDTH;
		int levelLength;	// Length of the level
		vector<int> xPositions;		// Vector containing the x positions of each block
		vector< vector<int> >yPositions; // Vector of vectors containing each y position for each x position
};

#endif
