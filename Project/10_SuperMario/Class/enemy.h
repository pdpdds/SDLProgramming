/* 
File:
	enemy.h
Description:
	contains interface of enemy class: a class derived from character and the base
	class for the three different types of enemies: trojan, purdue, eagle
Programmers:
	Scott Grimes
	Mike Duggan
	Vinny Birch
	Keven Sonnen
*/


#ifndef ENEMY_H
#define ENEMY_H

#include"mSDL.h"
#include"block.h"
#include "character.h"
#include<iostream>
#include<string>

class enemy:public character
{				//enemy constructor: inherits from character

public:
  enemy (string, int, int, int, int, int, int);	//constructor
  virtual SDL_Surface *update (SDL_Surface *);	//updates screen to new enemy position
  virtual void move (int, int, block &);	//moves enemy based on input and landscape
  virtual int collideRight (block &);	//checks for collide right
  virtual int collideLeft (block &);	//checks for collide left 
  virtual int getypos ();	//returns the y position of the enemy
  virtual int getxpos ();	//returns the x position of the enemy
  virtual void setFrames ();	//sets clipsfrom sprite sheet
  int getScore ();		//returns the score given for the specific enemy
  void setScore (int);		//sets the score for the specific

private:
  double HSPEED2;		//HSPEED temp variable
  int lepxOffset;		//the leprechaun (player's) x offset on screen
  int lepxpos;			//the leprechaun (player's) xpos on screen
  int score;			//score value
};

#endif
