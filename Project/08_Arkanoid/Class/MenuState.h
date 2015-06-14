//
//  MenuState.h
//  Arkanoid
//
//  Created by Maciej Żurad on 11/26/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#ifndef __Arkanoid__MenuState__
#define __Arkanoid__MenuState__

#include <iostream>
#include <sstream>
#include <tuple>
//#include "Game.h"
#include "State.h"
#include "Background.h" 

using namespace std;

//ID enums for current menu state and option ID
enum MENU_STATE{MAIN_MENU, OPTIONS, HIGHSCORES};
enum MENU_OPTION_IDS{SHOWFPS, MUSICON, SOUNDON};



// Function pointer to function that is run when object is clicked
typedef void (*Clicked)(void);

// typdefs for cleaner implementation of menu objects
typedef tuple<SDL_Surface*, SDL_Surface*, SDL_Surface*> Text;

typedef tuple<Text, bool, Text> Highscore_Text;
typedef tuple<Text, bool, Clicked> MainMenuText;
typedef tuple<Text, bool, Clicked, Text, Text, bool, int> OptionsText;

//friend functions
void GotoOptions();
void GotoHighscores();
void GotoMainMenu();

class Background;


class MenuState : public State {
    
    
private:
    list<Background*> bgs;
    
    list<MainMenuText> menu_main;
    list<Highscore_Text> menu_highscores;
    list<OptionsText> menu_options;

    int mouse_pos_x;
    int mouse_pos_y;
    
    int offsetX;    // offset from top to first menu message
    int offsetY;    // offset from left to menu messages
    
    int distance_between_msg;       //vertical distance between consecutive MSGs
    int distance_between_opt;       //horizontal distance between Option and value
    
    int curMenu;
    
    SDL_Color text;
    SDL_Color shade;
    SDL_Color highlight;
    
    TTF_Font* font;
    inline void Draw(SDL_Surface* image, int x, int y) const;
    
    //function pointers to menu event listener
    Clicked startgame;
    Clicked options;
    Clicked highscores;
    Clicked quit;
    Clicked mainmenu;
    Clicked showfps;
    Clicked musicon;
    Clicked soundon;
    
    template <typename T> void UpdateList(list<T> &menu_list);
    template <typename T> void RunCommand(list<T> menu_list);
    
    
public:
    MenuState();
    void Destroy();

    void UpdateInfo(int ID);
    void RenderState();
	void UpdateState(float fElapsedTime);
    void HandleEvents(Uint8* keystates, SDL_Event event, int control_type);
    
    friend void GotoOptions();
    friend void GotoHighscores();
    friend void GotoMainMenu();
};

#endif /* defined(__Arkanoid__MenuState__) */
