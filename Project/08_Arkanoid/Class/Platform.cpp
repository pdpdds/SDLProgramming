//
//  Platform.cpp
//  Arkanoid
//
//  Created by Maciej Żurad on 11/18/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#include "Platform.h"


Platform::Platform(const char* filename, int maxFrame, int frameDelay, int frameWidth,
           int frameHeight, int animationColumns, int animationDirection )
            : GameObject(filename, maxFrame, frameDelay, frameWidth, frameHeight, animationColumns, animationDirection), has_effect(-1)
{
    //setting ID to PLAYER and calling superclass constructor
    SetID(PLAYER);
}

void Platform::Destroy(){
    //calling superclass destructor
    GameObject::Destroy();
}

void Platform::Init() {
    
    // Initializing ball
    GameObject::Init(g_Game.GetScreen_W()/2.0, g_Game.GetScreen_H() - 10 , 15, 0, 0, 0, animation->GetFrameWidth()/2, animation->GetFrameHeight()/2);
    
    SetAlive(true);
    
    lives = 5;
    score = 0;
    
}

int Platform::Update(float fElapsedTime){
    if(isAlive()){
		GameObject::Update(fElapsedTime);
        //Performing boundry checking
        if( x > g_Game.GetScreen_W() - boundX)
            x = g_Game.GetScreen_W() - boundX;
        else if ( x < boundX)
            x = boundX ;
        //Updating of animation exists
        if(animation) animation->Animate();
    }
    
    if(!GetLives()){
        PlayingState* playing_state = dynamic_cast<PlayingState*>(g_GamePtr->GetState());
        playing_state->SetChangingStateFlag(true);
        playing_state->PushScore(getenv("USER"), GetScore());
    }
    return 0;
}
void Platform::Render(){
    if(isAlive()){
        GameObject::Render();
        //Rendering if animation exists
        if(animation) animation->Draw(x-boundX, y-boundY);
    }
}

void Platform::MoveLeft(){
    dirX = -1;
}
void Platform::MoveRight(){
    dirX = 1;
}

void Platform::StopMoving(){
    dirX = 0;
}


void Platform::Collided( int objectID, col_dir dir){
    if(dir == NO_COLLISION)
        return;
    
    if(objectID == BALL){
        if(!(has_effect == MAGNET))                       // if platform is under effect of Magnet then we dont want to add points constantly
            AddPoint();

    }
}

void Platform::Shoot(){
    if(has_effect == GUN){
        Projectile** projectiles_temp = dynamic_cast<PlayingState*>(g_GamePtr->GetState())->GetProjectiles();
        for(int i=0; i<3; i++)
            if(!projectiles_temp[i]->isAlive()){
                projectiles_temp[i]->Init(x, y, 3);
                return;
            }
    }
}

void Platform::MorphPlatform(int effect_type) {
    has_effect = effect_type;
    animation->SetFrame(effect_type+1);
}
