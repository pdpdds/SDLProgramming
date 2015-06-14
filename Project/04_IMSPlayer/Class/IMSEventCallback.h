#pragma once
#include "IMSLibrary/IIMSEventCallback.h"
#include "BaseLib/TinyThread++1.1/source/tinythread.h"

class IMSManager;
class LyricsManager;

class IMSEventCallback : public IIMSEventCallback
{
public:
	IMSEventCallback(void);
	virtual ~IMSEventCallback(void);

	virtual void CallbackLyrics(char* lyrics);
	virtual void CallbackPlayEnd() ;
	virtual void Reset();

	void SetIMSManager(IMSManager* pManager){ m_pIMSManager = pManager; }
	bool IsLyricsUpdate(std::string& message1, std::string&  message2);


private:
	tthread::mutex m_mutex;
	IMSManager* m_pIMSManager;
	LyricsManager* m_pLyricsManager;
};

