/* 
File:
	player.cpp 
Description:
	Contains implementation for the player.h class as defined in the file player.h
	Initials the x, y positions of the player as well as which way the player is facing, it's speed and how it responds to the keys. Allows for movement while "in the air"
	Conatins collision functions for player for enemies and landscape
	Also includes the SDL_Delay function to make motion and animation more noticeable
	NOTE: implementation strategy for this class comes from the following URL: http://lazyfoo.net/SDL_tutorials/lesson20/index.php
Progammers
	Scott Grimes
	Mike Duggan
	Vinny Birch
	Kevin Sonnen
*/

#include"player.h"		// include header file for the player class
#include"mSDL.h"		// includes sdl commands and SDL libraries
#include<iostream>
#include<math.h>
#include "block.h"
#include "SDLSingleton.h"
using namespace std;


//Constants:
const int PLAYER_HEIGHT = 91 / 2;	// height of the player image clip in pixels (used to define sprite sheet boundaries)
const int PLAYER_WIDTH = 196 / 4;	// width of the player image clip in pixels (used to define sprite clips)
const int GOING_RIGHT = 0;	// a constant that shows whether the image should be facing right relative to the user
const int GOING_LEFT = 1;	// constant that shows whether the player is facing left relative to the user
const int HSPEED = PLAYER_WIDTH / 4;	// constant for the average run value
const int HSPRINT = PLAYER_WIDTH / 3.5;	// constant for the average sprint value



//constructor for player objects
player::player (string filename, string backgroundName, int windowWidth,
		int windowHeight, SDL_Surface * Window):
character (filename, Window, windowWidth, windowHeight, PLAYER_HEIGHT,
	   PLAYER_WIDTH)
{

  // Player specs
  xOffset = 50;			// horizontal offset for the player
  yOffset = 430 - CHARACTER_HEIGHT;	// vertical offset for the player
  speed = 0;			// speed of the player
  currentFrame = 0;		// current state of animation on leprechaun sprite sheet
  jumpOffset = 0;		// current y position offset on screen
  status = GOING_RIGHT;		// initializes leprechaun to face right, status is the direction of the player

  frameLeft = new SDL_Rect[4];
  frameRight = new SDL_Rect[4];
  setFrames ();			// clips sprite sheet for animation
  background = loadBackground (backgroundName);
  bgX1 = 0;			//offset for first background image
  bgX2 = background->w;		//offset for second background image

  // Bool values for walking specs
  lWalk = false;		//bool value for whether the player is walking left
  rWalk = false;		//bool value for whether the player is walking right
  sprint = false;		//bool value for whether the player is sprinting

  xpos = 50;			//initial player position
  score = 0;			//initial score 
  center = WINDOW_WIDTH / 2 + CHARACTER_WIDTH;	//initial center of screen position
  //  floor = new block (WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);
  isJump = false;		//bool for whether player is jumping
  time = 0;			//time value for jumping motion
}


// deconstructor for player objects: frees the two SDL_Surfaces created in this class
player::~player ()
{

  SDL_FreeSurface (background);
}


// takes user input using keystates instead of input
int
player::keyInput(block & floor)
{

	int numkeys;
	Uint8 *keystate = (Uint8*)SDL_GetKeyboardState(&numkeys);

	// User quits
	if (keystate[SDL_GetScancodeFromKey(SDLK_q)])
		return 1;

	// User hits the jump buttom ('w') and the leprechaun is in collision with the top of a block
	if ((keystate[SDL_GetScancodeFromKey(SDLK_w)] || keystate[SDL_GetScancodeFromKey(SDLK_COMMA)]) && collideBottom(floor))
	{
		isJump = true;
	}

	// Check for user's movement
	// Going right
	if (keystate[SDL_GetScancodeFromKey(SDLK_d)] || keystate[SDL_GetScancodeFromKey(SDLK_e)])
		rWalk = true;
	else
		rWalk = false;

	// Going left
	if (keystate[SDL_GetScancodeFromKey(SDLK_a)] && xpos != 0)
		lWalk = true;
	else
		lWalk = false;

	// Sprinting left or right
	if (keystate[SDL_GetScancodeFromKey(SDLK_RSHIFT)] || keystate[SDL_GetScancodeFromKey(SDLK_LSHIFT)])
		sprint = true;
	else
		sprint = false;

	return 0;
}


/*
based on function from URL cited above
separates lep.png sprite sheet into 8 different cells
four on top are the right facing leprechauns
the four on the bottom are the right facing leprechauns
clips the sprite sheet in eight positions to adjust for left/right motion
*/
void
player::setFrames ()
{

  // four sprites of player going right 
  frameRight[0].x = 0;
  frameRight[0].y = 0;
  frameRight[0].w = CHARACTER_WIDTH;
  frameRight[0].h = CHARACTER_HEIGHT;

  frameRight[1].x = CHARACTER_WIDTH;
  frameRight[1].y = 0;
  frameRight[1].w = CHARACTER_WIDTH;
  frameRight[1].h = CHARACTER_HEIGHT;

  frameRight[2].x = CHARACTER_WIDTH * 2;
  frameRight[2].y = 0;
  frameRight[2].w = CHARACTER_WIDTH;
  frameRight[2].h = CHARACTER_HEIGHT;

  frameRight[3].x = CHARACTER_WIDTH * 3;
  frameRight[3].y = 0;
  frameRight[3].w = CHARACTER_WIDTH;
  frameRight[3].h = CHARACTER_HEIGHT;


  // four frames of animation for when player is going left (below images of player going right)
  frameLeft[0].x = 0;
  frameLeft[0].y = CHARACTER_HEIGHT;
  frameLeft[0].w = CHARACTER_WIDTH;
  frameLeft[0].h = CHARACTER_HEIGHT;

  frameLeft[1].x = CHARACTER_WIDTH;
  frameLeft[1].y = CHARACTER_HEIGHT;
  frameLeft[1].w = CHARACTER_WIDTH;
  frameLeft[1].h = CHARACTER_HEIGHT;

  frameLeft[2].x = CHARACTER_WIDTH * 2;
  frameLeft[2].y = CHARACTER_HEIGHT;
  frameLeft[2].w = CHARACTER_WIDTH;
  frameLeft[2].h = CHARACTER_HEIGHT;

  frameLeft[3].x = CHARACTER_WIDTH * 3;
  frameLeft[3].y = CHARACTER_HEIGHT;
  frameLeft[3].w = CHARACTER_WIDTH;
  frameLeft[3].h = CHARACTER_HEIGHT;
}



//adjusts the horizontal offset of the player : based on URL above
void
player::move (block & floor)
{
  //calculate current speed (for no accelerator)
  //check if right arrow hit
  if (rWalk == true && lWalk == false)
    {
      if (xOffset == WINDOW_WIDTH / 2 - CHARACTER_WIDTH && !collideLeft (floor) && !collideRight (floor))	//if character is in the center of the screen 
	{
	  bgX1 -= HSPEED;	//scroll background
	  bgX2 -= HSPEED;
	}
      speed += HSPEED;		//increment speed
    }
  //check if left arrow hit
  else if (lWalk == true && rWalk == false && xpos >= HSPEED)
    {
      speed -= HSPEED;		//decrement speed
    }
  //no keys hit or both hit, speed is 0
  else
    speed = 0;

  //if shift and direction are pressed sprint in that direction
  if (sprint == true)
    {
      if (rWalk == true)
	{
	  if (xOffset == WINDOW_WIDTH / 2 - CHARACTER_WIDTH && !collideLeft (floor) && !collideRight (floor))	//sets background to scroll if character is in center of screen
	    {
	      bgX1 -= HSPRINT;
	      bgX2 -= HSPRINT;
	    }
	  speed += HSPRINT;
	}
      else if (lWalk == true && xpos >= HSPEED + HSPRINT)
	{
	  speed -= HSPRINT;
	}
    }


  if (!collideRight (floor) && !collideLeft (floor))
    {

      //speed adjusts x position
      xOffset += speed;

      //checks for collision with "walls" of the left and right side of window and does not allow animation to continue past these boundaries, player will stop as if walls are final point
      if (xOffset <= 0)		//if character is against left border of screen
	{
	  xOffset = 0;
	  xpos = xpos;
	}
      else if (xOffset > WINDOW_WIDTH / 2 - CHARACTER_WIDTH)	//if character is against middle of the screen
	{
	  xpos += speed;
	  score += (double) speed / 50;
	  xOffset = WINDOW_WIDTH / 2 - CHARACTER_WIDTH;
	  center = xpos + WINDOW_WIDTH / 2 - xOffset + CHARACTER_WIDTH;
	}
      else
	{
	  xpos += speed;
	}
    }
  //Uint8 *keystate = SDL_GetKeyState (NULL);

  // Adjust the center of the screen to the correct specs (based off of the movement of the player)
  if (!collideBottom (floor) || isJump)	//sets jumping motion
    {
      collideRight (floor);	//checks if colliding right
      collideLeft (floor);	//and left
      if (!topCollide (floor) && isJump && time <= 4)	//if player is not colliding above, jumping motion is true, and he has been jumping for time<=4
	{
	  jumpOffset = 40;	//keep upward motion
	}
      else
	{
	  jumpOffset = -40;	//downward motion
	  isJump = false;	//isJump should be false
	}
      time++;			//increment time to progress jumping motion
      yOffset -= jumpOffset;	//change y offset on screen
      topCollide (floor);	//checks if top collide 
      collideBottom (floor);	//checks if bottom collide
    }
  else
    {
      time = 0;			//set time to 0 if not jumping and on ground
    }
    collideRight(floor);
    collideLeft(floor);
}


/*
CHECKING AGAINST A BLOCK
xpos/50 is location of lep in terms of the block size
therefore, iterating through the locations (1, 2, ... )
*/
int
player::topCollide (block & floor)
{

  /*
     find the y positions of a block on the bottom
     check all the x positions of the block on that y position
   */

  for (int i = 0; i < floor.getSize (xpos / 50); i++)	//increments through all blocks at certain x position
    {
      if (yOffset <= floor.getCurrentY (xpos / 50, i) + 50 && yOffset > floor.getCurrentY (xpos / 50, i))	//if top intersecting with a block
	{
	  yOffset = floor.getCurrentY (xpos / 50, i) + 50;	//set y offset to bottom
	  return 1;
	}
    }


  if (xpos / 50 != (xpos + CHARACTER_WIDTH) / 50)	//checks if player is standing on more than one block
    {
      for (int i = 0; i < floor.getSize (xpos / 50 + 1); i++)	//increments through all blocks at right x
	{
	  if (yOffset <= floor.getCurrentY (xpos / 50 + 1, i) + 50 && yOffset > floor.getCurrentY (xpos / 50 + 1, i))	//if top intersecting with a block
	    {
	      yOffset = floor.getCurrentY (xpos / 50 + 1, i) + 50;	//set y offset to bottom
	      return 1;
	    }

	}
    }
  return 0;
}


// returns the center of the screen
int
player::getCenter ()
{

  return center;
}


/*
Checks when lep collides with object block from the right
Checks if lep is walking right, and if the lep's xpos (position on the screen, relative to beginning) plus it's width minus the block's x position (relative to lep's position)	
*/
int
player::collideRight (block & floor)
{

  if (rWalk==true && floor.getX (xpos / 50 + 1) - (xpos + CHARACTER_WIDTH) < speed)	//if right side of player is within a certain range of a block
    {
      for (int j = yOffset; j <= yOffset + CHARACTER_HEIGHT; j += 1)	//increment pixels in height
	{
	  for (int i = 0; i < floor.getSize (xpos / 50 + 1); i++)	//check all blocks in the y block array for certain x value
	    {
	      if (j > floor.getCurrentY (xpos / 50 + 1, i) && j < floor.getCurrentY (xpos / 50 + 1, i) + 50)	//checks if pixel is in range of the block
		{
		  xpos = floor.getX (xpos / 50 + 1) - CHARACTER_WIDTH -1;	//resets x position behind the block
		  xOffset = floor.getBlockX (xpos / 50 + 1, center) - CHARACTER_WIDTH -1;	//sets offset to behind block
		  bgX1 = bgX1;	//stops screen scrolling
		  bgX2 = bgX2;
		  return 1;
		}
	    }
	}
    }

  return 0;
}


/*
Checks when lep collides with object block from the right
Checks if lep is walking right, and if the lep's xpos (position on the screen, relative to beginning) plus it's width minus the block's x position (relative to lep's position)	
*/
int
player::collideLeft (block & floor)
{

  if (lWalk==true && xpos - floor.getX (xpos / 50) < -speed)	//checks if left side is within certain range of block
    {
      for (int j = yOffset; j <= yOffset + CHARACTER_HEIGHT; j += 1)	//increments through pixels in height
	{
	  for (int i = 0; i < floor.getSize (xpos / 50 - 1); i++)	//runs through blocks for certain x value
	    {
	      int blockY = floor.getCurrentY (xpos / 50 - 1, i);
	      if (j > floor.getCurrentY (xpos / 50 - 1, i)
		  && j < floor.getCurrentY (xpos / 50 - 1, i) + 50)
		{		//checks if any pixels are between the block top and bottom
		  xpos = floor.getX (xpos / 50);	//sets xpos left of block
		  xOffset = floor.getBlockX (xpos / 50, center);	//sets x offset to left of block                 
		  return 1;
		}
	    }
	}
    }

  return 0;
}


//updates the screen to show player position and movement: based on URL above
SDL_Surface *
player::update (block & floor, ifstream & infile)
{

  //check to see what the current speed is
  //speed less than 0, player heading left
  if (speed < 0)
    {
      //player set to facing left
      status = GOING_LEFT;

      //adjusts for looping the array
      currentFrame = ++currentFrame % 4;

      //animation continues to increment for movement
    }
  //speed greater than 0, player heading right
  else if (speed > 0)
    {
      //player is facing right
      status = GOING_RIGHT;

      //adjusts for looping the array, animation continues going
      currentFrame = ++currentFrame % 4;
    }
  //speed is 0. player not moving, will not change the way it is facing, animation stops at the first frame of the sprite sheet for respective directions
  else
    {
      currentFrame = 0;
    }

  //blit image of player to screen given the offsets and the clip of the sprite sheets
  if (status == GOING_RIGHT)	//if player facing right
    {
      // If the background has gone too far to the left, reset the offset
      if (bgX1 <= -background->w)
	{
	  // Reset the offset
	  bgX1 = background->w;
	  bgX2 = 0;
	}
      // background gone too far to right, reset the offset
      if (bgX2 <= -background->w)
	{
	  bgX1=0;
	  bgX2 = background->w;
	}

      apply_image (background, window, 0, bgX1, 0);
      apply_image (background, window, 0, bgX2, 0);
      apply_image (characterImage, window, &frameRight[currentFrame], xOffset,
		   yOffset);
      floor.display (window, center, infile);

      //delays update time between loop iterations to make animation more visible
      //apply right facing image to background
    }
  else if (status == GOING_LEFT)	//if player facing left
    {
      apply_image (background, window, 0, bgX1, 0);
      apply_image (background, window, 0, bgX2, 0);

      //apply left facing image to background
      apply_image (characterImage, window, &frameLeft[currentFrame], xOffset,
		   yOffset);

      //delays update time between loop iterations to make animation more visible
      floor.display (window, center, infile);
    }

  //resets speed for next loop
  speed = 0;
  return window;
}


//get y offset of player
int
player::getyOffset ()
{

  return yOffset;
}

//get x offset of player
int
player::getxOffset ()
{

  return xOffset;
}


//get x position of player
int
player::getxpos ()
{

  return xpos;
}

//get player score
double
player::getScore ()
{
  return score;
}

//sets score value to increment the player's score
void
player::setScore (double newScore)
{
  score = newScore;
}


/*
CHECKING COLLISIONS AGAINST AN ENEMY
xpos/50 is location of lep in terms of the block size
therefore, iterating through the locations (1, 2, ... )
*/
int
player::enemyCollisionSide (int enemyxpos, int enemyypos, int height, int width)
{

  /*
     Check for right side collision 
   */
  if (xpos + CHARACTER_WIDTH - enemyxpos >= 0 && enemyxpos > xpos)	//if character intersects with the enemy
    {
      for (int j = yOffset; j <= yOffset + CHARACTER_HEIGHT; j += 1)	//check if any portion is within height of enemy
	{
	  if (j < height + enemyypos && j > enemyypos)
	    {
	      return 1;
	    }
	}
    }
  /*
     Check for left side collision
   */
  else if (enemyxpos + width - xpos >= 0 && xpos > enemyxpos)	//if character intersects with the enemy
    {
      for (int j = yOffset; j <= yOffset + CHARACTER_HEIGHT; j += 1)	//checks if any portion is within height of enemy
	{
	  if (j < height + enemyypos && j > enemyypos)
	    {
	      return 1;
	    }
	}
    }

  return 0;
}


/*
CHECKING COLLISIONS AGAINST AN ENEMY TO SEE IF IT WAS A KILL
xpos/50 is location of lep in terms of the block size
therefore, iterating through the locations (1, 2, ... )
*/
int
player::enemyKill (int enemyxpos, int enemyypos, int width)	//function for killing enemies
{

  if (enemyypos - (yOffset + CHARACTER_HEIGHT) <= 0 && yOffset < enemyypos && jumpOffset < 0)	//checks if player is intersecting with enemy from top
    {
      for (int i = xpos; i < xpos + CHARACTER_WIDTH; i++)	//checks all values in player width
	{
	  for (int j = enemyxpos; j < enemyxpos + width; j++)	//checks all values of enemy width
	    {
	      if (i == j)	//if any values are equal
		{
		  isJump = true;	//bounce after kill
		  time = 3;
		  return 1;
		}
	    }
	}
    }

  return 0;
}

void
player::deathAnimation (block & floor, ifstream & infile,
			SDL_Surface * window, vector < enemy * >&enemies)
{
  int t = 0;			// Keeps track of time for the animation
  //yOffset+=100;
  while (yOffset < WINDOW_HEIGHT)
    {
      if (t <= 2)
	yOffset -= 20;
      else
	yOffset += 5 * t;
      if (status == GOING_RIGHT)	//if player facing right
	{
	  // If the background has gone too far to the left, reset the offset
	  if (bgX1 <= -background->w)
	    {
	      // Reset the offset
	      bgX1 = background->w;
	      bgX2 = 0;
	    }
	  // background gone too far to right, reset the offset
	  if (bgX2 <= -background->w)
	    {
	      bgX1 = 0;
	      bgX2 = background->w;
	    }

	  apply_image (background, window, 0, bgX1, 0);
	  apply_image (background, window, 0, bgX2, 0);
	  floor.display (window, center, infile);
	  apply_image (characterImage, window, &frameRight[currentFrame],
		       xOffset, yOffset);

	  //delays update time between loop iterations to make animation more visible
	  //apply right facing image to background
	}
      else if (status == GOING_LEFT)	//if player facing left
	{
	  apply_image (background, window, 0, bgX1, 0);
	  apply_image (background, window, 0, bgX2, 0);

	  //delays update time between loop iterations to make animation more visible
	  floor.display (window, center, infile);
//apply left facing image to background
	  apply_image (characterImage, window, &frameLeft[currentFrame],
		       xOffset, yOffset);


	}
      for (int i = 0; i < enemies.size (); i++)
	{
	  // Move the ith enemy with respect ot the leprechaun's movement/position and the landscape
	  //enemies[i]->move (getxOffset (), getxpos (), floor);

	  // Update the screen
	  window = enemies[i]->update (window);
	}
	  SDLSingleton::GetInstance()->DoRender();
      SDL_Delay (50);
      t++;
    }
}


/* checks if player reaches end of the level, returns value for determination, animates ending of level where player jumps on the flagpole*/
int
player::endLevel (int length, block & floor, SDL_Surface * window,
		  ifstream & infile)
{
  if (xpos + CHARACTER_WIDTH >= length)
    {
      xpos = xpos;
      xOffset = xOffset;
      for (yOffset; yOffset < WINDOW_HEIGHT - 50 - CHARACTER_HEIGHT;
	   yOffset+=3)
	{

	  // If the background has gone too far to the left, reset the offset
	  if (bgX1 <= -background->w)
	    {
	      // Reset the offset
	      bgX1 = background->w;
	      bgX2 = 0;
	    }
	  // background gone too far to right, reset the offset
	  if (bgX2 <= -background->w)
	    {
	      bgX1 = 0;
	      bgX2 = background->w;
	    }
	  SDL_Surface *flag = load ("flag.png");
	  apply_image (background, window, 0, bgX1, 0);
	  apply_image (background, window, 0, bgX2, 0);
	  apply_image (characterImage, window, &frameRight[currentFrame],
		       xOffset, yOffset);
	  floor.display (window, center, infile);
	  apply_image (flag, window, NULL,
		       getxOffset () + (length - getxpos ()),
		       WINDOW_HEIGHT - flag->h);
	  //delays update time between loop iterations to make animation more visible
	  //apply right facing image to background
	  
	  SDLSingleton::GetInstance()->DoRender();
	  SDL_Delay (50);

	}
      return 1;
    }
  return 0;
}
