//
//  Projectile.cpp
//  Arkanoid
//
//  Created by Maciej Żurad on 11/25/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#include "Projectile.h"

Projectile::Projectile(const char* filename, int maxFrame, int frameDelay, int frameWidth,
               int frameHeight, int animationColumns, int animationDirection )
: GameObject(filename, maxFrame, frameDelay, frameWidth, frameHeight, animationColumns, animationDirection)
{
    SetID(PROJECTILE);
}


void Projectile::Destroy(){
    GameObject::Destroy();
}

void Projectile::Init(int x, int y, int velY){
    GameObject::Init(x, y, 0, velY, 0, -1, animation->GetFrameWidth()/2.0, animation->GetFrameHeight()/2.0);
    SetAlive(true);
}

int Projectile::Update(float fElapsedTime){
    if(isAlive()){
		GameObject::Update(fElapsedTime);
        if(animation) animation->Animate();
    }
    return 0;
}

void Projectile::Render() {
    if(isAlive()){
        GameObject::Render();
        if(animation) animation->Draw(x-boundX, y-boundY);
        
    }
}

void Projectile::Collided(int ObjectID, col_dir dir){
    if(dir == NO_COLLISION)
        return;
    
    if(ObjectID == BLOCK){
        SetAlive(false);
        dynamic_cast<PlayingState*>(g_GamePtr->GetState())->GetPlatform()->AddPoint();
    }
}