//
//  Effect.cpp
//  Arkanoid
//
//  Created by Maciej Żurad on 11/25/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#include "Effect.h"

Effect::Effect(const char* filename, int maxFrame, int frameDelay, int frameWidth,
               int frameHeight, int animationColumns, int animationDirection )
                : GameObject(filename, maxFrame, frameDelay, frameWidth, frameHeight, animationColumns, animationDirection)
{
    SetID(EFFECT);
}


void Effect::Destroy(){
    GameObject::Destroy();
}



void Effect::Init(){}


void Effect::Init(int x, int y){
    GameObject::Init(x, y, 0, rand()%2+1, 0, 1, animation->GetFrameWidth()/2.0, animation->GetFrameHeight()/2.0);
    SetAlive(true);    
}

int Effect::Update(float fElapsedTime){
    if(isAlive()){
		GameObject::Update(fElapsedTime);
        if(animation) animation->Animate();
    }
    return 0;
}

void Effect::Render() {
    if(isAlive()){
        GameObject::Render();
        if(animation) animation->Draw(x-boundX, y-boundY);
    }
}

void Effect::Collided(int ObjectID, col_dir dir){
    
    if(dir == NO_COLLISION)
        return;
    
    if(ObjectID == PLAYER ){
        if( effect_type == MAGNET){
            PlayingState* ps = dynamic_cast<PlayingState*>(g_GamePtr->GetState());
            ps->GetPlatform()->MorphPlatform(effect_type);
            ps->GetBall()->MorphBall(effect_type);
            SetAlive(false);
        }else if ( effect_type == GUN ) {
            PlayingState* ps = dynamic_cast<PlayingState*>(g_GamePtr->GetState());
            ps->GetPlatform()->MorphPlatform(effect_type);
            SetAlive(false);

        }else if ( effect_type == SECONDBALL){
            dynamic_cast<PlayingState*>(g_GamePtr->GetState())->LaunchSecondBall();
            PlayingState* ps = dynamic_cast<PlayingState*>(g_GamePtr->GetState());
            ps->GetPlatform()->MorphPlatform(effect_type);
            SetAlive(false);
        }
    }
}