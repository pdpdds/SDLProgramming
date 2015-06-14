/* 
File:
	menu.h
Description:
	Contains the files for the menu system that displays at the beginning of game and 
	throughout the levels of the game
	NOTE: ttf file "AEH_____.TTF" and "AEH2.TTF" are identical fonts and are taken from this
		URL: http://www.fonts101.com/fonts/view/Standard/59229/AEH.aspx
Progammer:
	Mike Duggan
*/

#ifndef MENU_H
#define MENU_H

#include<iostream>
#include<string>
#include<ctime>
#include"mSDL.h"
using namespace std;

class menu
{

public:
  menu (int = 14); //constructor with default text size of 14
  ~menu (); //deconstructor for menu objects
  void apply_message (string, SDL_Surface *, int, int, int); //function that opens string for message and displays it on the screen given x, y, and size values
  int initialMenus (SDL_Surface *); //function for all the menus that can be used
  void levelScreen (int, int, SDL_Surface *); //function that displays the current level and number of lives left
  void gameNumbers (int, int, SDL_Surface *); //function that displays the game values
  void losingScreen (SDL_Surface *); //function that states that player lost
  void advancingScreen(SDL_Surface *); //function that states player is moving on to the next level
  void winningScreen(SDL_Surface *); //function that states that the player has beat the game


  void setEndTime(); //sets amount of time that levle will last
  int isDone(); //checks whether time is up for the player
  


private:
  SDL_Surface * message; //surface file for the message string
  TTF_Font *font; //ttf file for the font that will be uploaded
  SDL_Color textColor; //color indicator for the text to be displayed
  SDL_Surface *background; //surface file for the background of the screen
  SDL_Surface *superlep; //surface file for the super leprechaunio logo
  SDL_Surface *instructions; //surface file for the instructions to be displayed
  TTF_Font *scorefont; //ttf file for font used to display scores (different score than others)
  int runStartScreen (SDL_Surface *); //function that runs the startup screen
  int runInstScreen (SDL_Surface *); //function that runs the instruction
  int timer(); //function that allows for user to stop delay for screens between levels
  void apply_scores(string, SDL_Surface *, int, int); //displays all game status values during game play

};

#endif
