// SDLTweakBar.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <AntTweakBar.h>
#include <SDL.h>
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include <windows.h>

#include <GL/gl.h>
#include <GL/glu.h>

int _tmain(int argc, _TCHAR* argv[])
{
	int width = 640, height = 480;
	int bpp, flags;
	int quit = 0;
	TwBar *bar;
	int n, numCubes = 30;
	float color0[] = { 1.0f, 0.5f, 0.0f };
	float color1[] = { 0.5f, 1.0f, 0.0f };
	double ka = 5.3, kb = 1.7, kc = 4.1;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 0;
	}

	SDL_Window *pWindow;
	SDL_GLContext MainContext;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return 0;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

	// 24bit double buffer
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	pWindow = SDL_CreateWindow("SDL AntTweakBar", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		640, 480, SDL_WINDOW_OPENGL | SDL_WINDOW_HIDDEN);// | SDL_WINDOW_RESIZABLE);
	if (!pWindow) {
		return 0;
	}

	// Attach the OpenGL context to our window

	MainContext = SDL_GL_CreateContext(pWindow);

	SDL_ShowWindow(pWindow);

	// Enable vsync
	SDL_GL_SetSwapInterval(1);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	//SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	
	// Set OpenGL viewport and states
	glViewport(0, 0, width, height);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0); // use default light diffuse and position
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glDisable(GL_CULL_FACE);
	glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);

	// Initialize AntTweakBar
	TwInit(TW_OPENGL, NULL);

	// Tell the window size to AntTweakBar
	TwWindowSize(width, height);

	// Create a tweak bar
	bar = TwNewBar("TweakBar");
	TwDefine(" GLOBAL help='This example shows how to integrate AntTweakBar with SDL and OpenGL.\nPress [Space] to toggle fullscreen.' "); // Message added to the help bar.

	// Add 'width' and 'height' to 'bar': they are read-only (RO) variables of type TW_TYPE_INT32.
	TwAddVarRO(bar, "Width", TW_TYPE_INT32, &width,
		" label='Wnd width' help='Width of the graphics window (in pixels)' ");

	TwAddVarRO(bar, "Height", TW_TYPE_INT32, &height,
		" label='Wnd height' help='Height of the graphics window (in pixels)' ");

	// Add 'numCurves' to 'bar': this is a modifiable variable of type TW_TYPE_INT32. Its shortcuts are [c] and [C].
	TwAddVarRW(bar, "NumCubes", TW_TYPE_INT32, &numCubes,
		" label='Number of cubes' min=1 max=100 keyIncr=c keyDecr=C help='Defines the number of cubes in the scene.' ");

	// Add 'ka', 'kb and 'kc' to 'bar': they are modifiable variables of type TW_TYPE_DOUBLE
	TwAddVarRW(bar, "ka", TW_TYPE_DOUBLE, &ka,
		" label='X path coeff' keyIncr=1 keyDecr=CTRL+1 min=-10 max=10 step=0.01 ");
	TwAddVarRW(bar, "kb", TW_TYPE_DOUBLE, &kb,
		" label='Y path coeff' keyIncr=2 keyDecr=CTRL+2 min=-10 max=10 step=0.01 ");
	TwAddVarRW(bar, "kc", TW_TYPE_DOUBLE, &kc,
		" label='Z path coeff' keyIncr=3 keyDecr=CTRL+3 min=-10 max=10 step=0.01 ");

	// Add 'color0' and 'color1' to 'bar': they are modifable variables of type TW_TYPE_COLOR3F (3 floats color)
	TwAddVarRW(bar, "color0", TW_TYPE_COLOR3F, &color0,
		" label='Start color' help='Color of the first cube.' ");
	TwAddVarRW(bar, "color1", TW_TYPE_COLOR3F, &color1,
		" label='End color' help='Color of the last cube. Cube colors are interpolated between the Start and End colors.' ");

	// Add 'quit' to 'bar': this is a modifiable (RW) variable of type TW_TYPE_BOOL32 
	// (a boolean stored in a 32 bits integer). Its shortcut is [ESC].
	TwAddVarRW(bar, "Quit", TW_TYPE_BOOL32, &quit,
		" label='Quit?' true='+' false='-' key='ESC' help='Quit program.' ");

	// Main loop:
	// - Draw some cubes
	// - Process events
	while (!quit)
	{
		SDL_Event event;
		int handled;

		// Clear screen
		glClearColor(0.5f, 0.75f, 0.8f, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Set OpenGL camera
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(40, (double)width / height, 1, 10);
		gluLookAt(0, 0, 3, 0, 0, 0, 0, 1, 0);

		// Draw cubes
		for (n = 0; n<numCubes; ++n)
		{
			double t = 0.05*n - (double)SDL_GetTicks() / 2000.0;
			double r = 5.0*n + (double)SDL_GetTicks() / 10.0;
			float c = (float)n / numCubes;

			// Set cube position
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glTranslated(0.6*cos(ka*t), 0.6*cos(kb*t), 0.6*sin(kc*t));
			glRotated(r, 0.2, 0.7, 0.2);
			glScaled(0.1, 0.1, 0.1);
			glTranslated(-0.5, -0.5, -0.5);

			// Set cube color
			glColor3f((1.0f - c)*color0[0] + c*color1[0], (1.0f - c)*color0[1] + c*color1[1], (1.0f - c)*color0[2] + c*color1[2]);

			// Draw cube
			glBegin(GL_QUADS);
			glNormal3f(0, 0, -1); glVertex3f(0, 0, 0); glVertex3f(0, 1, 0); glVertex3f(1, 1, 0); glVertex3f(1, 0, 0); // front face
			glNormal3f(0, 0, +1); glVertex3f(0, 0, 1); glVertex3f(1, 0, 1); glVertex3f(1, 1, 1); glVertex3f(0, 1, 1); // back face
			glNormal3f(-1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(0, 0, 1); glVertex3f(0, 1, 1); glVertex3f(0, 1, 0); // left face
			glNormal3f(+1, 0, 0); glVertex3f(1, 0, 0); glVertex3f(1, 1, 0); glVertex3f(1, 1, 1); glVertex3f(1, 0, 1); // right face
			glNormal3f(0, -1, 0); glVertex3f(0, 0, 0); glVertex3f(1, 0, 0); glVertex3f(1, 0, 1); glVertex3f(0, 0, 1); // bottom face  
			glNormal3f(0, +1, 0); glVertex3f(0, 1, 0); glVertex3f(0, 1, 1); glVertex3f(1, 1, 1); glVertex3f(1, 1, 0); // top face
			glEnd();
		}

		// Draw tweak bars
		TwDraw();

		// Present frame buffer
		SDL_GL_SwapWindow(pWindow);

		// Process incoming events
		while (SDL_PollEvent(&event))
		{
			// Send event to AntTweakBar
			handled = TwEventSDL(&event, SDL_MAJOR_VERSION, SDL_MINOR_VERSION);

			// If event has not been handled by AntTweakBar, process it
			if (!handled)
			{
				switch (event.type)
				{
				case SDL_QUIT:  // Window is closed
					quit = 1;
					break;
				/*case SDL_WINDOWEVENT:
				{
										if (event.window.type == SDL_WINDOWEVENT_RESIZED)
										{
											// Resize SDL video mode
											
											SDL_GL_GetDrawableSize(pWindow, &width, &height);

											// Resize OpenGL viewport
											glViewport(0, 0, width, height);

											// Restore OpenGL states (SDL seems to lost them)
											glEnable(GL_DEPTH_TEST);
											glEnable(GL_LIGHTING);
											glEnable(GL_LIGHT0);
											glEnable(GL_NORMALIZE);
											glEnable(GL_COLOR_MATERIAL);
											glDisable(GL_CULL_FACE);
											glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);

											// TwWindowSize has been called by TwEventSDL, 
											// so it is not necessary to call it again here.
										}
				}
				
					break;*/

				/*case SDL_KEYDOWN:
					if (event.key.keysym.sym == ' ') // toggle fullscreen if Space key is pressed
					{
						flags ^= SDL_FULLSCREEN;
						SDL_SetVideoMode(800, 600, bpp, flags);

						// Push a resize event because SDL does not do it for us
						event.type = SDL_VIDEORESIZE;
						event.resize.w = 800;
						event.resize.h = 600;
						SDL_PushEvent(&event);
					}
					break;*/
				}
			}
		}
	} // End of main loop

	// Terminate AntTweakBar
	TwTerminate();

	// Terminate SDL
	SDL_Quit();

	return 0;
}


