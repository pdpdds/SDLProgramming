/* 
File:
	mSDL.c
Description:
	Contains the implementation for the functions of mSDL.h library
	As noted in the mSDL.h comments, the implementation is based off of functions that were made on 
	this website: http://lazyfoo.net/SDL_tutorials/lesson02/index.php
Programmer: 
	Mike Duggan
*/

#include"mSDL.h"
#include "SDLSingleton.h"


//creates window surface: default values defined in mSDL.h file
SDL_Surface * openWindow (string windowCaption, int windowWidth, int windowHeight, int bpp) {

	if (false == SDLSingleton::GetInstance()->InitSystem())
		return NULL;

	return SDLSingleton::GetInstance()->GetSurface();
}


//loads .png files, optimizes them, color keys them and outputs them to the main function in an SDL_Surface * pointer
SDL_Surface * load (string imageName) {
	
	if(imageName.empty())
		return NULL;

	//loads image based on filename
	SDL_Surface *tempImage = IMG_Load (imageName.c_str ());

	//optimizes image based on window settings
	SDL_Surface *optimizeImage = SDL_ConvertSurfaceFormat(tempImage, SDL_PIXELFORMAT_RGBA8888,0);

	//color keys window so that it's outline doesnt show on the background
	SDL_SetColorKey(optimizeImage, SDL_TRUE, SDL_MapRGB(optimizeImage->format, 255, 0, 255));

	//frees original unoptimized image
	SDL_FreeSurface (tempImage);

	//returns image pointer
	return optimizeImage;
}


SDL_Surface * loadBackground (string imageName) {

	if(imageName.empty())
		return NULL;

	//loads image based on filename
	SDL_Surface *tempImage = IMG_Load (imageName.c_str ());

	//optimizes image based on window settings
	SDL_Surface *optimizeImage = SDL_ConvertSurfaceFormat(tempImage, SDL_PIXELFORMAT_RGBA8888, 0);

	//frees original unoptimized image
	SDL_FreeSurface (tempImage);

	//returns image pointer
	return optimizeImage;
}


//puts an image on the surface of the window based on the offset from the origin of the window and where the image is clipped relative to the sprite sheet
void apply_image (SDL_Surface * image, SDL_Surface * currentWindow, SDL_Rect * clip, int xpos, int ypos) {

	SDL_Rect offset;	//set window offsets
	offset.x = xpos;
	offset.y = ypos;

	// makes the window background plain white (no image at this point)
	// adds image to the window surface
	SDL_BlitSurface (image, clip, currentWindow, &offset);


	//updates the window so that current image and position is displayed
 	//SDL_Flip (currentWindow);
}






