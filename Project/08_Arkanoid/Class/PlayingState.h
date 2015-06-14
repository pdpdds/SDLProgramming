//
//  PlayingState.h
//  Arkanoid
//
//  Created by Maciej Żurad on 11/26/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#ifndef __Arkanoid__PlayingState__
#define __Arkanoid__PlayingState__

#include <iostream>
#include "Game.h"
#include "State.h"
#include "GameObject.h"
#include "Platform.h"
#include "Ball.h"
#include "Block.h"
#include "Effect.h"
#include "Projectile.h"
#include "MapLoader.h"
#include "Gui.h"

class Gui;
class Platform;
class Ball;
class Block;
class Effect;
class Projectile;

class MapLoader;

using namespace std;

class PlayingState : public State {

private:
    bool changingstate;
    
    list<GameObject*> gobjects;
    MapLoader* map_loader;
    
    Ball* ball;
    Ball* second_ball;
    Platform* platform;
    Effect** effects;
    Projectile** projectiles;
    Gui* gui;
    
    int second_ball_flag;
    
    void SaveHighscores();
    
public:
    PlayingState();
    ~PlayingState();
    
    void InitState();
    void RenderState();
	void UpdateState(float fElapsedTime);
    void HandleEvents(Uint8* keystates, SDL_Event event, int control_type);
    
    void SetChangingStateFlag(bool flag) { changingstate = flag; }
    bool GetChangingStateFlag() { return changingstate; }
    
    Effect** GetEffects(){return effects;}
    Projectile** GetProjectiles(){return projectiles;}
    Platform* GetPlatform() {return platform;}
    Ball* GetBall() {return ball;}
    
    void LaunchSecondBall();
};
#endif /* defined(__Arkanoid__PlayingState__) */
