//
//  FpsCounter.cpp
//  Arkanoid
//
//  Created by Maciej Żurad on 11/18/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#include "FpsCounter.h"


int FpsCounter::measureFPS(){
    
    //Get current time
    int currentTime = SDL_GetTicks();
    
    
    //Measuring time
    if(currentTime - lastTime >= 1000){
        FPS = fps;
        fps = 0;
        lastTime = currentTime ;
    }
    
    if(currentTime - lastFrame >= frameDelay ){
        lastFrame = currentTime ;
        fps++;
        
        //next frame thus we return 1 for Renderer
        return 1;
    }
    //no frame in this measure, we dont return 1 for Renderer
    return 0;
}


int FpsCounter::getFPS(){
    return FPS;
}


// Too slow 
//void FpsCounter::RenderFPS(int x, int y){
//    SDL_Color col = {0xcc,0xcc,0xcc,0};
//    fps_message  = TTF_RenderText_Solid(g_GamePtr->GetMainFont(), IntToStr(FPS), col);
//    
//    Game::Draw(g_GamePtr->GetScreen(), fps_message, x, y);
//}

