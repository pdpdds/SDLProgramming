/*eagle.h
The class representing the Boston College eagle enemy in the game. Inherits from the enemy class.
The eagle bounces through the levels, turning around when it hits the edge of a block.
Programmers:
	Scott Grimes
*/

#ifndef EAGLE_H
#define EAGLE_H

#include"mSDL.h"
#include"block.h"
#include "enemy.h"
#include "character.h"
#include<iostream>
#include<string>

class eagle: public enemy {

	public:
		eagle (string, int, int, int); // Constructor
		void move (int templepxOffset, int templepxpos, block & floor); // The eagle's move function
		int topCollide ( block & ); // The eagle's top collision function

	private:
		int jumpTime; // Time variable used for determining whether the eagle is moving up or down while he is jumping
};

#endif
