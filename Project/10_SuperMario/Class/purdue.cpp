/*
File:
	purdue.cpp
Desciption:
	.cpp file for the purdue enemy
Progammer:
	Scott Grimes
*/

#include"mSDL.h"
#include"block.h"
#include "enemy.h"
#include "purdue.h"
#include "character.h"
#include<iostream>
#include<string>

const int EN_WIDTH = 320 / 4;
const int EN_HEIGHT = 50;
const int GOING_RIGHT = 0;	// a constant that shows whether the image should be facing right relative to the user
const int GOING_LEFT = 1;	// constant that shows whether the EN is facing left relative to the user
const int HSPEED = EN_WIDTH / 5;	// constant for the average run value

// =================================== Constructor =====================================
purdue::purdue (string filename, int windowWidth, int windowHeight, int x):
enemy (filename, windowWidth, windowHeight, x, EN_HEIGHT, EN_WIDTH, HSPEED)
{				//purdue train constructor

  rWalk = true;
  lWalk = false;
  yOffset = 385;
  setFrames ();
  setScore (50);
}

/*
Moves the enemy based off of a coordinate of the leprechaun and block he is touching
*/
void
purdue::move (int templepxOffset, int templepxpos, block & floor)
{


  speed = -HSPEED;		//set speed
  xpos += speed;		//increase train x position
  xOffset = templepxOffset + (xpos - templepxpos);	//set screen offset

}
