#pragma once
#include <map>
#include <string>

class LyricsManager
{
public:
	LyricsManager(void);
	virtual ~LyricsManager(void);

	bool AddText(char* szText);
	bool InitText();
	

protected:

public:
	bool m_isUpdate;
	std::string m_szOldLyrics;
	std::string m_szLyrics;
};

