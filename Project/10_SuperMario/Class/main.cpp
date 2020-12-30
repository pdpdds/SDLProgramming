/* main.cpp

-contains implementation of the mario game

Programmer: Vincent Birch, Mike Duggan, Scott Grimes, Kevin Sonnen
*/


#include"mSDL.h"
#include"player.h"
#include"block.h"
#include"enemy.h"
#include"purdue.h"
#include"menu.h"
#include"button.h"
#include<string>
#include<vector>
#include<iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#ifdef WIN32
#include <Windows.h>
#include <tchar.h>
#include "util.h"
#else
#include <sys/time.h>
#endif
#include <time.h>
#include "trojan.h"
#include "eagle.h"
#include<sstream>
using namespace std;
#include "SDLSingleton.h"

//window constants
const int WINDOW_WIDTH = 640;	//window width in pixels
const int WINDOW_HEIGHT = 480;	//window height in pixels
const int WINDOW_BPP = 32;	//bit per pixel constant for window
const int NUMBER_LEVELS = 3;	//constant for number of levels in the game
const int DEFAULT_LIVES = 3;	//constant for number of lives to start game with

//global variables: event and window surface
SDL_Surface *window = NULL;
SDL_Event event;

#ifdef WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
extern "C" int SDL_main(int argc, char *argv[])
#endif
{
  //initialize all SDL libraries
  SDL_Init (SDL_INIT_EVERYTHING);

  //open the window to be used with window dimensions
  window = openWindow ("Super Leprechaunio", WINDOW_WIDTH, WINDOW_HEIGHT,
		       WINDOW_BPP);

  //instantiate menu object that will be used throughout game
  menu menuScreen;


  //intialize game variables
  int lives = DEFAULT_LIVES;	//determines number of lives
  int level = 3;		//used for determining when game is over
  int quit = 0;			//checks if user has quit
  double globalScore = 0;	//keeps track of the player's score throughout game
  bool dead = false;		//checks if player has died
  double tempScore = 500;


  while (1)
    {

      if (menuScreen.initialMenus (window) == 1)	//runs menus and checks that user hasn't quit
	return 0;
      else			//if user hasn't quit, intializes variables to indicate a new game
	{
	  quit = 0; //var for whether user quit
	  lives = DEFAULT_LIVES; //variable for number of lives left
	  level = 1; //variable for current level
	  globalScore = 0; //total player score for restoring score after death
	  tempScore = 0; //temp score for incrementing lives 
	}

      while (lives > 0 && !quit && level <= NUMBER_LEVELS)	//continues game until player dies, or user quits or all levels are completed.
	{
	  //initialize player object "lep"
	  player lep ("lep.png", "background.png", (int) WINDOW_WIDTH,
		      (int) WINDOW_HEIGHT, window);
	

	  lep.setScore (globalScore);	//sets player score to whatever the global score is (will be zero when user first starts but greater than zero after player death)

	  //text file that will read in landscape
	  ifstream infile;

	
	  
	  stringstream outstring; //intializes streams
          outstring << level << ".txt"; //sets level stream
	  infile.open ((outstring.str()).c_str());
		
		

	

	  int length = 15000;	//integer for the length of the level in pixels

	  //intializes the block object which contains all landscape values
	  block floor (WINDOW_WIDTH, WINDOW_HEIGHT, length + 500, 0, infile);


	  //initializes window with initial position of character and color of screen
	  lep.update (floor, infile);

	  // Initialize time for random variables
	  timeval time;
	  gettimeofday (&time, NULL);
	  srand ((time.tv_sec * 1000) + (time.tv_usec / 1000));


	//create vector of enemies using polymorphism from the trojan, eagle and purdue classes
	  vector < enemy * >enemies; //vector of enemy pointers
	  vector < int >enemyLocations; //vector of enemy x positions
	  int x = 500; 	//first enemy x position
	  int numberEnemies = (rand () % 50 + 25); //generates random number of enemies
	  int randomNumber;	//random number for use in making enemies

	  // Creation of a vector of enemies
	  for (int i = 0; i < numberEnemies && x < length;
	       i++, x += (rand () % 50) + 300) //creates enemies
	    {
	      randomNumber = rand () % 10; //create random number

	      switch (randomNumber)
		{
		//cases for trojans (most common)
		case (1):
		case (2):
		case (3):
		case (4):
		case (5):
		  {
		    // Creates a point to an enemy that will be stored in the vector: enemies
		    trojan *en =
		      new trojan ("trojanSpriteSheet.png", 2 * WINDOW_WIDTH,
				  WINDOW_HEIGHT, x);
		    enemies.push_back (en);
		    break;
		  }
		//cases for eagles (second most common)
		case (6):
		case (7):
		case (8):
		  {
		    // Creates a point to an enemy that will be stored in the vector: enemies
		    eagle *en =
		      new eagle ("eagle.png", 2 * WINDOW_WIDTH, WINDOW_HEIGHT,
				 x);
		    enemies.push_back (en);
		    break;
		  }
		case (9): //case for trains(least common)
		  {
		    // Creates a point to an enemy that will be stored in the vector: enemies
		    purdue *en = new purdue ("purdue.png", 2 * WINDOW_WIDTH,
					     WINDOW_HEIGHT,
					     x);
		    enemies.push_back (en);
		    break;
		  }
		default:
		  {
		    // Creates a point to an enemy that will be stored in the vector: enemies
		    trojan *en =
		      new trojan ("trojanSpriteSheet.png", 2 * WINDOW_WIDTH,
				  WINDOW_HEIGHT, x);
		    enemies.push_back (en);
		    break;
		  }
		}
	    }

	  // keeps looping while user has not quit
	  while (quit == 0)
	    {

	      while (SDL_PollEvent (&event))	//if user has input something
		{
		  //checks that user hasn't "x'd" out
		  if (event.type == SDL_QUIT)
		    quit = 1;

		  //checks if user hit the 'q' button to quit
		  else if (event.type == SDL_KEYDOWN
			   && event.key.keysym.sym == SDLK_q)
		    quit = 1;

		  //takes in the user input and event into another function
		  else if (lep.keyInput (floor) == 1)
		    return 0;
		}



	      // Moves leprechaun based on user input from previous loop
	      lep.move (floor);

		//checks for the leprechaun falling through a gap, and if that happens
			//then lives are decremented and the level restarts or the game ends
	      if (lep.getyOffset () > WINDOW_HEIGHT)
		{
		  lives--;
		  if (lives > 0)
		    menuScreen.levelScreen (level, lives, window);
		  else
		    menuScreen.losingScreen (window);
		  dead = true;
		  globalScore = tempScore = lep.getScore ();
		  break;
		}

	      //updates the screen to reflect current moves made
	      window = lep.update (floor, infile);

		//POLYMORPHIC: goes through each enemy pointer and moves, updates and checks collide for enemies
	      for (int i = 0; i < enemies.size (); i++)
		{
		  // Move the ith enemy with respect ot the leprechaun's movement/position and the landscape
		  enemies[i]->move (lep.getxOffset (), lep.getxpos (), floor);

		  // Update the screen
		  window = enemies[i]->update (window);

		  // If the leprechaun killed an enemy: increases score
		  if (lep.enemyKill
		      (enemies[i]->getxpos (), enemies[i]->getypos (),enemies[i]->getWidth()))
		    {
		      lep.setScore (lep.getScore () +
				    enemies[i]->getScore ());
		      enemies.erase (enemies.begin () + i);
		      continue;
		    }

		  // If the leprechaun died: checks for enemies colliding with the player
		  else if (lep.enemyCollisionSide (enemies[i]->getxpos (),
						   enemies[i]->getypos (),enemies[i]->getHeight(),enemies[i]->getWidth()) ==1)
		    {
			  SDLSingleton::GetInstance()->DoRender();
		      SDL_Delay (50);
		      lep.deathAnimation (floor, infile, window, enemies); //if player dies, player jumps and falls
						//through the window and lives are decremented accordingly
		      lives--;

		      if (lives > 0)
			menuScreen.levelScreen (level, lives, window);
		      else
			menuScreen.losingScreen (window);
		      dead = true;
		      globalScore = tempScore=  lep.getScore ();
		      break;
		    }
		  else if (enemies[i]->getypos () > WINDOW_HEIGHT
			   || enemies[i]->getxpos () <= 0
			   || enemies[i]->getxpos () >= length) //checks for enemies going out of range of the 
					//window or have fallen through a gap 
		    {
		      enemies.erase (enemies.begin () + i);
		    }

		}


			
	      if (dead || quit) //checks that user has not died or quit 
		{
		  dead = false;
		  break;
		}
	    
		//puts flag at the end of the level
		  SDL_Surface *flag = load ("flag.png");
	          apply_image (flag, window, NULL,
			   lep.getxOffset () + (length - lep.getxpos ()),
			   WINDOW_HEIGHT - flag->h);

	      if (lep.endLevel (length, floor, window, infile) == 1
		  && level < NUMBER_LEVELS) //checks if user has beat level and is not at the end of the game 
		{
		  menuScreen.advancingScreen (window);
		  globalScore = lep.getScore ();
		  level++;
		  stringstream outstring; //intializes streams
	          outstring << level << ".txt"; //sets level stream
		  infile.open ((outstring.str()).c_str());
		  break;
		}
	      else if (lep.endLevel (length, floor, window, infile) == 1
		       && level == NUMBER_LEVELS) //checks if user is at the end of the game and has won level
		{
		  menuScreen.winningScreen (window);
		  level++;
		  stringstream outstring; //intializes streams
	          outstring << level << ".txt"; //sets level stream
		  infile.open ((outstring.str()).c_str());
		  break;
		}

	      menuScreen.gameNumbers (lives, lep.getScore (), window); //applies scores to the window
		  SDLSingleton::GetInstance()->DoRender();
	      SDL_Delay (50); //delays 


	//when score increases by 500, increase lives by one
	  if (lep.getScore() >= tempScore+500)
	    {
	      lives++;
	      tempScore = lep.getScore();
	    }
	    }
	
	//end game
	  enemies.clear (); //clears all enemy pointers
	  infile.close (); //closes text file
	}
    }

  //Cleanup: frees the SDL_Surface and exits all SDL libraries
  SDL_FreeSurface (window);
  SDL_Quit ();


  //returns 0 to show successful program ending
  return 0;
}
