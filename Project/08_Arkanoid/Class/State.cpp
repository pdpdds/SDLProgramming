//
//  State.cpp
//  Arkanoid
//
//  Created by Maciej Żurad on 11/26/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#include "State.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

State::State(){
    //ifstream file;
    //file.open("./data/highscores");
	SDL_RWops *file = SDL_RWFromFile("./data/highscores", "rb");
    
	std::vector<char> horizontal;
	char ch;
	// iterating through lines of map file
	while (1 == SDL_RWread(file, &ch, sizeof(char), 1))
	{
		if (ch == '\n')
		{
			std::string line(horizontal.begin(), horizontal.end());
			size_t it = 0; // character pointer

			line.erase(remove(line.begin(), line.end(), ' '), line.end());                          //removing whitespaces

			string name = line.substr(0, it = line.find_first_of(","));                                   //getting players name
			line.erase(0, it + 1);

			int score = StrToInt(line);
			highsco_list.push_back(pair<string, int>(name, score));
			horizontal.clear();
			continue;
		}
		horizontal.push_back(ch);
	}
	SDL_RWclose(file);
}


int StrToInt(string s){
    istringstream istr(s);
    int returnVal;
    istr >> returnVal;
    
    return returnVal;
}

bool Compare(pair<string, int> a, pair<string, int> b){
    return a > b ;
}

void State::PushScore(string name, int highscore){
    highsco_list.push_back(pair<string, int>(name, highscore));
    highsco_list.sort(Compare);
}
