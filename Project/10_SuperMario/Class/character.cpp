/*
File:
	character.cpp
Description:
	contains implementation of code for base character class
Programmers:
	Mike Duggan
	Kevin Sonnen
*/

#include "character.h"

character::character (string character, SDL_Surface * screen, int windowWidth,
		      int windowHeight, int charHeight, int charWidth)
{				//constructor for character object

  characterImage = load (character);	//loads character image
  window = screen;		//sets window image
  //sets window and character constants
  WINDOW_WIDTH = windowWidth;
  WINDOW_HEIGHT = windowHeight;
  CHARACTER_WIDTH = charWidth;
  CHARACTER_HEIGHT = charHeight;
  isAlive = true;
}

character::~character ()
{				//deconstructor for character class

  SDL_FreeSurface (characterImage);
  SDL_FreeSurface (window);
  delete[]frameLeft;
  delete[]frameRight;
}



int
character::collideBottom (block & floor)
{				//checks for collision with blocks on the bottom of the character image
  if (isAlive)
    {
      for (int i = 0; i < floor.getSize (xpos / 50); i++)
	{
	  if (yOffset + CHARACTER_HEIGHT >= floor.getCurrentY (xpos / 50, i)
	      && yOffset + CHARACTER_HEIGHT < floor.getCurrentY (xpos / 50,
								 i) + 50)
	    {
	      yOffset = floor.getCurrentY (xpos / 50, i) - CHARACTER_HEIGHT;
	      return 1;
	    }

	}

      if (			//xpos != floor.getX (xpos / 50) + 1 &&
	   xpos / 50 != (xpos + CHARACTER_WIDTH) / 50)
	{
	  for (int i = 0; i < floor.getSize (xpos / 50 + 1); i++)
	    {
	      if (yOffset + CHARACTER_HEIGHT >=
		  floor.getCurrentY (xpos / 50 + 1, i)
		  && yOffset + CHARACTER_HEIGHT <
		  floor.getCurrentY (xpos / 50 + 1, i) + 50)
		{
		  //cout<<"BOTTOM "<<xpos+CHARACTER_WIDTH<<endl;
		  yOffset =
		    floor.getCurrentY (xpos / 50 + 1, i) - CHARACTER_HEIGHT;
		  return 1;
		}

	    }
	}
    }
  return 0;
}

int
character::getxpos ()
{				//returns the character's xpos

  return xpos;
}

int
character::getHeight(){
return CHARACTER_HEIGHT;
}

int character::getWidth(){
return CHARACTER_WIDTH;
}
