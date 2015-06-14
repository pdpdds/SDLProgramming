//
//  Platform.h
//  Arkanoid
//
//  Created by Maciej Żurad on 11/18/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#ifndef __Arkanoid__Platform__
#define __Arkanoid__Platform__

#include <iostream>
#include <cstdlib>
#include "GameObject.h"
#include "Game.h"


class Platform : public GameObject {
    
private:
    int lives;
    int score;
    int has_effect;
    
public:
    Platform(const char* filename = NULL, int maxFrame = 0, int frameDelay = 0, int frameWidth = 0,
         int frameHeight = 0, int animationColumns = 0, int animationDirection = 0 ) ;
    void Destroy();
    
    void Init();
	int Update(float fElapsedTime);
    void Render();
    
    void MoveLeft();
    void MoveRight();
    void StopMoving();
    
    void Shoot();
    
    void MorphPlatform(int effect_type);
    
    int GetScore() {return score;}
    int GetLives() {return lives;}
    
    void LoseLife() { --lives;}
    void AddPoint() { ++score;}
    
    void Collided( int objectID, col_dir dir);
};


#endif /* defined(__Arkanoid__Platform__) */
