//
//  Background.h
//  Arkanoid
//
//  Created by Maciej Żurad on 11/26/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#ifndef __Arkanoid__Background__
#define __Arkanoid__Background__

#include <iostream>
#include <SDL2/SDL.h>
#include "scaler.h"
#include "Game.h"

class Background {

private:
    float x;
    float y;
    int width;
    int height;
    SDL_Surface* image;
    SDL_Rect* clip;
    
public:
    
    Background(const char* filename, int width, int height);
    ~Background();
    void RenderBackground();
    void UpdateBackground(float x, float y);
    void InitBackground();
    
};

#endif /* defined(__Arkanoid__Background__) */
