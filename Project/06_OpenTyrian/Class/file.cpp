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
#include "file.h"
#include "opentyr.h"

#include "SDL.h"
#include <errno.h>

#ifdef _WIN32
#include <memory.h>
#include <string.h>
#endif

const char *custom_data_dir = ".";

// finds the Tyrian data directory
const char *data_dir( void )
{
	const char *dirs[] =
	{
		custom_data_dir,
		"data",
#ifdef TARGET_MACOSX
		tyrian_game_folder(),
#endif
		"/usr/share/opentyrian/data"
	};
	
	static const char *dir = NULL;
	
	if (dir != NULL)
		return dir;
	
	for (uint i = 0; i < COUNTOF(dirs); ++i)
	{
		SDL_RWops *f = dir_fopen(dirs[i], "tyrian1.lvl", "rb");
		if (f)
		{
			SDL_RWclose(f);
			
			dir = dirs[i];
			break;
		}
	}
	
	if (dir == NULL) // data not found
		dir = "";
	
	return dir;
}

// prepend directory and fopen
SDL_RWops *dir_fopen(const char *dir, const char *file, const char *mode)
{
	char *path = (char *)malloc(strlen(dir) + 1 + strlen(file) + 1);
	sprintf(path, "%s/%s", dir, file);
	
	SDL_RWops *f = SDL_RWFromFile(path, mode);
	
	free(path);
	
	return f;
}

// warn when dir_fopen fails
SDL_RWops *dir_fopen_warn(const char *dir, const char *file, const char *mode)
{
	errno = 0;
	
	SDL_RWops *f = dir_fopen(dir, file, mode);
	
	if (!f)
		fprintf(stderr, "warning: failed to open '%s': %s\n", file, strerror(errno));
	
	return f;
}

// die when dir_fopen fails
SDL_RWops *dir_fopen_die(const char *dir, const char *file, const char *mode)
{
	errno = 0;
	
	SDL_RWops *f = dir_fopen(dir, file, mode);
	
	if (f == NULL)
	{
		fprintf(stderr, "error: failed to open '%s': %s\n", file, strerror(errno));
		fprintf(stderr, "error: One or more of the required Tyrian 2.1 data files could not be found.\n"
		                "       Please read the README file.\n");
		exit(1);
	}
	
	return f;
}

// check if file can be opened for reading
bool dir_file_exists( const char *dir, const char *file )
{
	SDL_RWops *f = dir_fopen(dir, file, "rb");
	if (f != NULL)
		SDL_RWclose(f);
	return (f != NULL);
}

// returns end-of-file position
long ftell_eof(SDL_RWops *f)
{
	long pos = SDL_RWtell(f);
	
	SDL_RWseek(f, 0, SEEK_END);
	long size = SDL_RWtell(f);
	
	SDL_RWseek(f, pos, SEEK_SET);
	
	return size;
}

int SDL_RWputc(int _Ch, SDL_RWops * f)
{
	char cc = (char)_Ch; /* Bytesex */
	if (1 != SDL_RWwrite(f, &cc, sizeof(char), 1))
		return -1;

	return (int)_Ch;
}


int SDL_RWeof(SDL_RWops * f)
{
	long endSize = ftell_eof(f);
	return (SDL_RWtell(f) == endSize);
}


int SDL_RWgetc(SDL_RWops * f)
{
	unsigned char c;

	c = (unsigned char)-1;
	if (1 != efread(f,&c, sizeof(char), 1))
		return -1;

	return (int)c;
}

int SDL_RWputs(const char *s, SDL_RWops *stream)
{
	int len;

	len = strlen(s) * sizeof(char);

	if (1 != SDL_RWwrite(stream, s, len, 1))
		return -1;

	return 0;
}

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
// endian-swapping fread
size_t efread( void *buffer, size_t size, size_t num, SDL_RWops *stream )
{
	size_t f = fread(buffer, size, num, stream);
	
	switch (size)
	{
		case 2:
			for (size_t i = 0; i < num; i++)
				((Uint16 *)buffer)[i] = SDL_Swap16(((Uint16 *)buffer)[i]);
			break;
		case 4:
			for (size_t i = 0; i < num; i++)
				((Uint32 *)buffer)[i] = SDL_Swap32(((Uint32 *)buffer)[i]);
			break;
		case 8:
			for (size_t i = 0; i < num; i++)
				((Uint64 *)buffer)[i] = SDL_Swap64(((Uint64 *)buffer)[i]);
			break;
		default:
			break;
	}
	
	return f;
}

// endian-swapping fwrite
size_t efwrite( void *buffer, size_t size, size_t num, SDL_RWops *stream )
{
	void *swap_buffer;
	
	switch (size)
	{
		case 2:
			swap_buffer = malloc(size * num);
			for (size_t i = 0; i < num; i++)
				((Uint16 *)swap_buffer)[i] = SDL_SwapLE16(((Uint16 *)buffer)[i]);
			break;
		case 4:
			swap_buffer = malloc(size * num);
			for (size_t i = 0; i < num; i++)
				((Uint32 *)swap_buffer)[i] = SDL_SwapLE32(((Uint32 *)buffer)[i]);
			break;
		case 8:
			swap_buffer = malloc(size * num);
			for (size_t i = 0; i < num; i++)
				((Uint64 *)swap_buffer)[i] = SDL_SwapLE64(((Uint64 *)buffer)[i]);
			break;
		default:
			swap_buffer = buffer;
			break;
	}
	
	size_t f = fwrite(swap_buffer, size, num, stream);
	
	if (swap_buffer != buffer)
		free(swap_buffer);
	
	return f;
}
#endif

// kate: tab-width 4; vim: set noet:
