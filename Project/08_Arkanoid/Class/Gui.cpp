//
//  Gui.cpp
//  Arkanoid
//
//  Created by Maciej Żurad on 11/27/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#include "Gui.h"

Gui::Gui() : x(0), y(0), score(0),  lives(0), score_msg(NULL), lives_msg(NULL) {
    color = {0x0c, 0xac, 0xd0, 0};
    font = TTF_OpenFont("./data/font.ttf", 14);
    if(!font) {
        cerr << "Could not load font " << TTF_GetError << endl;
        exit(1);
    }
};

Gui::~Gui(){
    SDL_FreeSurface(score_msg);
    SDL_FreeSurface(lives_msg);
    if(!font) TTF_CloseFont(font);
}

void Gui::Init(int x, int y){
    Gui::x = x ;
    Gui::y = y ;
}
void Gui::Update(){
    Platform* platform = dynamic_cast<PlayingState*>(g_GamePtr->GetState())->GetPlatform();
    score = platform->GetScore();
    lives = platform->GetLives();
}
void Gui::Render(){

    score_msg = TTF_RenderText_Solid(font, ("Score: " + IntToStr(score)).c_str(), color);
    lives_msg = TTF_RenderText_Solid(font, ("Lives: " + IntToStr(lives)).c_str(), color);

    Game::Draw(g_GamePtr->GetScreen(), score_msg, x, y);
    Game::Draw(g_GamePtr->GetScreen(), lives_msg, x, y+score_msg->h);
    
    if(!score_msg) SDL_FreeSurface(score_msg);
    if(!lives_msg) SDL_FreeSurface(lives_msg);
}
