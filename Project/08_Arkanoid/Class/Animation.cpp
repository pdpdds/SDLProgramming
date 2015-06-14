//
//  Animation.cpp
//  Arkanoid
//
//  Created by Maciej Żurad on 11/22/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#include "Animation.h"
#include "Game.h"



Animation::Animation(const char* filename, int maxFrame, int frameDelay, int frameWidth, int frameHeight, int animationColumns, int animationDirection ){
    
    //Animation's properties initialization
    Animation::curFrame = 0;
    Animation::frameCount = 0;
    Animation::maxFrame = maxFrame;
    Animation::frameDelay = frameDelay;
    Animation::animationColumns = animationColumns;
    Animation::animationDirection = animationDirection;
 
    // Forumula for calculating new frame sizes according to current window size
    Animation::frameWidth = g_Game.GetScreen_W() / (float)BASE_SCREEN_X * frameWidth;
    Animation::frameHeight = g_Game.GetScreen_H() / (float)BASE_SCREEN_Y * frameHeight;
   
    // formjula for checking if the last row is full in spritesheet if so then we have to adjust height of a loading image
    int loading_image_w = Animation::frameWidth*animationColumns;
    int loading_image_h;
    if( (maxFrame+1)%animationColumns )
        loading_image_h = Animation::frameHeight*((maxFrame+1)/animationColumns+1);
    else
        loading_image_h = Animation::frameHeight*(((maxFrame+1)/animationColumns));
    
    //loading image to SDL_Surface* with new width and height
    image = LoadScaledBitmap(filename, loading_image_w, loading_image_h);
   
    if(image){
        clip = new SDL_Rect();
        clip->x = 0;
        clip->y = 0;
        clip->w = Animation::frameWidth;
        clip->h = Animation::frameHeight;
    }
}

Animation::Animation(SDL_Surface* image, int maxFrame, int frameDelay, int frameWidth, int frameHeight, int animationColumns, int animationDirection ){

    Animation::curFrame = 0;
    Animation::frameCount = 0;
    Animation::maxFrame = maxFrame;
    Animation::frameDelay = frameDelay;
    Animation::animationColumns = animationColumns;
    Animation::animationDirection = animationDirection;
    
    Animation::frameWidth = g_Game.GetScreen_W() / (float)BASE_SCREEN_X * frameWidth;
    Animation::frameHeight = g_Game.GetScreen_H() / (float)BASE_SCREEN_Y * frameHeight;
    
    Animation::image = image;
    
    if(image){
        clip = new SDL_Rect();
        clip->x = 0;
        clip->y = 0;
        clip->w = Animation::frameWidth;
        clip->h = Animation::frameHeight;
    }
}

Animation::~Animation(){
    if(image){
        delete clip;
    }
}

void Animation::Animate(){
    if(++frameCount > frameDelay){
        curFrame += animationDirection;
        
        if(curFrame > maxFrame){
            curFrame = 0;
        }
        if(curFrame < 0 ){
            curFrame = maxFrame;
        }
        frameCount = 0;
        
        clip->x = (curFrame % animationColumns) * clip->w;
        clip->y = (curFrame / animationColumns) * clip->h;
    }
}

void Animation::Draw(float x, float y) const {
    SDL_Rect offset = {(Sint16)x, (Sint16)y, 0, 0};
    SDL_BlitSurface(image, clip, g_Game.GetScreen(), &offset);
}

bool Animation::IsAutoAnimation(){                                                           // helper for blocks that have animation based on health
    if ( !animationDirection)
        return true ;
    else
        return false ;
};



