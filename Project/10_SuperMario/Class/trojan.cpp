/* 
File:
	trojan.cpp
Description:
	Implementation of the trojan class
Programmer:
	Kevin Sonnen
	Vinny Birch
	Mike Duggan
	Scott Grimes
*/
#include"mSDL.h"
#include"block.h"
#include "enemy.h"
#include "trojan.h"
#include "character.h"
#include<iostream>
#include<string>

const int EN_WIDTH = 114 / 4;	//enemy width (based on sprite sheet dimension)
const int EN_HEIGHT = 45;	//enemy height (based on sprite sheet dimension)
const int GOING_RIGHT = 0;	// a constant that shows whether the image should be facing right relative to the user
const int GOING_LEFT = 1;	// constant that shows whether the EN is facing left relative to the user
const int HSPEED = EN_WIDTH / 10;	// constant for the average run value

// =================================== Constructor =====================================
trojan::trojan (string filename, int windowWidth, int windowHeight, int x):
enemy (filename, windowWidth, windowHeight, x, EN_HEIGHT, EN_WIDTH, HSPEED)
{				//trojan constructor
  setFrames ();			//sets frames for trojan
  setScore (15);		//sets the trojan's score
}
