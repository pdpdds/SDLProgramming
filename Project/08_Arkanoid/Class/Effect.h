//
//  Effect.h
//  Arkanoid
//
//  Created by Maciej Żurad on 11/25/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#ifndef __Arkanoid__Effect__
#define __Arkanoid__Effect__

#include <iostream>
#include "GameObject.h"
#include "Game.h"


class Effect : public GameObject {
    
private:
    int effect_type;
public:
    Effect(const char* filename = NULL, int maxFrame = 0, int frameDelay = 0, int frameWidth = 0,
           int frameHeight = 0, int animationColumns = 0, int animationDirection  = 0);

    void Destroy();
    
    void Init();
    void Init(int x, int y);
    void Render();
	int Update(float fElapsedTime);

    void SetEffectType(int effect_type) { Effect::effect_type = effect_type;}

    
    void Collided(int ObjectID, col_dir dir);

};

#endif /* defined(__Arkanoid__Effect__) */
