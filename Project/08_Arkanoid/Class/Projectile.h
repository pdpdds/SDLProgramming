//
//  Projectile.h
//  Arkanoid
//
//  Created by Maciej Żurad on 11/25/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#ifndef __Arkanoid__Projectile__
#define __Arkanoid__Projectile__

#include <iostream>
#include "Game.h"
#include "GameObject.h"

class Projectile : public GameObject {
    
public:
    Projectile(const char* filename = NULL, int maxFrame = 0, int frameDelay = 0, int frameWidth = 0,
         int frameHeight = 0, int animationColumns = 0, int animationDirection = 0 ) ;
   
    void Destroy();
    void Init(int x, int y, int velY);
    void Render();
	int Update(float fElapsedTime);
        
    //respond to collision function
    void Collided(int ObjectID, enum col_dir );
    
    
};
#endif /* defined(__Arkanoid__Projectile__) */
