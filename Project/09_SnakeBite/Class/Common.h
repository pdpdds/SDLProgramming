#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
#include <time.h>
#include <string>

void DrawSurface(SDL_Surface *dst, int x, int y, SDL_Surface *src);
int BaseRand(int x, int y);