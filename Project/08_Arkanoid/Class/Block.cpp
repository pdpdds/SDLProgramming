
//
//  Block.cpp
//  Arkanoid
//
//  Created by Maciej Żurad on 11/18/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#include "Block.h"


Block::Block(const char* filename, int maxFrame, int frameDelay, int frameWidth,
                   int frameHeight, int animationColumns, int animationDirection )
: GameObject(filename, maxFrame, frameDelay, frameWidth, frameHeight, animationColumns, animationDirection), health(0), maxhealth(0)
{
    //setting ID to PLAYER and calling superclass constructor
    SetID(BLOCK);
}


Block::Block(SDL_Surface* image, int maxFrame, int frameDelay, int frameWidth,
             int frameHeight, int animationColumns, int animationDirection)
: GameObject(image, maxFrame, frameDelay, frameWidth, frameHeight, animationColumns, animationDirection), health(0), maxhealth(0)
{
    //setting ID to PLAYER and calling superclass constructor
    SetID(BLOCK);
}

void Block::Destroy(){
    //calling superclass destructor
    GameObject::Destroy();
}

void Block::Init(float x, float y, int speed, int dirX, int health){
    
    // Initializing block
    GameObject::Init(x, y , speed, 0, dirX, 0, animation->GetFrameWidth()/2, animation->GetFrameHeight()/2);
    
    SetAlive(true);
    Block::health = health;
    Block::maxhealth = health;

}

int Block::Update(float fElapsedTime){
    if(isAlive()){
		GameObject::Update(fElapsedTime);
        //Performing boundry checking
        if( x > g_Game.GetScreen_W() - boundX || x < boundX)
            dirX *= -1;
        //Updating of animation exists
        if(animation) animation->Animate();
    }
    return 0;
}
void Block::Render(){
    if(isAlive()){
        GameObject::Render();
        //Rendering if animation exists
        if(animation) animation->Draw(x-boundX, y-boundY);
    }
}


void Block::Collided( int objectID, col_dir dir)
{
    if(dir == NO_COLLISION)
        return;
    
    if(objectID == BALL || objectID == PROJECTILE){
        if(!--health){
            Effect** effs = dynamic_cast<PlayingState*>(g_GamePtr->GetState())->GetEffects();
            if(rand()%2){
                int index = rand()%3;
                if (!effs[index]->isAlive())
                    effs[index]->Init(x, y);
            }
            SetAlive(false);
        }else if (animation->IsAutoAnimation())
            animation->SetFrame(maxhealth - health);
        
        
    } else if (objectID == BLOCK ){
        if(dir == LEFT)
            dirX = -1;
        else if (dir == RIGHT)
            dirX = 1;
    }
    
}