#include "WidgetsContainer.h"
#include "GUIManager.h"
#include "SDL_Mixer.h"
#include <fstream>

#ifdef _WIN32
#include <Windows.h>
#endif

bool read_text(const char* source_file, char** destination)
{
	// Open the file
	SDL_RWops *file;
	file = SDL_RWFromFile(source_file, "r");

	if (file == 0)
		return false;

	size_t file_length = SDL_RWseek(file, 0, SEEK_END);
	(*destination) = new char[file_length + 1];
	// Reset seek to beginning of file and read text
	SDL_RWseek(file, 0, SEEK_SET);
	int n_blocks = SDL_RWread(file, (*destination), 1, file_length);
	if (n_blocks <= 0)
	{

	}
	SDL_RWclose(file);

	(*destination)[file_length] = '\0';

	return true;
}

char * SDL_RWgets(char* s, int n, SDL_RWops* stream)
{
	char c;
	char * p = s;

	while (n > 1) {
		if (1 == SDL_RWread(stream, &c, sizeof(char), 1)) {
			*p++ = c;
			n--;
			if (c == '\n')
			{
				break;
			}
			continue;
		}

		/* error handling */
		if (SDL_RWseek(stream, 0, RW_SEEK_END) != -1 && (p != s))
			break;

		return 0;
	}

	if (n > 0)
		*p = (char)0;

	return s;
}

template<typename T>
inline T TrimStr_Generic(const T& Src, const T& c)
{
	int p2 = Src.find_last_not_of(c);
	if (p2 == T::npos) return T();
	int p1 = Src.find_first_not_of(c);
	if (p1 == T::npos) p1 = 0;
	return Src.substr(p1, (p2 - p1) + 1);
}

char* trim(char *source)
{
	std::string str(source);
	str = TrimStr_Generic<std::string>(str, "\r\n");
	str = TrimStr_Generic<std::string>(str, "\r");
	str = TrimStr_Generic<std::string>(str, "\n");
	str = TrimStr_Generic<std::string>(str, "\t");
	str = TrimStr_Generic<std::string>(str, " ");
#ifdef _WIN32
	strcpy_s(source, str.length() + 1, str.c_str());
#else
	strcpy(source, str.c_str());
#endif

	return source;
}

class MidiListModel : public gcn::ListModel
{
	std::map<int, std::string> m_mapMid;
public:
	int getNumberOfElements()
	{
		return m_mapMid.size();
	}


	int AddIMSList()
	{
#ifdef _WIN32
		HANDLE File_Hwnd;
		WIN32_FIND_DATAA wfd;

		std::wofstream outFile("midifile.list", std::ios::app);

		if (!outFile.good())
		{
			return NULL;
		}

		BOOL bResult = TRUE;

		File_Hwnd = FindFirstFileA(".\\assets\\*.mid", &wfd);
		if (((DWORD)(File_Hwnd)) == 0xffffffff)
			bResult = FALSE;
		else bResult = TRUE;

		int index = 0;
		while (bResult)
		{
			if ((FILE_ATTRIBUTE_DIRECTORY & wfd.dwFileAttributes) == 0)
			{
			
				m_mapMid.insert(std::make_pair(index, wfd.cFileName));
				index++;

				outFile << wfd.cFileName << '\n';
			}

			bResult = FindNextFileA(File_Hwnd, &wfd);
		}
		FindClose(File_Hwnd);
		outFile.close();
#else
		SDL_RWops* fp = 0;
		fp = SDL_RWFromFile("assets/midifile.list", "rb");

		if (fp == 0)
			return false;

		char tmp[256] = { 0, };
		int index = 0;
		while (SDL_RWgets(tmp, sizeof(tmp), fp))
		{
			
			trim(tmp);
			std::string str = tmp;
			m_mapMid.insert(std::make_pair(index, str.c_str()));
			index++;
		}
		SDL_RWclose(fp);
#endif
		return true;
	}


	std::string getElementAt(int i)
	{
		std::map<int, std::string>::iterator iter = m_mapMid.find(i);
		if(iter != m_mapMid.end())
			return iter->second;
		return std::string("");
	}
};

MidiListModel midiListModel;

bool g_bPlayEnd = false;
void musicDone();

class ListBoxScrollListener : public gcn::ActionListener
{
public:
	// Implement the action function in ActionListener to recieve actions
	// The eventId tells us which widget called the action function.
	ListBoxScrollListener(WidgetsContainer* pWidgetsContainer)
	{
		m_pWidgetsContainer = pWidgetsContainer;
		m_pMusic = 0;
		m_bMusicPlaying = false;
		m_selected = 0;
		
	}

	bool isMusicPlaying()
	{
		if (m_pMusic != NULL && m_bMusicPlaying == true)
			return true;

		return false;
	}

	void AutoPlay()
	{
		if (g_bPlayEnd == true)
		{
			g_bPlayEnd = false;

			m_selected++;
			if (m_selected >= midiListModel.getNumberOfElements())
			{
				m_selected = 0;
			}

			std::string szMidFile = "assets/";
			szMidFile += m_pWidgetsContainer->m_pListBox->getListModel()->getElementAt(m_selected);

			if (m_pMusic)
			{
				Mix_HaltMusic();
				Mix_FreeMusic(m_pMusic);
				m_pMusic = 0;
			}

			m_pMusic = Mix_LoadMUS(szMidFile.c_str());

			if (m_pMusic == 0)
			{
				return;
			}
			
			Mix_PlayMusic(m_pMusic, 1); //Music loop=1
			m_bMusicPlaying = true;
			

		}
	}

	void action(const gcn::ActionEvent& actionEvent)
	{
		g_bPlayEnd = false;
		Mix_HookMusicFinished(0);
		std::string str;


		// Here we use the widget pointer to check which widget the action
		// originated from.
		if (actionEvent.getSource() == m_pWidgetsContainer->m_pListBoxScrollArea)
		{
			
		}
		if (actionEvent.getSource() == m_pWidgetsContainer->m_pListBox)
		{
			int selected = m_pWidgetsContainer->m_pListBox->getSelected();
			m_selected = selected;
			std::string szMidFile = "assets/";
			szMidFile += m_pWidgetsContainer->m_pListBox->getListModel()->getElementAt(selected);

			if (m_pMusic)
			{
				Mix_HaltMusic();
				Mix_FreeMusic(m_pMusic);
				m_pMusic = 0;
			}
			
			m_pMusic = Mix_LoadMUS(szMidFile.c_str());

			if (m_pMusic == 0)
			{				
				return;
			}			

			Mix_PlayMusic(m_pMusic, 1); //Music loop=1
			Mix_HookMusicFinished(musicDone);
			m_bMusicPlaying = true;
			
			
		}
	}

	WidgetsContainer* m_pWidgetsContainer;
	Mix_Music* m_pMusic;
	bool m_bMusicPlaying;
	int m_selected;
	
};

WidgetsContainer::WidgetsContainer(GUIManager* pManager)
: m_pManager(pManager)
{
}


WidgetsContainer::~WidgetsContainer()
{
	delete m_pContainer;
	delete m_pFont;
	delete m_pSlider;
	delete m_pListBoxScrollArea;
	delete m_pListBox;
	delete m_plistBoxScrollListener;
}

bool WidgetsContainer::BuildWidgets()
{
	m_pContainer = new gcn::Container();
	m_pContainer->setDimension(gcn::Rectangle(0, 0, m_pManager->m_winWidth, m_pManager->m_winHeight));

	m_pManager->m_pGcn->setTop(m_pContainer);

	// Now we load the font used in this example.
	m_pFont = new gcn::ImageFont("font.png", " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,!?-+/():;%&''*#=[]\"");
	// Widgets may have a global font so we don't need to pass the
	// font object to every created widget. The global font is static.
	gcn::Widget::setGlobalFont(m_pFont);

	midiListModel.AddIMSList();

	m_pListBox = new gcn::ListBox(&midiListModel);
	
	m_pListBox->setWidth(m_pManager->m_winWidth);
	m_pListBox->setHeight((m_pManager->m_winHeight/10) * 9);
	m_pListBox->setPosition(0, 0);
	m_pListBox->setActionEventId("midiList");

	m_pListBoxScrollArea = new gcn::ScrollArea(m_pListBox);
	m_pListBoxScrollArea->setWidth(m_pManager->m_winWidth);
	m_pListBoxScrollArea->setHeight((m_pManager->m_winHeight / 10) * 9);
	m_pListBoxScrollArea->setScrollbarWidth(40);
	m_pListBoxScrollArea->setPosition(0, 0);

	m_pSlider = new gcn::Slider(0, 100);
	m_pSlider->setSize(m_pManager->m_winWidth, (m_pManager->m_winHeight / 10));

	m_plistBoxScrollListener = new ListBoxScrollListener(this);
	m_pListBoxScrollArea->addActionListener(m_plistBoxScrollListener);
	m_pListBox->addActionListener(m_plistBoxScrollListener);

	m_pContainer->add(m_pListBoxScrollArea, 0, 0);
	m_pContainer->add(m_pSlider, 0, (m_pManager->m_winHeight / 10) * 9);

	return true;
}

void WidgetsContainer::UpdateSlider()
{
	if (m_plistBoxScrollListener)
	{
		if (m_plistBoxScrollListener->m_pMusic)
		{
			//m_plistBoxScrollListener->m_pMusic->
		}
	}
}

bool WidgetsContainer::AutoPlay()
{
	m_plistBoxScrollListener->AutoPlay();
	return true;
}

extern WidgetsContainer* pWidgetsContainer;

void musicDone() {
	g_bPlayEnd = true;
	pWidgetsContainer->AutoPlay();
}