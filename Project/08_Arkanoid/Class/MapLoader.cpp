//
//  MapLoader.cpp
//  Arkanoid
//
//  Created by Maciej Żurad on 11/25/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#include "MapLoader.h"
#include <vector>
// offsets for placing blocks properly on screen such that its edges are aligned with screen edges
#define offsetX g_Game.GetScreen_W()/(float)BASE_SCREEN_X*value.frameWidth/2.0
#define offsetY g_Game.GetScreen_H()/(float)BASE_SCREEN_Y*value.frameHeight/2.0

// multipliers for calulating size for scaled bitmap
#define scaleX g_Game.GetScreen_W()/(float)BASE_SCREEN_X
#define scaleY g_Game.GetScreen_H()/(float)BASE_SCREEN_Y

MapLoader::MapLoader(string filename){
    
    configfile = new ConfigFile(filename + ".cfg");
}


MapLoader::~MapLoader(){
    delete configfile;
    UnloadBitmaps();
}

list<GameObject*> MapLoader::LoadMap(string filename){
    
    // creating list which will contain block objects
    list<GameObject*> return_val;
    
    // opening map file
	SDL_RWops *file = SDL_RWFromFile(filename.c_str(), "rb");
    
 
    // setting y-coordinate starting position
    float posY =0;
    
    // loading bitmaps to a map 
    LoadBitmaps();
	std::vector<char> horizontal;
	char ch;
    // iterating through lines of map file
	while (1 == SDL_RWread(file, &ch, sizeof(char), 1))
	{
		if (ch == '\n')
		{
			std::string line(horizontal.begin(), horizontal.end());

			// if line is empty then we continue
			if (!line.length()){
				posY += g_Game.GetScreen_H() / 20;
				horizontal.clear();
				continue;
			}

			// setting x-coordinate starting position
			float posX = 0;

			//iterating through characters in line
			for (int i = 0; i < 20; i++){

				//if we have an empty symbol we continue in a row and move posX
				if (line[i] == ' '){
					posX += g_Game.GetScreen_W() / 20;					
					continue;
				}

				//Receiving value from config file map
				Value value = configfile->GetValue_at_Key(line[i]);

				Block* g_object = new Block(bitmaps.find(line[i])->second, value.maxFrame, value.frameDelay, value.frameWidth, value.frameHeight,
					value.animationColumns, value.animationDirection);

				g_object->Init(posX + offsetX, posY + offsetY, value.speed, value.dirX, value.health);

				return_val.push_back(g_object);

				posX += g_Game.GetScreen_W() / 20; // calculating X coordinate

			}

			posY += g_Game.GetScreen_H() / 20;     // calculating y coordinate
			horizontal.clear();
			continue;
		}

		horizontal.push_back(ch);
    }
    
	SDL_RWclose(file);
    
    return return_val;
}

void MapLoader::LoadBitmaps() {
    
    float scalerX = g_Game.GetScreen_W()/(float)BASE_SCREEN_X ;
    float scalerY = g_Game.GetScreen_H()/(float)BASE_SCREEN_Y ;
    
    for(map<char, Value>::iterator iter = configfile->map_begin();
        iter != configfile->map_end(); iter++)
    {
        Value val = iter->second;
        
        int scaled_width = scalerX * val.frameWidth * val.animationColumns ;
        int scaled_height = scalerY * val.frameHeight * (val.maxFrame+1) / val.animationColumns;
        
        SDL_Surface* image = LoadScaledBitmap(val.filename.c_str(),scaled_width, scaled_height);
        bitmaps.insert(pair<char, SDL_Surface*>(iter->first, image));
    }
        
}

void MapLoader::UnloadBitmaps(){
    for(map<char, SDL_Surface*>::iterator iter = bitmaps.begin();
        iter != bitmaps.end(); iter++)
    {
        SDL_FreeSurface(iter->second);
    }
}