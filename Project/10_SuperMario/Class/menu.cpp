/* 
File:
	menue.cpp
Description:
	contains implementation of menu class
	based on code from lazyfoo Tutorials 
	http://lazyfoo.net/SDL_tutorials/lesson07/index.php
	font taken from this URL
	http://www.fonts101.com/fonts/view/Standard/59229/AEH.aspx
Progammer:
	Mike duggan
*/

#include"menu.h"
#include<sstream>
#include"button.h"
#include "SDLSingleton.h"

//constants for the window values
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;
const int WINDOW_BPP = 32;


//constructor
menu::menu (int size)
{

  SDL_Init (SDL_INIT_EVERYTHING); //intialize SDL if not already initialized
  TTF_Init (); //initialize ttf library
  // font = TTF_OpenFont ("AEH.TTF", size); //load text font
  scorefont = TTF_OpenFont("AEH.TTF", 15); //load score font
  SDL_Color tempColor = { 255, 255, 255 }; //initalize text color (white)
  textColor = tempColor; //sets the final text color
  background = loadBackground ("background.png"); //loads background image
  superlep = load("superlep.png"); //loads super leprechaunio logo
}

menu::~menu () //deconstructor: frees open images, fonts, and quits the SDL libraries
{
  SDL_FreeSurface (background);
  SDL_FreeSurface (superlep);
  TTF_Quit ();
  SDL_Quit ();

}



//sets up timer that will last at most 4 seconds unless user hits "x" on window or q key
int menu::timer(){
	clock_t end = clock() + 4*CLOCKS_PER_SEC; //finds end
	  SDL_Event event; //event for sdl 
 
	while(clock()<end){	//continues to count time until 4 seconds reached or user quits the screen
		 while (SDL_PollEvent (&event)){
		  if (event.type == SDL_QUIT)
	    		return 0;
			
		  int numkeys;
		  Uint8 *keystate = (Uint8*)SDL_GetKeyboardState(&numkeys);

		  // User quits
		  if (keystate[SDL_GetScancodeFromKey(SDLK_q)] || keystate[SDL_GetScancodeFromKey(SDLK_RETURN)] || 
			  keystate[SDL_GetScancodeFromKey(SDLK_w)] || keystate[SDL_GetScancodeFromKey(SDLK_a)] || 
			  keystate[SDL_GetScancodeFromKey(SDLK_d)] || keystate[SDL_GetScancodeFromKey(SDLK_RSHIFT)] || keystate[SDL_GetScancodeFromKey(SDLK_LSHIFT)])
		    return 0;
		}
	}

return 0;
}

//function that takes a string argument and places it on the window given the location and size of the text
void menu::apply_message (string messText, SDL_Surface * window, int x, int y, int size = 15)
{
  font = TTF_OpenFont ("AEH.TTF", size);
  message = TTF_RenderText_Solid (font, messText.c_str (), textColor);
  apply_image (message, window, NULL, x, y);
  TTF_CloseFont (font);
}


//function that displays scores using the score font (size is changed slightly from apply_message function)
void menu::apply_scores (string messText, SDL_Surface * window, int x, int y)
{
  message = TTF_RenderText_Solid (scorefont, messText.c_str (), textColor);
  apply_image (message, window, NULL, x, y);
}


//displays a black screen that states "YOU LOSE"
void menu::losingScreen(SDL_Surface *window){
  SDL_FillRect( window, &window->clip_rect, SDL_MapRGB( window->format, 0, 0, 0) );
  apply_message("You Lose!", window, 215, 200, 35);
  SDLSingleton::GetInstance()->DoRender();
  while(timer());
}

//displays a message on the screen saying that player has advanced to the next level
void menu::advancingScreen(SDL_Surface *window){
   SDL_Surface *nextLevel = load("NEXTLEVEL.png");
apply_image (background, window, NULL, 0, 0);
apply_image (nextLevel, window, NULL, 74, 100);
SDLSingleton::GetInstance()->DoRender();
//SDL_Delay(4000);
  while(timer());
  
}

//displays a message saying that the player has won the game
void menu::winningScreen(SDL_Surface *window){
   SDL_Surface *win = load("WINNER.png");
apply_image (background, window, NULL, 0, 0);
apply_image (win, window, NULL, 73, 100);
SDLSingleton::GetInstance()->DoRender();
//SDL_Delay(4000);
  while(timer());
  
}

//runs the start screen and uses two buttons to determine when to start game or change window
int menu::runStartScreen (SDL_Surface * window)
{
  
  button startButton ("PLAYBUTTON.png", 31, 300); //makes start button
  button instructionsButton ("HELPBUTTON.png", 400, 300); //makes play button
  apply_image (background, window, NULL, 0, 0); //adds background to screen
  apply_image (superlep, window, NULL, 0, 30); //adds logo to screen
  startButton.apply_button (window); //adds start button to screen
  instructionsButton.apply_button (window); //adds help button to screen
  SDLSingleton::GetInstance()->DoRender();
	
  //checks for user either hitting buttons or exiting program
  SDL_Event event; 
  while (1)
    {
      while (SDL_PollEvent (&event))
	{
	  if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
	    {

		  if (startButton.isClicked (event.button.x, event.button.y))
		    {
		      return 1;
		    }
		  else
		    if (instructionsButton.isClicked
			(event.button.x, event.button.y))
		    {
		      return -1;
		    }

		}
	  if (event.type == SDL_QUIT)
	    return 0;


	}
    }
  return 0;
}

//function that runs instruction image on screen until user exits program or goes back to 
	//start  menu
int menu::runInstScreen (SDL_Surface * window)
{

  instructions = load ("instructions.png"); //instruction image 
  apply_image (background, window, NULL, 0, 0); //adds background to screen
  apply_image (instructions, window, NULL, 91, 40); //adds instructions to screen
  button backButton ("BACKBUTTON.png", 50, 370); //adds back button
  backButton.apply_button (window); //adds back button to screen
  SDLSingleton::GetInstance()->DoRender();
 
 //checks to see if user has exited program or hit the back button
  SDL_Event event;
  while (1)
    {
      while (SDL_PollEvent (&event))
	{
	  if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT&&backButton.isClicked (event.button.x, event.button.y))
	    {	SDL_FreeSurface(instructions);		      
			return 1;
	    }
	  if (event.type == SDL_QUIT)
	    return 0;
	}

    }

  return 1;
}

//function that runs the instruction and start menus until the user elects to start the game
int menu::initialMenus (SDL_Surface * window)
{
  while (1)
    {
      int temp = runStartScreen (window); //runs start screen
      if (temp == 1) //checks for user starting
	return 0;
      else if (temp == -1) //checks for user hitting instruction button
	{
	  if (runInstScreen (window) == 0)
	    return 1;
	}
      else if (temp == 0) //checks for user qutting game
	return 1;

    }
  return 0;
}


//function that displays what level the user is on and how many lives are left
void menu::levelScreen (int level, int lives, SDL_Surface * window)
{
//makes window black
SDL_FillRect( window, &window->clip_rect, SDL_MapRGB( window->format, 0, 0, 0) );

  font = TTF_OpenFont ("AEH.TTF", 30); //opens font
  stringstream outstring; //intializes streams
  stringstream outstring2;
  outstring << "Level: "<< level; //sets level stream
  apply_message (outstring.str (), window, 265, 200); //applies level stream
  outstring2 << "Lives Remaining: " << lives; //applies lives stream
  font = TTF_OpenFont ("AEH.TTF", 18); //open different size font
  apply_message (outstring2.str (), window, 232, 230); //applies lives stream
  SDLSingleton::GetInstance()->DoRender();
  while(timer()); 
}

//function that is called by main that outputs the scores on the screen in the proper place
void menu::gameNumbers (int livesRemaining, int currentScore, SDL_Surface * window)
{

  ostringstream scorestring; //score stream
  ostringstream livesstring; //live string 
  scorestring << "Score: " << currentScore; //makes score stream
  livesstring << "Lives: " << livesRemaining; //makes lives stream

  apply_scores (scorestring.str(), window, 520, 0); //applies score stream
  apply_scores (livesstring.str(), window, 520, 20); //applies lives stream
}
