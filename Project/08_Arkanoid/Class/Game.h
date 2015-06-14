//
//  Game.h
//  Arkanoid
//
//  Created by Maciej Żurad on 11/18/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#ifndef __Arkanoid__Game__
#define __Arkanoid__Game__

#include <iostream>
#include <list>
#include <string>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include "State.h"
#include "GameObject.h"
#include "Singleton.h"
#include "FpsCounter.h"
#include "PlayingState.h"
#include "MenuState.h"

#define g_Game Game::GetSingleton()
#define g_GamePtr Game::GetSingletonPtr()
#define BASE_SCREEN_X 960
#define BASE_SCREEN_Y 540

#define KEYBOARD 0
#define MOUSE 1

enum GAME_STATE {MENU, PLAYING};

using namespace std;

class FpsCounter;
class State;
class PlayingState;
class MenuState;


//helper function for conversion
string IntToStr(int n);
//helper function for Displaying Finish Text
void DisplayFinishText(int ms, const char* text);

//forward declaration for use as callback functions
void SwitchFPSVisibility();
void SwitchMusic();
void SwitchSfx();
void ChangeState();
void ShutDown();

class Game : public Singleton<Game> {
    
private:
    int initSystems();
    void closeSystems();
    
    bool running;
    bool paused;
    
    bool displayFPS;
    bool musicOn;
    bool sfxOn;
    
    int control_type;
    
    int current_state;
    
    int screen_w;
    int screen_h;
    int gameFPS;
    
    State* game_state;
    
    FpsCounter* fps_counter;
    
    SDL_Surface *screen;
    Mix_Chunk *sound;
    Mix_Music *music;
    TTF_Font *font;
    
public:
    Game();
    ~Game();
    int Loop();
    void HandleEvents();
        
    void SetScreen_W(int screen_w) { Game::screen_w = screen_w; }
    int GetScreen_W() {return screen_w; }
    
    void SetScreen_H(int screen_h) { Game::screen_h = screen_h; }
    int GetScreen_H() {return screen_h;}
    
    bool isMusicOn() { return musicOn;}
    bool isSfxOn() {return sfxOn;}
    
    bool isFPSVisible() {return displayFPS;}
    void setFPSVisile() { displayFPS = true;}
    
    Mix_Chunk* GetSfx() {return sound;}
    SDL_Surface* GetScreen() {return screen;}
    State* GetState() {return game_state;}
    TTF_Font* GetMainFont() {return font;}
    
    friend void ChangeState();
    friend void ShutDown();
    friend void SwitchFPSVisibility();
    friend void SwitchMusic();
    friend void SwitchSfx();
    
    static void Draw(SDL_Surface* screen, SDL_Surface* source, int x, int y)  ;  // helper function for drawing
public:
	SDL_Window *m_pWindow;
	SDL_Renderer *m_pRenderer;
	SDL_Texture* m_pScreenTexture;

};
#endif /* defined(__Arkanoid__Game__) */
