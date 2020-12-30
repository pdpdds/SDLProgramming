//
//  Gui.h
//  Arkanoid
//
//  Created by Maciej Żurad on 11/27/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#ifndef __Arkanoid__Gui__
#define __Arkanoid__Gui__

#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"

class Gui {
    
private:
    
    SDL_Color color;
    
    int x;
    int y;

    int score;
    int lives;
    
    SDL_Surface* score_msg;
    SDL_Surface* lives_msg;
    TTF_Font* font;
    
public:
    Gui();
    ~Gui();

    void Init(int x, int y);
    void Render();
    void Update();
    
};

#endif /* defined(__Arkanoid__Gui__) */
