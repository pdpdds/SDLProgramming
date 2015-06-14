/*
eagle.cpp
programmers:
	Scott Grimes
	Vinny Birch
*/

#include"mSDL.h"
#include"block.h"
#include "enemy.h"
#include "eagle.h"
#include "character.h"
#include<iostream>
#include<string>

const int EN_WIDTH = 180 / 4;		// constant for the width of the eagle sprite
const int EN_HEIGHT = 45;		// constant for the height of the eagle
const int GOING_RIGHT = 0;		// a constant that shows whether the image should be facing right relative to the user
const int GOING_LEFT = 1;		// constant that shows whether the EN is facing left relative to the user
const int HSPEED = EN_WIDTH / 10;	// constant for the speed at which the enemy moves horizontally

// =================================== Constructor =====================================
eagle::eagle (string filename, int windowWidth, int windowHeight, int x): enemy ( filename, windowWidth, windowHeight, x, EN_HEIGHT, EN_WIDTH, HSPEED) {
	yOffset = 10;
	jumpTime = 0;
	setFrames();
	setScore(30);	// Sets the amounts of points the player gets from killing an eagle
}



// =================================== Member Functions =====================================
/*
Moves the enemy based off of a coordinate of the leprechaun and block he is touching. The eagle
bounces forward. If it hits a block from the side, it turns around.
*/
void eagle::move (int templepxOffset, int templepxpos, block & floor) {

// Starts the character jumping if he collides with the ground
if( collideBottom (floor)){
      jumpTime = 0;
    }

// Checks for collision the sides of the blocks
collideRight (floor);
  collideLeft (floor);

// Eagle moves up if it's not hitting the bottom of a block and its jump time is less than a certain amount of time
      if (!topCollide (floor) && jumpTime <= 4)
	{
	  jumpOffset = 20; 
	// Checks for collision on the left with the landscape
	  if (collideLeft (floor))
	{
		speed = HSPEED;
		rWalk = true;
		lWalk = false;
	}
	// Check for collision on the right with the landscape
	else if (collideRight (floor))
	{
		speed = -HSPEED;
    		rWalk = false;
		lWalk = true;
	}
	}
	// He moves down if the time is over 4, or if he top collides
      else
	{
	  jumpOffset = -20;
// Checks for collisions after he's moved down
	topCollide(floor); 
	 if (collideLeft (floor))
	{
		speed = HSPEED;
		rWalk = true;
		lWalk = false;
	}
	// Check for collision on the right with the floor
	else if (collideRight (floor))
	{
		speed = -HSPEED;
    		rWalk = false;
		lWalk = true;
	}
	}
      jumpTime++;
      yOffset -= jumpOffset;
topCollide (floor);
     	 collideBottom(floor); 
	
	// Adjust the speed of the enemy with respect to the newly found collisions
	xpos += speed;
	xOffset = templepxOffset + (xpos - templepxpos);
	currentFrame += 1; // Changes the frame being displayed
	currentFrame = currentFrame % 2;
}


/*
The eagle's top collide function. Unlike the Trojan and the train, the eagle jumps, meaning
that it can collide with the bottom of a block, so it needs a top collision function
CHECKING AGAINST A BLOCK
xpos/50 is location of lep in terms of the block size
therefore, iterating through the locations (1, 2, ... )
*/
int
eagle::topCollide (block & floor)
{
  /*
     find the y positions of the bottom of a block
     check all the x positions of the block on that y position
   */
  for (int i = 0; i < floor.getSize (xpos / 50); i++)
    {
      if (yOffset <= floor.getCurrentY (xpos / 50, i) + 50
	  && yOffset > floor.getCurrentY (xpos / 50, i))
	{
	  yOffset = floor.getCurrentY (xpos / 50, i) + 50;	  
return 1;
	}
    }

// Checks if he's over two separate blocks
if(xpos/50!=(xpos+CHARACTER_WIDTH)/50)
    {
      for (int i = 0; i < floor.getSize (xpos / 50 + 1); i++)
	{
	  if (yOffset <= floor.getCurrentY (xpos / 50 + 1, i) + 50
	
      && yOffset > floor.getCurrentY (xpos / 50 + 1, i))
	    {
	      yOffset = floor.getCurrentY (xpos / 50 + 1, i) + 50;	      
return 1;
	    }

	}
    }
  return 0;
}



