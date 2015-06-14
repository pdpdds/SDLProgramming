
#include "IMSEventCallback.h"
#include "IMSLibrary/IMSManager.h"
#include "LyricsManager.h"

#ifdef _WIN32
#include <BaseLib/Win32/iconv/iconv.h>
#else
#include <iconv.h>
#endif

IMSEventCallback::IMSEventCallback(void)
{
	m_pLyricsManager = new LyricsManager();
}


IMSEventCallback::~IMSEventCallback(void)
{
}

void IMSEventCallback::CallbackLyrics(char* lyrics)
{
	int err = 0;
	char buf[1024];
	memset(buf, 0, 1024);
	char *output_buf_ptr = buf;
	int ret;

	wchar_t wszLyrics[256];

	iconv_t cd = iconv_open("UTF-8", "JOHAB");

	char* pS = lyrics;
	size_t aa = strlen(lyrics);
	size_t nsLen = 1024;
	if (cd != (iconv_t)(-1))
		iconv(cd, &pS, &aa, &output_buf_ptr, &nsLen);

	iconv_close(cd);

	m_mutex.lock();

	m_pLyricsManager->AddText(buf);

	m_mutex.unlock();
}

void IMSEventCallback::CallbackPlayEnd()
{
}

bool IMSEventCallback::IsLyricsUpdate(std::string& message1, std::string& message2)
{
	m_mutex.lock();

	if (m_pLyricsManager->m_isUpdate == false)
	{
		m_mutex.unlock();
		return false;
	}


	message1 = m_pLyricsManager->m_szOldLyrics;
	message2 = m_pLyricsManager->m_szLyrics;
	
	m_pLyricsManager->m_isUpdate = false;

	m_mutex.unlock();

	return true;
}

void IMSEventCallback::Reset()
{
	m_mutex.lock();

	m_pLyricsManager->m_szOldLyrics.clear();
	m_pLyricsManager->m_szLyrics.clear();
	
	m_pLyricsManager->m_isUpdate = true;

	m_mutex.unlock();
}