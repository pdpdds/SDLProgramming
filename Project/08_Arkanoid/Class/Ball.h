//
//  Ball.h
//  Arkanoid
//
//  Created by Maciej Żurad on 11/21/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#ifndef __Arkanoid__Ball__
#define __Arkanoid__Ball__

#include <iostream>
#include "GameObject.h"
#include "Game.h"
#include <algorithm>

using namespace std;

class Ball : public GameObject {
    int has_effect;
    bool stand_on_platform;
    
public:
    Ball(const char* filename = NULL, int maxFrame = 0, int frameDelay = 0, int frameWidth = 0,
                    int frameHeight = 0, int animationColumns = 0, int animationDirection = 0 ) ;
    
    
    void Destroy();
    void Init();
    void Render();
	int Update(float fElapsedTime);
    
    void MorphBall(int effect) {has_effect = effect; }
    void LoseEffect() {has_effect = -1;}
    void StartFlying();
    
    //respond to collision function
    void Collided(int ObjectID, enum col_dir );
    
    
};
#endif /* defined(__Arkanoid__Ball__) */
