/*
File:
	purdue.h
Desciption:
	.h file for the purdue enemy
Progammer:
	Scott Grimes
*/


#ifndef PURDUE_H
#define PURDUE_H

#include"mSDL.h"
#include"block.h"
#include "enemy.h"
#include "character.h"
#include<iostream>
#include<string>

class purdue:public enemy
{

public:
  purdue (string, int, int, int);	//constructor
  void move (int templepxOffset, int templepxpos, block & floor);	//move function

};

#endif
