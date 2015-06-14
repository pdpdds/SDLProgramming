/* 
File:
	enemy.cpp
Description:
	implementation of enemy class
Progammers:
	Scott Grimes
	Mike Duggan
	Vinny Birch
	Keven Sonnen
*/

#include"enemy.h"


// =================================== Constructor =====================================
enemy::enemy (string filename, int windowWidth, int windowHeight, int x,
	      int EN_HEIGHT, int EN_WIDTH, int HSPEED):
character (filename, NULL, windowWidth, windowHeight, EN_HEIGHT, EN_WIDTH)
{				//constructor: allows for inheritance from character

  HSPEED2 = HSPEED;
  speed = HSPEED;
  xOffset = 0;
  yOffset = 0;
  xpos = x;
  currentFrame = 0;
  lWalk = false;
  rWalk = true;
  frameLeft = new SDL_Rect[2];	//dynamically allocates array of sdl rects for 
  //clipping sprites
  frameRight = new SDL_Rect[2];
  setFrames ();
}


// =================================== Member Functions =====================================
/*
Moves the enemy based off of a coordinate of the leprechaun and block he is touching
*/
void
enemy::move (int templepxOffset, int templepxpos, block & floor)
{

  // Set the enemy's understanding where the leprechaun is
  lepxOffset = templepxOffset;
  lepxpos = templepxpos;

  // Check for collision on the left with the floor
  if (collideLeft (floor))
    {
      speed = HSPEED2;
      rWalk = true;
      lWalk = false;
    }
  // Check for collision on the right with the floor
  else if (collideRight (floor))
    {
      speed = -HSPEED2;
      rWalk = false;
      lWalk = true;
    }

  // Adjust the speed of the enemy with respect to the newly found collisions
  xpos += speed;
  xOffset = lepxOffset + (xpos - lepxpos);
  currentFrame += 1;
  currentFrame = currentFrame % 2;

  // Check for collision on the bottom of the enemy
  if (!collideBottom (floor))
    {
      jumpOffset = -26;
      yOffset -= jumpOffset;
      collideBottom (floor);
    }
}

/*
Set the frames of the enemy to the created sprites
*/
void
enemy::setFrames ()
{

  frameRight[0].x = 0;
  frameRight[0].y = 0;
  frameRight[0].w = CHARACTER_WIDTH;
  frameRight[0].h = CHARACTER_HEIGHT;

  frameRight[1].x = CHARACTER_WIDTH;
  frameRight[1].y = 0;
  frameRight[1].w = CHARACTER_WIDTH;
  frameRight[1].h = CHARACTER_HEIGHT;

  frameLeft[0].x = CHARACTER_WIDTH * 2;
  frameLeft[0].y = 0;
  frameLeft[0].w = CHARACTER_WIDTH;
  frameLeft[0].h = CHARACTER_HEIGHT;

  frameLeft[1].x = CHARACTER_WIDTH * 3;
  frameLeft[1].y = 0;
  frameLeft[1].w = CHARACTER_WIDTH;
  frameLeft[1].h = CHARACTER_HEIGHT;
}

/*
Update the enemy with respect to his movement
Use appropriate sprits
*/
SDL_Surface *
enemy::update (SDL_Surface * window)
{

  if (rWalk && !lWalk)
    {
      apply_image (characterImage, window, &frameRight[currentFrame], xOffset,
		   yOffset);
    }

  if (lWalk && !rWalk)
    {
      apply_image (characterImage, window, &frameLeft[currentFrame], xOffset,
		   yOffset);
    }

  return window;
}



/*
Check for collisions on the right side
*/
int
enemy::collideRight (block & floor)
{

  /*
     Check to see if the enemy is walking right
     and, 
     the x position of the enemy is less than his speed to make sure that he does not go into the block
   */
  if (rWalk && !lWalk
      && floor.getX (xpos / 50 + 1) - (xpos + CHARACTER_WIDTH) < speed)
    {
      // Iterate through the leprechaun's yposistions to check against the enemies positions
      for (int j = yOffset; j <= yOffset + CHARACTER_HEIGHT; j++)
	{
	  // Find the block's y position 
	  for (int i = 0; i < floor.getSize (xpos / 50 + 1); i++)
	    {
	      if (j > floor.getCurrentY (xpos / 50 + 1, i)
		  && j < floor.getCurrentY (xpos / 50 + 1, i) + 50)
		{
		  xpos = floor.getX (xpos / 50 + 1) - CHARACTER_WIDTH;
		  xOffset = lepxOffset + (xpos - lepxpos);
		  return 1;
		}
	    }
	}
    }

  return 0;
}

//function to check for enemy collision with the left side (similar to right function above)
int
enemy::collideLeft (block & floor)
{

  if (lWalk && !rWalk && xpos - floor.getX (xpos / 50) < -speed)
    {
      for (int j = yOffset; j <= yOffset + CHARACTER_HEIGHT; j += 1)
	{
	  for (int i = 0; i < floor.getSize (xpos / 50 - 1); i++)
	    {
	      int blockY = floor.getCurrentY (xpos / 50 - 1, i);
	      if (j > floor.getCurrentY (xpos / 50 - 1, i)
		  && j < floor.getCurrentY (xpos / 50 - 1, i) + 50)
		{
		  xpos = floor.getX (xpos / 50);
		  xOffset = lepxOffset + (xpos - lepxpos);
		  return 1;
		}
	    }
	}
    }

  return 0;
}


/*
return the y offset of the enemy,
with repect to the right side of screen
*/
int
enemy::getypos ()
{

  return yOffset;
}


/*
return the x position of the enemy,
with respect to the start of the game
*/
int
enemy::getxpos ()
{				//return the xpos of the enemy

  return xpos;
}

int
enemy::getScore ()
{				//return the score value from the enemy
  return score;
}

void
enemy::setScore (int s)
{				//sets the score value to an int
  score = s;
}
