//
//  State.h
//  Arkanoid
//
//  Created by Maciej Żurad on 11/26/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#ifndef __Arkanoid__State__
#define __Arkanoid__State__

#include <iostream>
#include <SDL.h>
#include <list>

using namespace std;

bool Compare(pair<string, int> a, pair<string, int> b);
int StrToInt(string s);

class State {
    
protected:
    list<pair<string, int>> highsco_list;               // list of all highscores and their names
    
public:
    
    State();
    virtual ~State() {};
    
    void virtual HandleEvents(Uint8* keystates, SDL_Event event, int control_type) {};
    void virtual RenderState() {};
	void virtual UpdateState(float fElapsedTime) {};
    void virtual InitState() {};
    
    void PushScore(string name, int highscore);
    
};


#endif /* defined(__Arkanoid__State__) */
