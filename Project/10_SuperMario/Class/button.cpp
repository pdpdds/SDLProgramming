/* 
File: 
	button.cpp
Description:
	contains implementation of button class
Programmer:
	Mike Duggan
*/

#include"button.h"
#include"mSDL.h"
#include<string>
#include<iostream>
using namespace std;

button::button (string filename, int x, int y)
{

  buttonImage = load (filename.c_str ());
  buttonInfo.x = x;
  buttonInfo.y = y;
  buttonInfo.w = buttonImage->w;
  buttonInfo.h = buttonImage->h;
}


button::~button () //deconstructor: frees the image 
{
  SDL_FreeSurface (buttonImage);
}


//draws button on window
void button::apply_button (SDL_Surface * window)
{
  apply_image (buttonImage, window, NULL, buttonInfo.x, buttonInfo.y);

}

//returns true or false as to whether last text file inputs are within the range of a button
bool button::isClicked (int mousex, int mousey)
{
  if (mousex > buttonInfo.x && mousex < buttonInfo.x + buttonInfo.w
      && mousey > buttonInfo.y && mousey < buttonInfo.y + buttonInfo.h)
    return true;

  else
    return false;

  return false;
}
