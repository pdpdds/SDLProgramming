 //
//  Game.cpp
//  Arkanoid
//
//  Created by Maciej Żurad on 11/18/12.
//  Copyright (c) 2012 Maciej Żurad. All rights reserved.
//

#include "Game.h"



Game::~Game(){
    
    delete fps_counter;
    delete game_state;
    
    closeSystems();
}

Game::Game(){
    
    music = Mix_LoadMUS("data/sounds/music.mp3");
    sound = Mix_LoadWAV("data/sounds/sfx.wav");
   // SDL_WM_SetCaption("ARKANOID", NULL);
        
    if(initSystems() == -1)
        cerr << "Problem occured while initializing SDL systems" << endl;
    
    font = TTF_OpenFont("data/mainfont.ttf", 35);
    if(!font) {
        cerr << "Could not load font " << TTF_GetError << endl;
        exit(1);
    }
    
    running = true ;
    
    //just for now
    gameFPS = 60;
    musicOn = false;
    sfxOn = false;
    control_type = KEYBOARD;
    current_state = MENU ;
    
    
    
    fps_counter = new FpsCounter(gameFPS);

    game_state = new MenuState();
    game_state->InitState();
    
}

int Game::initSystems()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
	{
		cerr << "Problem while initializing SDL" << endl;
		return -1;
	}
	
#ifndef WIN32 
	if (SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN, &m_pWindow, &m_pRenderer) < 0)
#else
	screen_w = 640;
	screen_h = 480;
	if (SDL_CreateWindowAndRenderer(screen_w, screen_h, 0, &m_pWindow, &m_pRenderer) < 0)
#endif
	{
		std::cout << "SDL_CreateWindowAndRenderer Error: " << SDL_GetError() << std::endl;
		return 0;
	}

	SDL_GetWindowSize(m_pWindow, &screen_w, &screen_h);

	screen = SDL_CreateRGBSurface(0, screen_w, screen_h, 32,
		0,
		0,
		0,
		0);

	if (screen == 0)
	{
		std::cout << "SDL_CreateRGBSurface Error: " << SDL_GetError() << std::endl;
		return false;
	}

	m_pScreenTexture = SDL_CreateTexture(m_pRenderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		screen_w, screen_h);

	if (m_pScreenTexture == 0)
	{
		std::cout << "SDL_CreateTexture Error: " << SDL_GetError() << std::endl;
		return -1;
	}
		
	if (TTF_Init() < 0) {
		cerr << "Problem initializing SDL_ttf" << endl;
		return -1;
	}
	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 4096) < 0) {
		cerr << "Problem initializing SDL_mixer" << endl;
		return -1;
	}
    Mix_Init(MIX_INIT_MP3);
	return 0;
}

void Game::closeSystems(){
    if(!screen) SDL_FreeSurface(screen);
    if (!font) TTF_CloseFont(font);
    if (!sound) Mix_FreeChunk(sound);
    if (!music) Mix_FreeMusic(music);
    Mix_CloseAudio();
    TTF_Quit();
    SDL_Quit();
}

int Game::Loop(){
	float fElapsedTime = 0.0f;
	Uint32 lastTime = SDL_GetTicks();
	
	while (running)
	{
		//if (fps_counter->measureFPS()){
		

		HandleEvents();
		SDL_FillRect(screen, NULL, 0);

		Uint32 currentTime = SDL_GetTicks();
		Uint32 diff = currentTime - lastTime;
		lastTime = currentTime;

		game_state->UpdateState((float)diff / (float)1000);
		game_state->RenderState();

		if (displayFPS)
		{
			static char buffer[10] = { 0 };
			sprintf(buffer, "%d FPS", fps_counter->getFPS());
			//        SDL_WM_SetCaption(buffer, NULL);
		}
		else
		{
			//			SDL_WM_SetCaption("Arkanoid", NULL);}

		}
		SDL_RenderClear(m_pRenderer);
		SDL_UpdateTexture(m_pScreenTexture, NULL, screen->pixels, screen->pitch);
		SDL_RenderCopy(m_pRenderer, m_pScreenTexture, NULL, NULL);
		SDL_RenderPresent(m_pRenderer);
		//}
	}
	return 0;
}


void Game::HandleEvents(){

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{

		if (event.type == SDL_QUIT)
			ShutDown();

		//Uint8* keystates = SDL_GetKeyState(NULL);
		int numkeys = 0;
		Uint8* keystates = (Uint8*)SDL_GetKeyboardState(&numkeys);

		//if(keystates[SDLK_q])
		//    ShutDown();

		if (keystates[SDL_GetScancodeFromKey(SDLK_q)])
			ShutDown();

		game_state->HandleEvents(keystates, event, control_type);
	}

}


void ChangeState(){
	Game* game = g_GamePtr;
	if (game->current_state == PLAYING){
		game->current_state = MENU;
		delete game->game_state;
		game->game_state = new MenuState();
		game->game_state->InitState();

	}
	else if (game->current_state == MENU){
		game->current_state = PLAYING;
		delete game->game_state;
		game->game_state = new PlayingState();
		game->game_state->InitState();
	}
}

void ShutDown(){
    g_GamePtr->running = false;
}

void SwitchFPSVisibility(){
    g_GamePtr->displayFPS = !g_GamePtr->displayFPS;
    dynamic_cast<MenuState*>(g_GamePtr->GetState())->UpdateInfo(SHOWFPS);
}
void SwitchMusic(){
    g_GamePtr->musicOn = !g_GamePtr->musicOn;
    dynamic_cast<MenuState*>(g_GamePtr->GetState())->UpdateInfo(MUSICON);
    
    if(g_GamePtr->musicOn){
        Mix_PlayingMusic();
        Mix_PlayMusic(g_GamePtr->music, -1);
    } else {
        Mix_HaltMusic();
    }
        
}
void SwitchSfx(){
    g_GamePtr->sfxOn = !g_GamePtr->sfxOn;
    dynamic_cast<MenuState*>(g_GamePtr->GetState())->UpdateInfo(SOUNDON);
}

void Game::Draw(SDL_Surface* screen, SDL_Surface* source,int x, int y) {
    SDL_Rect offset = {(Sint16)x, (Sint16)y, 0, 0};
    SDL_Rect clip = {0, 0, (Uint16)source->w, (Uint16)source->h};
    SDL_BlitSurface(source, &clip, screen, &offset);
}

string IntToStr(int n){
    stringstream ss;
    ss << n;
    return ss.str();
}

void DisplayFinishText(int ms, const char* text){
    
    TTF_Font* font = TTF_OpenFont("data/font.ttf", 70);
    
    int posX = g_GamePtr->GetScreen_W()/2;
    int posY = g_GamePtr->GetScreen_H()/2;
    
    
    SDL_Color color = {0x2b, 0xd7, 0xb7, 0};
    SDL_Color shade = {0xff, 0xff, 0xff, 0};
    
    SDL_Surface* text_image = TTF_RenderText_Solid(font, text, color);
    SDL_Surface* text_shade = TTF_RenderText_Solid(font, text, shade);
    
    Game::Draw(g_GamePtr->GetScreen(), text_shade, posX - text_shade->w/2 +2, posY - text_shade->h/2 +2);
    Game::Draw(g_GamePtr->GetScreen(), text_image, posX - text_image->w/2, posY - text_image->h/2);
    
    //SDL_Flip(g_GamePtr->GetScreen());
	SDL_RenderClear(g_GamePtr->m_pRenderer);
	SDL_UpdateTexture(g_GamePtr->m_pScreenTexture, NULL, g_GamePtr->GetScreen()->pixels, g_GamePtr->GetScreen()->pitch);
	SDL_RenderCopy(g_GamePtr->m_pRenderer, g_GamePtr->m_pScreenTexture, NULL, NULL);
	SDL_RenderPresent(g_GamePtr->m_pRenderer);
    
    int firstMeasure = SDL_GetTicks();
    while(SDL_GetTicks() - firstMeasure <= ms);
    
    SDL_FreeSurface(text_shade);
    SDL_FreeSurface(text_image);
    TTF_CloseFont(font);
}










