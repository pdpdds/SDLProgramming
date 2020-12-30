/* mSDL.h

Programmer: Mike Duggan

-Header file for mSDL library, a library that contains functions that will be 
	used in the project using the SDL library that are universal for each 
	aspect of the project
-based on functions from the following URL: http://lazyfoo.net/SDL_tutorials/lesson02/index.php


Functions:

SDL_Surface * openWindow(string, int, int, int);
	-initializes all SDL libraries, creates an SDL window surface and creates a caption for it
	-also takes the screen height width and bits per pixel as arguments from the main function
	-returns pointer to the new window surface pointer

SDL_Surface * load(string); 
	-loads images and optimizes them to the display window, takes the filename of the
		image as the only argument and outputs a pointer to the SDL_Surface of the 

void apply_image(SDL_Surface *image, SDL_Surface *currentWindow, SDL_Rect * clip, int xpos, int ypos);
	-adds an image to the window and updates it
	-uses SDL_Surface *, SDL_Rect * and integers to take in the window surface, the image surface, the image offset (clip), and the desired coordinates for the image and updates the SDL window using SDL_Flip after blitting the image and the window surface at the proper coordinates

*/

#ifndef MSDL_H
#define MSDL_H

#include "SDL2/SDL.h"		//sdl base library
#include "SDL2/SDL_image.h"	//sdl library to deal with functions
#include "SDL2/SDL_ttf.h"		//sdl library to deal with text on the screen
//#include"SDL/SDL_mixer.h"
#include<string>		//stl library to allow for use of strings
using namespace std;



	/*
	initializes SDL, opens window 
	*/
	SDL_Surface *openWindow (string windowCaption = "Default Caption", int windowWidth = 640, int windowHeight = 480, int bpp = 32);


	/*
	loads and optimizes an image file
	LOADS SPRITE SHEETS WITH 255,0,255 (MAGENTA) BACKGROUNDS
	*/
	SDL_Surface *load (string imageName);


	/*
	DOES NOT ACCOUNT FOR MAGENTA TRANSPARENCY
	*/
	SDL_Surface *loadBackground (string imageName);

	/*
	puts image on another SDL_Surface (the window) and updates the window so it shows the current position of the image
	*/
	void apply_image (SDL_Surface * image, SDL_Surface * currentWindow, SDL_Rect * clip, int xpos, int ypos);



#endif
