//
//  PlayingState.cpp
//  Arkanoid
//
//  Created by Maciej Żurad on 11/26/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#include "PlayingState.h"

PlayingState::PlayingState() : State(){
    
    changingstate = false;
    
    platform = new Platform("data/graphics/platformw.png", 3, 0, 66, 18, 4, 0);
  
    ball = new Ball("data/graphics/ball.png", 0, 1, 16, 16, 1, 1);
    second_ball = new Ball("data/graphics/ball.png", 0, 1, 16, 16, 1, 1);
    
    //pushing ball and platform on the list
    gobjects.push_back(platform);
    gobjects.push_back(ball);
    
    
    //loading blocks
    map_loader = new MapLoader("data/config");
    gobjects.splice(gobjects.end(), map_loader->LoadMap("data/map.cfg"));
    
    
    //loading projectiles
    projectiles = new Projectile*[10];     // Creating 10 projectile pointers as arbitrary value
    for(int i=0; i<3; i++){
        projectiles[i] = new Projectile("data/graphics/effect.png", 23, 4, 16, 14, 24, 1);
        gobjects.push_back(projectiles[i]);
    }
    
    effects = new Effect*[3];
    effects[0] = new Effect("data/graphics/effect.png", 23, 4, 16, 14, 24, 1);
    effects[0]->SetEffectType(GUN);
    effects[1] = new Effect("data/graphics/effect2.png", 10, 7, 34, 29, 11, 1);
    effects[1]->SetEffectType(MAGNET);
    effects[2] = new Effect("data/graphics/effect3.png", 59, 1, 60, 60, 8, 1);
    effects[2]->SetEffectType(SECONDBALL);
    
    
    // we push effects as last elem. beacause they have to be rendered as last objs
    for(int i=0; i<3; i++)
        gobjects.push_back(effects[i]);
    
    gui = new Gui();
    gui->Init(g_GamePtr->GetScreen_W() - 135, g_GamePtr->GetScreen_H() - 35);
    
    second_ball_flag = false;       // setting up flag , second wasnt intialized yet ( pushed on the list )
}

PlayingState::~PlayingState(){
    

    delete map_loader;
    for(list<GameObject*>::iterator iter = gobjects.begin(); iter != gobjects.end(); iter++)
        (*iter)->Destroy();
    delete gui;
    
    SaveHighscores(); // we save list of highscores to file
}

void PlayingState::RenderState(){
    for(list<GameObject*>::iterator iter = gobjects.begin(); iter!=gobjects.end(); iter++)
        (*iter)->Render();
    
    gui->Render();
    
    if(changingstate){
        DisplayFinishText(3000, "Game over");
        changingstate = false;
        ChangeState();
    }
    
}

void PlayingState::UpdateState(float fElapsedTime){
    for(list<GameObject*>::iterator iter = gobjects.begin(); iter!=gobjects.end(); iter++)
        for(list<GameObject*>::iterator iter2 = gobjects.begin(); iter2!=gobjects.end(); iter2++)
            (*iter)->Collided((*iter2)->GetID(), (*iter)->detectCollision(*iter2));

    gui->Update();

    for(list<GameObject*>::iterator iter = gobjects.begin(); iter!=gobjects.end(); iter++)
	if ((*iter)->Update(fElapsedTime) == -1)
            break;  // if an update function returns -1 then we break from loop because we are about to change state
}

void PlayingState::HandleEvents(Uint8* keystates, SDL_Event event, int control_type){
    
	if (keystates[SDL_GetScancodeFromKey(SDLK_ESCAPE)]){
        ChangeState();
        return;             // we get the hell out of here
    }
    
	if (keystates[SDL_GetScancodeFromKey(SDLK_SPACE)])
        ball->StartFlying();
    
    
    // Movement controls with keyboard
    if(control_type == KEYBOARD){
		if (keystates[SDL_GetScancodeFromKey(SDLK_LEFT)])
            platform->MoveLeft();
		else if (keystates[SDL_GetScancodeFromKey(SDLK_RIGHT)])
            platform->MoveRight();
        else
            platform->StopMoving();
        
        if(event.type == SDL_KEYDOWN)
            if(event.key.keysym.sym == SDLK_x)
                platform->Shoot();
        
    } else if(control_type == MOUSE){
        int x; // mouse x coordinate position
        SDL_GetMouseState(&x, NULL);
        if(x - 10 > platform->GetX())
            platform->MoveRight();
        else if (x + 10 < platform->GetX())
            platform->MoveLeft();
        else
            platform->StopMoving();
    }
}

void PlayingState::InitState(){
    for(list<GameObject*>::iterator iter = gobjects.begin(); iter!=gobjects.end(); iter++)
        (*iter)->Init();
}

void PlayingState::SaveHighscores(){
   /* ofstream file;
    file.open("data/highscores");
    
    for(list<pair<string, int>>::iterator iter=highsco_list.begin(); iter != highsco_list.end(); iter++)
        file << iter->first << ", " << iter->second << endl;
    
    file.close();*/
};

void PlayingState::LaunchSecondBall(){
    int t_dirX = (rand() % 2 +1)*2 -3 ;
    int t_dirY = (rand() % 2 +1)*2 -3 ;

    second_ball->GameObject::Init(ball->GetX(), ball->GetY(), rand()%2 +3, rand()%2 +3, t_dirX, t_dirY, ball->GetBoundX(), ball->GetBoundY());
    second_ball->SetAlive(true);
    if(!second_ball_flag){
        gobjects.push_back(second_ball);
        second_ball_flag = true;
    }

}
