//
//  scaler.c
//  Arkanoid
//
//  Created by Maciej Żurad on 11/24/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#include "scaler.h"

using namespace std;

SDL_Surface* LoadScaledBitmap(const char* filename, int width, int height){
    
    // load image to temp file
    SDL_Surface *temp = IMG_Load(filename);
    if(!temp){
        cerr << "IMG_Load: " << IMG_GetError() << endl ;
        exit(1);
    }
    // apply alpha channel
   // SDL_Surface* temp2 = SDL_DisplayFormatAlpha(temp);
	SDL_SetSurfaceAlphaMod(temp, 255);

    //scale bitmap
    SDL_Surface* image = ScaleSurface(temp, width, height);
    
    // delete junk
    SDL_FreeSurface(temp);
    //SDL_FreeSurface(temp2);
    
    //returning pointer to scaled bitmap
    return image;
}



SDL_Surface *ScaleSurface(SDL_Surface *Surface, Uint16 Width, Uint16 Height)  // doesnt delete source bitmap, but we deal with it in LoadScaledBitmap
{
    // if source is null pointer or height/width is not specified then return NULL
    if(!Surface || !Width || !Height)
        return NULL;
    
    // create bitmap for a scaled bitmap
    SDL_Surface *_ret = SDL_CreateRGBSurface(Surface->flags, Width, Height, Surface->format->BitsPerPixel,
                                             Surface->format->Rmask, Surface->format->Gmask, Surface->format->Bmask, Surface->format->Amask);
    
    // calculate stretching factor for x  and y
    double _stretch_factor_x = (static_cast<double>(Width)  / static_cast<double>(Surface->w)),
    _stretch_factor_y = (static_cast<double>(Height) / static_cast<double>(Surface->h));
    
    
    // perform scaling for every pixel of source map
    for(Sint32 y = 0; y < Surface->h; y++)
        for(Sint32 x = 0; x < Surface->w; x++)
            for(Sint32 o_y = 0; o_y < _stretch_factor_y; ++o_y)
                for(Sint32 o_x = 0; o_x < _stretch_factor_x; ++o_x)
                    putpixel(_ret, static_cast<Sint32>(_stretch_factor_x * x) + o_x,
                             static_cast<Sint32>(_stretch_factor_y * y) + o_y, getpixel(Surface, x, y));
    
    //return scaled bitmap
    return _ret;
}


// Functions taken from SDL site
///////////////////////////////////////////////

Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
    
    switch(bpp) {
        case 1:
            return *p;
            break;
            
        case 2:
            return *(Uint16 *)p;
            break;
            
        case 3:
            if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
                return p[0] << 16 | p[1] << 8 | p[2];
            else
                return p[0] | p[1] << 8 | p[2] << 16;
            break;
            
        case 4:
            return *(Uint32 *)p;
            break;
            
        default:
            return 0;       /* shouldn't happen, but avoids warnings */
    }
}

void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
    
    switch(bpp) {
        case 1:
            *p = pixel;
            break;
            
        case 2:
            *(Uint16 *)p = pixel;
            break;
            
        case 3:
            if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
                p[0] = (pixel >> 16) & 0xff;
                p[1] = (pixel >> 8) & 0xff;
                p[2] = pixel & 0xff;
            } else {
                p[0] = pixel & 0xff;
                p[1] = (pixel >> 8) & 0xff;
                p[2] = (pixel >> 16) & 0xff;
            }
            break;
            
        case 4:
            *(Uint32 *)p = pixel;
            break;
    }
}