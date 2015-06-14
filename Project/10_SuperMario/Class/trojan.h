/*
File:
	trojan.h
Description:
	Interface for trojan class
Programmers:
	Kevin Sonnen
	Vinny Birch
	Mike Duggan
	Scott Grimes
*/


#ifndef TROJAN_H
#define TROJAN_H

#include"mSDL.h"
#include"block.h"
#include "enemy.h"
#include "character.h"
#include<iostream>
#include<string>

class trojan:public enemy
{

public:
  trojan (string, int, int, int);	//constructor for a trojan (inherits from enemy)
};

#endif
