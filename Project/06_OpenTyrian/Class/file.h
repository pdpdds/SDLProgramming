/* 
 * OpenTyrian Classic: A modern cross-platform port of Tyrian
 * Copyright (C) 2007-2009  The OpenTyrian Development Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#ifndef FILE_H
#define FILE_H

#include <SDL2/SDL_endian.h>
#include <stdbool.h>
#include <stdio.h>
#include <SDL2/SDL.h>
extern const char *custom_data_dir;

#ifdef TARGET_MACOSX
const char *tyrian_game_folder();
#endif // TARGET_MACOSX

const char *data_dir( void );

SDL_RWops *dir_fopen(const char *dir, const char *file, const char *mode);
SDL_RWops *dir_fopen_warn(const char *dir, const char *file, const char *mode);
SDL_RWops *dir_fopen_die(const char *dir, const char *file, const char *mode);

bool dir_file_exists( const char *dir, const char *file );

long ftell_eof(SDL_RWops *f);
int SDL_RWputc(int _Ch, SDL_RWops * f);
int SDL_RWgetc(SDL_RWops * f);
int SDL_RWeof(SDL_RWops * f);
int SDL_RWputs(const char *s, SDL_RWops *stream);

// endian-swapping fread/fwrite
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
size_t efread( void *buffer, size_t size, size_t num, SDL_RWops *stream );
size_t efwrite( void *buffer, size_t size, size_t num, SDL_RWops *stream );
#else
#define efread SDL_RWread
#define efwrite SDL_RWwrite
#define efputc SDL_RWputc
#define efgetc SDL_RWgetc
#define efclose SDL_RWclose
#define efseek SDL_RWseek
#define eftell SDL_RWtell
#define egetc SDL_RWgetc
#define efeof SDL_RWeof
#define efputs SDL_RWputs
#endif

#endif // FILE_H

// kate: tab-width 4; vim: set noet:
