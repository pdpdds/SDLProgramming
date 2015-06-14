/* 
File:
	player.h
Description:
	Contains interface for the player class: the figure that the user of the program will control
	NOTE: strategy for implementation of this class comes from the following URL: http://lazyfoo.net/SDL_tutorials/lesson20/index.php
	Contains functions that allow the user to input using keys from the main program and manipulate the player image on the main window screen called from the main function
Progammers:
	Scott Grimes
	Mike Duggan
	Vinny Birch
	Keven Sonnen
*/


#ifndef PLAYER_H
#define PLAYER_H

#include"SDL_image.h"
#include<string>
#include"character.h"
#include "block.h"
#include "enemy.h"
using namespace std;


class player:public character
{

public:
  //constructor for player objects
  player (string = "lep.png", string = "background.png", int = 1024, int =
	  768, SDL_Surface * = NULL);
  //deconstructor: deletes SDL_Surfaces created
   ~player ();

  // Member functions
  void move (block &);		//moves offsets of the character to reflect current position on window
  SDL_Surface *update (block &, ifstream & infile);	//updates the SDL screen to reflect current position of the figure
  int keyInput (block &);	//takes user input using keystates instead of events (used instead of input)
  int getCenter ();		//returns position of the senter of screen
  int collideRight (block &);	//collide right with block
  int collideLeft (block &);	//collide left with block
  int topCollide (block &);	//collide top with blocks
  int getyOffset ();		//gets yoffset of the player
  int getxOffset ();		//gets xoffset of the player
  int getxpos ();		//gets x position of the player
  int enemyCollisionSide (int enemyxpos, int enemyypos, int height, int width);	//collision with enemies on right and left
  int enemyKill (int enemyxpos, int enemyypos, int width);	//kills enemies
  void deathAnimation (block &, ifstream & infile, SDL_Surface *, vector < enemy * >&);	// Animates the player when he's killed
  double getScore ();		//gets player score
  void setScore (double);	//sets value to get added to score
  int endLevel (int, block &, SDL_Surface *, ifstream &);	//determines if level is ended and animates it
private:

    bool sprint;		//bool value for whether shift is down or up
  int bgX1;			//int for the horizontal offset of the background
  int bgX2;			//int for offset of second background image
  int center;			//x position of the center of the screen
  int status;			//determines whether player image is facing left or right (for frame clips)
  SDL_Surface *background;	//background image

  // Movement of player
  void setFrames ();		//sets clips on sprite sheet lep.png for use in animation (goes from frame to frame)
  bool isJump;			//bool for jumping motion
  int time;			//counter for animation of jumping
  double score;			// Keeps track of the player's score
};

#endif
