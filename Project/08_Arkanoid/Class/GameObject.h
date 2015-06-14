//
//  GameObject.h
//  Arkanoid
//
//  Created by Maciej Żurad on 11/18/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#ifndef __Arkanoid__GameObject__
#define __Arkanoid__GameObject__

#include <iostream>
#include "Animation.h"

enum OBJECT_TYPE{PLAYER, BALL, BLOCK, EFFECT, PROJECTILE};                          // enum for defining an object, used during collisions
enum col_dir {NO_COLLISION, LEFT, RIGHT, TOP, BOTTOM, TLCOR, TRCOR, BLCOR, BRCOR};  // enum for indicating how objects collided, COR stands for corner
enum EFFECT_TYPE{GUN, MAGNET, SECONDBALL};


class Animation;

class GameObject {
    
private:
    bool alive;
    bool collidable;
    int ID;
    
protected:
    // object's properties for moving and collision
    float x;
    float y;
    float velX;
    float velY;
    
    int dirX;
    int dirY;
    float boundX;
    float boundY;
    
    Animation* animation;
    
public:
    
    GameObject(const char* filename = NULL, int maxFrame = 0, int frameDelay = 0, int frameWidth = 0,
               int frameHeight = 0, int animationColumns = 0, int animationDirection = 0 );
   
    GameObject(SDL_Surface* image = NULL, int maxFrame = 0, int frameDelay = 0, int frameWidth = 0,
               int frameHeight = 0, int animationColumns = 0, int animationDirection = 0 );
    
    void virtual Destroy();
    
    void virtual Init();  // reinitialization function
    
    void Init(float x, float y, float velX, float velY, int dirX, int dirY, float boundX, float boundY);
    void virtual Render();
	int virtual Update(float fElapsedTime);
    
    float GetX() { return x; }
    float GetY() { return y; }
    
    void SetX(float x) { GameObject::x = x; }
    void SetY(float y) { GameObject::y = y; }
    
    float GetBoundX() { return boundX; }
    float GetBoundY() { return boundY; }
    
    int GetID() { return ID;}
    void SetID(int ID) {GameObject::ID = ID;}
    
    int isAlive() { return alive ; }
    void SetAlive(bool alive) {GameObject::alive = alive;}
    
    int isCollidable() { return collidable; }
    void setCollidable(bool collidable) {GameObject::collidable = collidable;}
    
    enum col_dir detectCollision(GameObject* otherObject);
    void virtual Collided(int objectID, col_dir dir);
    bool Collidable(){ return alive && collidable ;}


    
};

#endif /* defined(__Arkanoid__GameObject__) */
