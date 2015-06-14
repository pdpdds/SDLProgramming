 //
//  Ball.cpp
//  Arkanoid
//
//  Created by Maciej Żurad on 11/21/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#include "Ball.h"

Ball::Ball(const char* filename, int maxFrame, int frameDelay, int frameWidth,
           int frameHeight, int animationColumns, int animationDirection )
            : GameObject(filename, maxFrame, frameDelay, frameWidth, frameHeight, animationColumns, animationDirection), has_effect(-1), stand_on_platform(false)
{
    //setting ID and calling superclass constructor
    SetID(BALL);
}

void Ball::Destroy(){
    // object destructor calling superclass destructor
    GameObject::Destroy();
}


void Ball::Init(){
    
    int posX = dynamic_cast<PlayingState*>(g_GamePtr->GetState())->GetPlatform()->GetX();
    int posY = dynamic_cast<PlayingState*>(g_GamePtr->GetState())->GetPlatform()->GetY();
    
    int t_dirX = (rand() % 2 +1)*2 -3 ; //  picking random direction either left or right
    GameObject::Init(posX, posY - animation->GetFrameHeight()/2, rand()%1 + 3,  rand()%1 +  3, t_dirX, -1, animation->GetFrameWidth()/2, animation->GetFrameHeight()/2);

}

void Ball::Render(){
    
    //if object is alive we draw it 
    if(isAlive()){
        GameObject::Render();
        
        //If there is an animation, we draw it so that the centre of it is at (x,y)
        if(animation) animation->Draw(x-boundX,y-boundY);
    }
}


int Ball::Update(float fElapsedTime){
    //if object is alive we update it 
    if(isAlive()){
        
        if(stand_on_platform){
            x = dynamic_cast<PlayingState*>(g_GamePtr->GetState())->GetPlatform()->GetX();
            y = dynamic_cast<PlayingState*>(g_GamePtr->GetState())->GetPlatform()->GetY()-15;
        }
        else{
			GameObject::Update(fElapsedTime);
            
            // we do a boundry checking
            if( x >= g_Game.GetScreen_W() -boundX || x<= boundX)
                dirX *= -1;
            else if( y <= boundY)
                dirY *= -1;
            else if ( y >= g_Game.GetScreen_H()){
                SetAlive(false);
                LoseEffect();
                Platform* platform = dynamic_cast<PlayingState*>(g_GamePtr->GetState())->GetPlatform();
                platform->LoseLife();
                platform->MorphPlatform(-1);            // calling platform to lose it's effect because ball has just died
            }
        }
        // we also update its animation if it exists
        if(animation) animation->Animate();
    }
    return 0;
}
void Ball::StartFlying(){
    

    // starting the ball, if it's not alive we dont allow for starting it again, until it dies
    if(!isAlive()){
        SetAlive(true);
        Init();
    }else if ( stand_on_platform){
        stand_on_platform = false;
        Update(0);                   //making sure that it will escape platform
    }

}


void Ball::Collided(int ObjectID, col_dir dir){
    if(dir == NO_COLLISION)
        return;

    //checking for collision with PLAYER
    if(ObjectID == PLAYER){
        
        if(has_effect == MAGNET && stand_on_platform == false)
            stand_on_platform = true;
        else{
            switch(dir){
                case LEFT:
                    dirX = -1;
                    break;
                case RIGHT:
                    dirX = 1;
                    break;
                case TOP:
                    dirY = -1;
                    break;
                case TLCOR:
                    dirX = -1;
                    dirY = -1;
                    break;
                case TRCOR:
                    dirX = 1;
                    dirY = -1;
                    break;
            }
            if(velX <0) velX -= .2; else velX += .2;
            if(velY <0) velY -= .2; else velY += .2;
            dynamic_cast<PlayingState*>(g_GamePtr->GetState())->GetPlatform()->AddPoint();
            if(g_GamePtr->isSfxOn())
                Mix_PlayChannel(-1, g_GamePtr->GetSfx(), 0);
            
        }
    } else if(ObjectID == BLOCK){
        switch(dir){
            case LEFT:
                dirX = -1;
                break;
            case RIGHT:
                dirX = 1;
                break;
            case TOP:
                dirY = -1;
                break;
            case BOTTOM:
                dirY = 1;
                break;
            case TLCOR:
                dirX = -1;
                dirY = -1;
                break;
            case TRCOR:
                dirX = 1;
                dirY = -1;
                break;
            case BLCOR:
                dirX = -1;
                dirY = 1;
                break;
            case BRCOR:
                dirX = 1;
                dirY = 1;
                break;
        }
    }
}