//
//  MapLoader.h
//  Arkanoid
//
//  Created by Maciej Żurad on 11/25/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#ifndef __Arkanoid__MapLoader__
#define __Arkanoid__MapLoader__

#include <iostream>
#include <list>
#include <istream>
#include <sstream>
#include <map>
#include "scaler.h"
#include "Block.h"
#include "ConfigFile.h"
#include "Game.h"

using namespace std;

class MapLoader {

private:
    ConfigFile *configfile;
    map<char, SDL_Surface*> bitmaps;
    
    void LoadBitmaps();
    void UnloadBitmaps();
    
public:
    MapLoader(string filename);
    ~MapLoader();

    list<GameObject*> LoadMap(string filename);

};

#endif /* defined(__Arkanoid__MapLoader__) */
