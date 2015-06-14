//
//  MenuState.cpp
//  Arkanoid
//
//  Created by Maciej Żurad on 11/26/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#include "MenuState.h"

#define RenderTextColor(_text, _color) TTF_RenderText_Solid(font, _text, _color)   // helpful macro for rendering text with color

// macro for placing 3 SDL_Surfaces in different colours defined as below
#define RenderText(_text) TTF_RenderText_Solid(font, _text, text),\
                            TTF_RenderText_Solid(font, _text, shade),\
                                TTF_RenderText_Solid(font, _text, highlight)

MenuState::MenuState() : State(){
    
    bgs.push_back(new Background("./data/graphics/background2.jpg", 1366, 768));
    //bgs.push_back(new Background("./data/graphics/starsback.png", 1700, 900));
    //bgs.push_back(new Background("./data/graphics/starsmidground.png", 1800, 1050));
    bgs.push_back(new Background("./data/graphics/starsforeground.png", 1550, 950));
    bgs.push_back(new Background("./data/graphics/starsforeforeground.png", 1800, 1050));
    
    curMenu = MAIN_MENU;        // setting first visible menu as MAIN MENU
    
    font = TTF_OpenFont("./data/font.ttf", 28);        // loading menu font
    if(!font) {
        cerr << "Could not load font " << TTF_GetError << endl;
        exit(1);
    }

    //Function pointers
    startgame = ChangeState;                    // pointer to function in Game.h to changes between states
    quit = ShutDown;                            // pointer to function in Game.h that performs an application shutdown
    options = GotoOptions;                      // pointer in to function that changes curMenu to OPTIONS
    highscores = GotoHighscores;                // pointer in to function that changes curMenu to HIGHSCORES
    mainmenu  = GotoMainMenu;                   // pointer in to function that changes curMenu to MAINMENU
    showfps = SwitchFPSVisibility;              // pointer to function in Game.h that switches displayFPS flag on or off
    musicon = SwitchMusic;                      // pointer to function in Game.h that switches musicON flag on or off
    soundon = SwitchSfx;                        // pointer to function in Game.h that switches sfxON flag on or off
    
    
    // message colors
    text = {0xFF, 0, 0, 0};
    shade = {0xc8, 0xc8, 0xc8, 0} ;
    highlight = {0, 0xFF, 0, 0};
    
    offsetX = g_GamePtr->GetScreen_W()/2.0;
    offsetY = g_GamePtr->GetScreen_H()/2.0 - 50;
    
    distance_between_msg = 50;
    distance_between_opt = 300;
    
    // creating main_menu objects
    menu_main.push_back(MainMenuText(make_tuple(RenderText("Start Game")), false, startgame));
    menu_main.push_back(MainMenuText(make_tuple(RenderText("Options")), false, options));
    menu_main.push_back(MainMenuText(make_tuple(RenderText("Highscores")), false, highscores));
    menu_main.push_back(MainMenuText(make_tuple(RenderText("Quit")), false, quit));
    
    //creating highscore objects
    for(list<pair<string, int>>::iterator iter = highsco_list.begin(); iter != highsco_list.end(); iter++)
        menu_highscores.push_back(Highscore_Text(make_tuple(RenderText((iter->first).c_str())), false, make_tuple(RenderText(IntToStr(iter->second).c_str()))));
    
    //creating menu option objects
    menu_options.push_back(OptionsText(make_tuple(RenderText("Show FPS")), false, showfps, make_tuple(RenderText("ON")), make_tuple(RenderText("OFF")), g_GamePtr->isFPSVisible(), SHOWFPS));
    menu_options.push_back(OptionsText(make_tuple(RenderText("Music")), false, musicon, make_tuple(RenderText("ON")), make_tuple(RenderText("OFF")), g_GamePtr->isMusicOn(), MUSICON));
    menu_options.push_back(OptionsText(make_tuple(RenderText("Sounds")), false, soundon, make_tuple(RenderText("ON")), make_tuple(RenderText("OFF")), g_GamePtr->isSfxOn(), SOUNDON));

    
}
void MenuState::Destroy(){
    for(list<Background*>::iterator iter = bgs.begin(); iter != bgs.end(); iter++)
        delete *iter;
    
    for(list<MainMenuText>::iterator iter = menu_main.begin(); iter != menu_main.end(); iter++){
        SDL_FreeSurface(get<0>(get<0>(*iter)));
        SDL_FreeSurface(get<1>(get<0>(*iter)));
        SDL_FreeSurface(get<2>(get<0>(*iter)));
    }
    
    for(list<Highscore_Text>::iterator iter = menu_highscores.begin(); iter != menu_highscores.end(); iter++){
        SDL_FreeSurface(get<0>(get<0>(*iter)));
        SDL_FreeSurface(get<1>(get<0>(*iter)));
        SDL_FreeSurface(get<2>(get<0>(*iter)));
    }
    
    for(list<OptionsText>::iterator iter = menu_options.begin(); iter != menu_options.end(); iter++){
        
        SDL_FreeSurface(get<0>(get<0>(*iter)));
        SDL_FreeSurface(get<1>(get<0>(*iter)));
        SDL_FreeSurface(get<2>(get<0>(*iter)));
        
        SDL_FreeSurface(get<0>(get<3>(*iter)));
        SDL_FreeSurface(get<1>(get<3>(*iter)));
        SDL_FreeSurface(get<2>(get<3>(*iter)));
        
        SDL_FreeSurface(get<0>(get<4>(*iter)));
        SDL_FreeSurface(get<1>(get<4>(*iter)));
        SDL_FreeSurface(get<2>(get<4>(*iter)));
    }
    
    TTF_CloseFont(font);
}

void MenuState::UpdateInfo(int ID){
    for(list<OptionsText>::iterator iter = menu_options.begin(); iter != menu_options.end(); iter++){
        if(ID == get<6>(*iter))
            get<5>(*iter) = !get<5>(*iter) ;
    }
}
void MenuState::RenderState(){
    for(list<Background*>::iterator iter = bgs.begin(); iter != bgs.end(); iter++)
        (*iter)->RenderBackground();
    
    int x = offsetX;
    int y = offsetY;
    
    switch (curMenu) {
        case MAIN_MENU:
            for(list<MainMenuText>::iterator iter = menu_main.begin(); iter != menu_main.end(); iter++){
                this->Draw(get<1>(get<0>(*iter)), x+1, y+1);
                if(get<1>(*iter))
                    this->Draw(get<2>(get<0>(*iter)), x, y);
                else
                    this->Draw(get<0>(get<0>(*iter)), x, y);
                y += distance_between_msg;
            }
            break;
        case OPTIONS:
            for(list<OptionsText>::iterator iter = menu_options.begin(); iter != menu_options.end(); iter++){
                this->Draw(get<1>(get<0>(*iter)), x+1, y+1);
                if(get<1>(*iter))
                    this->Draw(get<2>(get<0>(*iter)), x, y);
                else
                    this->Draw(get<0>(get<0>(*iter)), x, y);
                
                if(get<5>(*iter)){
                    this->Draw(get<1>(get<3>(*iter)), x+distance_between_opt+1, y+1);
                    if(get<1>(*iter))
                        this->Draw(get<2>(get<3>(*iter)), x+distance_between_opt, y);
                    else
                        this->Draw(get<0>(get<3>(*iter)), x+distance_between_opt, y);
                }else{
                    this->Draw(get<1>(get<4>(*iter)), x+distance_between_opt+1, y+1);
                    if(get<1>(*iter))
                        this->Draw(get<2>(get<4>(*iter)), x+distance_between_opt, y);
                    else
                        this->Draw(get<0>(get<4>(*iter)), x+distance_between_opt, y);
                }
                y += distance_between_msg;
            }
            break;
        case HIGHSCORES:
            int counter = 0 ; // we have to allow only print 5 highscores
            for(list<Highscore_Text>::iterator iter = menu_highscores.begin(); iter != menu_highscores.end() && counter<5; iter++){
                this->Draw(get<1>(get<0>(*iter)), x+1, y+1);
                if(get<1>(*iter))
                    this->Draw(get<2>(get<0>(*iter)), x, y);
                else
                    this->Draw(get<0>(get<0>(*iter)), x, y);
                
                this->Draw(get<1>(get<2>(*iter)), x+distance_between_opt+1, y+1);
                if(get<1>(*iter))
                    this->Draw(get<2>(get<2>(*iter)), x+distance_between_opt, y);
                else
                    this->Draw(get<0>(get<2>(*iter)), x+distance_between_opt, y);
                
                y += distance_between_msg;
                counter++;
            }
            break;
    }
}
void MenuState::UpdateState(float fElapsedTime){
    
    for(list<Background*>::iterator iter = bgs.begin(); iter != bgs.end(); iter++)
        (*iter)->UpdateBackground(g_GamePtr->GetScreen_W() - mouse_pos_x, g_GamePtr->GetScreen_H() - mouse_pos_y);
    switch (curMenu) {
        case MAIN_MENU:
            UpdateList(menu_main);
            break;
        case OPTIONS:
            UpdateList(menu_options);
            break;
        case HIGHSCORES:
            UpdateList(menu_highscores);
            break;
        default:
            break;
    }
}
void MenuState::HandleEvents(Uint8* keystates, SDL_Event event, int control_type){
    
    SDL_GetMouseState(&mouse_pos_x, &mouse_pos_y);
    
    
    switch (curMenu) {
        case OPTIONS:
			if (keystates[SDL_GetScancodeFromKey(SDLK_ESCAPE)]){
                GotoMainMenu();
                return;
            }
            break;
        case HIGHSCORES:
			if (keystates[SDL_GetScancodeFromKey(SDLK_ESCAPE)]){
                GotoMainMenu();
                return;
            }
            break;
        default:
            break;
    }
    
    
    if(event.type == SDL_MOUSEBUTTONUP){
        if(event.button.button == SDL_BUTTON_LEFT){
            switch (curMenu) {
                case MAIN_MENU:
                    RunCommand(menu_main);
                    break;
                case OPTIONS:
                    RunCommand(menu_options);
                    break;
                default:
                    break;
            }
        }
    }
}

inline void MenuState::Draw(SDL_Surface* image, int x, int y) const {
    SDL_Rect offset = {(Sint16)x, (Sint16)y, 0, 0};
    SDL_Rect clip = {0, 0, (Uint16)image->w, (Uint16)image->h};
    SDL_BlitSurface(image, &clip, g_Game.GetScreen(), &offset);
}

template <class T>
void MenuState::UpdateList(list<T> &menu_list){
    
    int counter = 0;
    
    for(typename list<T>::iterator iter = menu_list.begin(); iter != menu_list.end(); iter++){
        if (( mouse_pos_x >= offsetX) && ( mouse_pos_x <= offsetX + (get<0>(get<0>(*iter)))->w) &&
            ( mouse_pos_y >=offsetY + counter ) && ( mouse_pos_y <= offsetY + counter + get<0>(get<0>(*iter))->h))
        {
            get<1>(*iter) = true;
        }
        else
            get<1>(*iter) = false;
        
        counter += distance_between_msg;
    }
}



template <class T>
void MenuState::RunCommand(list<T> menu_list){
    for(typename list<T>::iterator iter = menu_list.begin(); iter != menu_list.end(); iter++){
        if(get<1>(*iter)){
            get<2>(*iter)();
            break;  // we destroyed the whole object propably, we better get the **** out
        }
    }
}


void GotoOptions(){
    dynamic_cast<MenuState*>(g_GamePtr->GetState())->curMenu = OPTIONS;
}

void GotoHighscores(){
    dynamic_cast<MenuState*>(g_GamePtr->GetState())->curMenu = HIGHSCORES;
}
void GotoMainMenu(){
    dynamic_cast<MenuState*>(g_GamePtr->GetState())->curMenu = MAIN_MENU;
}

