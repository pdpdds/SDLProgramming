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
#include "config.h"
#include "episodes.h"
#include "file.h"
#include "lvllib.h"
#include "lvlmast.h"
#include "opentyr.h"


/* MAIN Weapons Data */
JE_WeaponPortType weaponPort;
JE_WeaponType     weapons;

/* Items */
JE_PowerType   powerSys;
JE_ShipType    ships;
JE_OptionType  options[OPTION_NUM + 1]; /* [0..optionnum] */
JE_ShieldType  shields;
JE_SpecialType special;

/* Enemy data */
JE_EnemyDatType enemyDat;

/* EPISODE variables */
JE_byte    initial_episode_num, episodeNum = 0;
JE_boolean episodeAvail[EPISODE_MAX]; /* [1..episodemax] */
char       episode_file[13], cube_file[13];

JE_longint episode1DataLoc;

/* Tells the game whether the level currently loaded is a bonus level. */
JE_boolean bonusLevel;

/* Tells if the game jumped back to Episode 1 */
JE_boolean jumpBackToEpisode1;

void JE_loadItemDat( void )
{
	SDL_RWops *f = NULL;
	
	if (episodeNum <= 3)
	{
		f = dir_fopen_die(data_dir(), "tyrian.hdt", "rb");
		efread(f, &episode1DataLoc, sizeof(JE_longint), 1);
		efseek(f, episode1DataLoc, SEEK_SET);
	}
	else
	{
		// episode 4 stores item data in the level file
		f = dir_fopen_die(data_dir(), levelFile, "rb");
		efseek(f, lvlPos[lvlNum-1], SEEK_SET);
	}

	JE_word itemNum[7]; /* [1..7] */
	efread(f, &itemNum, sizeof(JE_word), 7);

	for (int i = 0; i < WEAP_NUM + 1; ++i)
	{
		efread(f, &weapons[i].drain,           sizeof(JE_word), 1);
		efread(f, &weapons[i].shotrepeat, sizeof(JE_byte), 1);
		efread(f, &weapons[i].multi, sizeof(JE_byte), 1);
		efread(f, &weapons[i].weapani, sizeof(JE_word), 1);
		efread(f, &weapons[i].max, sizeof(JE_byte), 1);
		efread(f, &weapons[i].tx, sizeof(JE_byte), 1);
		efread(f, &weapons[i].ty, sizeof(JE_byte), 1);
		efread(f, &weapons[i].aim, sizeof(JE_byte), 1);
		efread(f, &weapons[i].attack, sizeof(JE_byte), 8);
		efread(f, &weapons[i].del, sizeof(JE_byte), 8);
		efread(f, &weapons[i].sx, sizeof(JE_shortint), 8);
		efread(f, &weapons[i].sy, sizeof(JE_shortint), 8);
		efread(f, &weapons[i].bx, sizeof(JE_shortint), 8);
		efread(f, &weapons[i].by, sizeof(JE_shortint), 8);
		efread(f, &weapons[i].sg, sizeof(JE_word), 8);
		efread(f, &weapons[i].acceleration, sizeof(JE_shortint), 1);
		efread(f, &weapons[i].accelerationx, sizeof(JE_shortint), 1);
		efread(f, &weapons[i].circlesize,      sizeof(JE_byte), 1);
		efread(f, &weapons[i].sound, sizeof(JE_byte), 1);
		efread(f, &weapons[i].trail, sizeof(JE_byte), 1);
		efread(f, &weapons[i].shipblastfilter, sizeof(JE_byte), 1);
	}

	for (int i = 0; i < PORT_NUM + 1; ++i)
	{
		efseek(f, 1, SEEK_CUR); /* skip string length */
		efread(f, &weaponPort[i].name, 1, 30);
		weaponPort[i].name[30] = '\0';
		efread(f, &weaponPort[i].opnum, sizeof(JE_byte), 1);
		for (int j = 0; j < 2; ++j)
		{
			efread(f, &weaponPort[i].op[j], sizeof(JE_word), 11);
		}
		efread(f, &weaponPort[i].cost, sizeof(JE_word), 1);
		efread(f, &weaponPort[i].itemgraphic, sizeof(JE_word), 1);
		efread(f, &weaponPort[i].poweruse, sizeof(JE_word), 1);
	}

	for (int i = 0; i < SPECIAL_NUM + 1; ++i)
	{
		efseek(f, 1, SEEK_CUR); /* skip string length */
		efread(f, &special[i].name, 1, 30);
		special[i].name[30] = '\0';
		efread(f, &special[i].itemgraphic, sizeof(JE_word), 1);
		efread(f, &special[i].pwr, sizeof(JE_byte), 1);
		efread(f, &special[i].stype, sizeof(JE_byte), 1);
		efread(f, &special[i].wpn, sizeof(JE_word), 1);
	}
	
	for (int i = 0; i < POWER_NUM + 1; ++i)
	{
		efseek(f, 1, SEEK_CUR); /* skip string length */
		efread(f, &powerSys[i].name, 1, 30);
		powerSys[i].name[30] = '\0';
		efread(f, &powerSys[i].itemgraphic, sizeof(JE_word), 1);
		efread(f, &powerSys[i].power, sizeof(JE_shortint), 1);
		efread(f, &powerSys[i].speed, sizeof(JE_byte), 1);
		efread(f, &powerSys[i].cost, sizeof(JE_word), 1);
	}
	
	for (int i = 0; i < SHIP_NUM + 1; ++i)
	{
		efseek(f, 1, SEEK_CUR); /* skip string length */
		efread(f, &ships[i].name, 1, 30);
		ships[i].name[30] = '\0';
		efread(f, &ships[i].shipgraphic, sizeof(JE_word), 1);
		efread(f, &ships[i].itemgraphic, sizeof(JE_word), 1);
		efread(f, &ships[i].ani, sizeof(JE_byte), 1);
		efread(f, &ships[i].spd, sizeof(JE_shortint), 1);
		efread(f, &ships[i].dmg, sizeof(JE_byte), 1);
		efread(f, &ships[i].cost, sizeof(JE_word), 1);
		efread(f, &ships[i].bigshipgraphic, sizeof(JE_byte), 1);
	}
	
	for (int i = 0; i < OPTION_NUM + 1; ++i)
	{
		efseek(f, 1, SEEK_CUR); /* skip string length */
		efread(f, &options[i].name, 1, 30);
		options[i].name[30] = '\0';
		efread(f, &options[i].pwr, sizeof(JE_byte), 1);
		efread(f, &options[i].itemgraphic, sizeof(JE_word), 1);
		efread(f, &options[i].cost, sizeof(JE_word), 1);
		efread(f, &options[i].tr, sizeof(JE_byte), 1);
		efread(f, &options[i].option, sizeof(JE_byte), 1);
		efread(f, &options[i].opspd, sizeof(JE_shortint), 1);
		efread(f, &options[i].ani, sizeof(JE_byte), 1);
		efread(f, &options[i].gr, sizeof(JE_word), 20);
		efread(f, &options[i].wport, sizeof(JE_byte), 1);
		efread(f, &options[i].wpnum, sizeof(JE_word), 1);
		efread(f, &options[i].ammo, sizeof(JE_byte), 1);
		efread(f, &options[i].stop, 1, 1); /* override sizeof(JE_boolean) */
		efread(f, &options[i].icongr, sizeof(JE_byte), 1);
	}
	
	for (int i = 0; i < SHIELD_NUM + 1; ++i)
	{
		efseek(f, 1, SEEK_CUR); /* skip string length */
		efread(f, &shields[i].name, 1, 30);
		shields[i].name[30] = '\0';
		efread(f, &shields[i].tpwr, sizeof(JE_byte), 1);
		efread(f, &shields[i].mpwr, sizeof(JE_byte), 1);
		efread(f, &shields[i].itemgraphic, sizeof(JE_word), 1);
		efread(f, &shields[i].cost, sizeof(JE_word), 1);
	}
	
	for (int i = 0; i < ENEMY_NUM + 1; ++i)
	{
		efread(f, &enemyDat[i].ani, sizeof(JE_byte), 1);
		efread(f, &enemyDat[i].tur, sizeof(JE_byte), 3);
		efread(f, &enemyDat[i].freq, sizeof(JE_byte), 3);
		efread(f, &enemyDat[i].xmove, sizeof(JE_shortint), 1);
		efread(f, &enemyDat[i].ymove, sizeof(JE_shortint), 1);
		efread(f, &enemyDat[i].xaccel, sizeof(JE_shortint), 1);
		efread(f, &enemyDat[i].yaccel, sizeof(JE_shortint), 1);
		efread(f, &enemyDat[i].xcaccel, sizeof(JE_shortint), 1);
		efread(f, &enemyDat[i].ycaccel, sizeof(JE_shortint), 1);
		efread(f, &enemyDat[i].startx, sizeof(JE_integer), 1);
		efread(f, &enemyDat[i].starty, sizeof(JE_integer), 1);
		efread(f, &enemyDat[i].startxc, sizeof(JE_shortint), 1);
		efread(f, &enemyDat[i].startyc, sizeof(JE_shortint), 1);
		efread(f, &enemyDat[i].armor, sizeof(JE_byte), 1);
		efread(f, &enemyDat[i].esize, sizeof(JE_byte), 1);
		efread(f, &enemyDat[i].egraphic, sizeof(JE_word), 20);
		efread(f, &enemyDat[i].explosiontype, sizeof(JE_byte), 1);
		efread(f, &enemyDat[i].animate, sizeof(JE_byte), 1);
		efread(f, &enemyDat[i].shapebank, sizeof(JE_byte), 1);
		efread(f, &enemyDat[i].xrev, sizeof(JE_shortint), 1);
		efread(f, &enemyDat[i].yrev, sizeof(JE_shortint), 1);
		efread(f, &enemyDat[i].dgr, sizeof(JE_word), 1);
		efread(f, &enemyDat[i].dlevel, sizeof(JE_shortint), 1);
		efread(f, &enemyDat[i].dani, sizeof(JE_shortint), 1);
		efread(f, &enemyDat[i].elaunchfreq, sizeof(JE_byte), 1);
		efread(f, &enemyDat[i].elaunchtype, sizeof(JE_word), 1);
		efread(f, &enemyDat[i].value, sizeof(JE_integer), 1);
		efread(f, &enemyDat[i].eenemydie, sizeof(JE_word), 1);
	}
	
	efclose(f);
}

void JE_initEpisode( JE_byte newEpisode )
{
	if (newEpisode == episodeNum)
		return;
	
	episodeNum = newEpisode;
	
	sprintf(levelFile,    "tyrian%d.lvl",  episodeNum);
	sprintf(cube_file,    "cubetxt%d.dat", episodeNum);
	sprintf(episode_file, "levels%d.dat",  episodeNum);
	
	JE_analyzeLevel();
	JE_loadItemDat();
}

void JE_scanForEpisodes( void )
{
	for (int i = 0; i < EPISODE_MAX; ++i)
	{
		char ep_file[20];
		snprintf(ep_file, sizeof(ep_file), "tyrian%d.lvl", i + 1);
		episodeAvail[i] = dir_file_exists(data_dir(), ep_file);
	}
}

unsigned int JE_findNextEpisode( void )
{
	unsigned int newEpisode = episodeNum;
	
	jumpBackToEpisode1 = false;
	
	while (true)
	{
		newEpisode++;
		
		if (newEpisode > EPISODE_MAX)
		{
			newEpisode = 1;
			jumpBackToEpisode1 = true;
			gameHasRepeated = true;
		}
		
		if (episodeAvail[newEpisode-1] || newEpisode == episodeNum)
		{
			break;
		}
	}
	
	return newEpisode;
}

// kate: tab-width 4; vim: set noet:
