/*************************************************************************** 
  alienBlaster 
  Copyright (C) 2004 
  Paul Grathwohl, Arne Hormann, Daniel Kuehn, Soenke Schwardt

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2, or (at your option)
  any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
***************************************************************************/
using namespace std;

#include "soundDB.h"
#include "SDL_mixer.h"
#ifdef ANDROID
#include <android/log.h>
#endif
#include <iostream>

SoundDB::SoundDB() {}

SoundDB::~SoundDB() {
  StringSoundMap::iterator pos;
  // free all Mix_Chunks
  for ( pos = soundDB.begin(); pos != soundDB.end(); ++pos ) {
    Mix_FreeChunk( pos->second );
  }
}

Mix_Chunk *SoundDB::loadWav( string fn ) {
  Mix_Chunk *searchResult = getWav( fn );
  if ( searchResult ) {
    return searchResult;
  }

  string fn1 = fn;
  // Check if file exist
  SDL_RWops * inputFile = SDL_RWFromFile(fn1.c_str(), "rb");
  if (!inputFile) {
    if( fn1.size() > 4 && fn1.find(".wav") != string::npos ) {
      fn1 = fn1.substr( 0, fn1.size() - 4 ) + ".ogg";
	  inputFile = SDL_RWFromFile(fn1.c_str(), "rb");
    }
    if (!inputFile) {
      cout << "ERROR: file " << fn1 << " does not exist!" << endl;

      exit(1);
    }
  }
  SDL_RWclose(inputFile);

  // TODO: error-handling
  Mix_Chunk *newSound = Mix_LoadWAV( fn1.c_str() );
  if( !newSound ) {
    cout << "ERROR: file " << fn1 << " cannot be loaded!" << endl;

    exit(1);
  }
  soundDB[ fn ] = newSound;
  return newSound;
}

Mix_Chunk *SoundDB::getWav( string fn ) {
  if ( soundDB.empty() ) {
    return 0;
  } else {
    StringSoundMap::iterator pos = soundDB.find( fn );
    if ( pos == soundDB.end() ) {
      return 0;
    } else {
      return pos->second;
    }
  }
}

