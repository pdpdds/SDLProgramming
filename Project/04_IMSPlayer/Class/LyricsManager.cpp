//#include "stdafx.h"
#include "LyricsManager.h"


using namespace std;

LyricsManager::LyricsManager(void)
{
	m_isUpdate = false;
}


LyricsManager::~LyricsManager(void)
{
}

bool LyricsManager::AddText(char* szText)
{
	if (strlen(szText) == 0)
		return false;

	m_szOldLyrics = m_szLyrics;
	m_szLyrics = szText;
	m_isUpdate = true;
	return true;
}

bool LyricsManager::InitText()
{
	m_szLyrics.clear();
	m_szOldLyrics.clear();
	return true;
}



