/*
File: 
	button.h
Description:
	contains interface for button class
Programmer:
	Mike Duggan
*/

#ifndef BUTTON_H
#define BUTTON_H

#include"mSDL.h"
#include<iostream>
#include<string>
using namespace std;

class button
{

public:
  button (string, int, int); //constructor, takes image filename, and the locations of the image
   ~button (); //deconstructor
  void apply_button (SDL_Surface *); //draws button on the given window
  bool isClicked (int, int); //checks if mouse has clicked within the range of the image


private:

    SDL_Rect buttonInfo;	//contains x, y positions as well as width of image
  SDL_Surface *buttonImage;	//image for button



};

#endif
