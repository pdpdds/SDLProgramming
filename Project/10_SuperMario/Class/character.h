/* 
File:
	character.h
Description:
	base class for every character in program
Programmers:
	Mike Duggan
	Kevin Sonnen
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include"mSDL.h"
#include"block.h"
#include<iostream>
#include<string>

using namespace std;

class character
{

public:
  character (string, SDL_Surface *, int, int, int, int);	//constructor
   ~character ();		//deconstructor

  int getxpos ();		//get xpos function: returns xpos
  virtual int collideBottom (block &);	//collide bottom: inherited by all classes
  bool isAlive;			// Keeps track of if the character is alive or not
  int getHeight();		//Returns character height
  int getWidth();		//Returns character width

protected:
    SDL_Surface * characterImage;	//pointer to the image of the character
  SDL_Surface *window;		//pointer to the window image
  SDL_Rect *frameLeft;		//pointer to the clip array
  SDL_Rect *frameRight;		//pointer to right clip array
  bool rWalk;			//shows whether character is facing right
  bool lWalk;			//shows whether character is facing left
  int speed;			//shows how fast in pixels character will move
  int xOffset;			//xposition of character relative to the screen
  int yOffset;			//yposition of character relative to the screen
  int currentFrame;		//shows what frame of the sprite sheet player is on
  int WINDOW_HEIGHT;		//constant for the window height
  int WINDOW_WIDTH;		//constant for the window width
  int xpos;			//xpostion relative to the entire player
  int jumpOffset;		//shows how much change in y offset has occurred
  int CHARACTER_HEIGHT;		//constant for height of character
  int CHARACTER_WIDTH;		//constant for width of character
};

#endif
