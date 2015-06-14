#include "WidgetsContainer.h"
#include "GUIManager.h"
#include "SDL_Mixer.h"
#include "IMSLibrary/IMSManager.h"

extern IMSManager* g_pManager;

class IMSListModel : public gcn::ListModel
{
public:
	int getNumberOfElements()
	{
		return 3;
	}

	std::string getElementAt(int i)
	{
		switch (i)
		{
		case 0:
			return std::string("1.ims");
		case 1:
			return std::string("2.ims");
		case 2:
			return std::string("3.ims");
		default: // Just to keep warnings away
			return std::string("");
		}
	}
};

IMSListModel imsListModel;

class ListBoxScrollListener : public gcn::ActionListener
{
public:
	// Implement the action function in ActionListener to recieve actions
	// The eventId tells us which widget called the action function.
	ListBoxScrollListener(WidgetsContainer* pWidgetsContainer)
	{
		m_pWidgetsContainer = pWidgetsContainer;
		m_pMusic = 0;
	}

	void action(const gcn::ActionEvent& actionEvent)
	{
		std::string str;


		// Here we use the widget pointer to check which widget the action
		// originated from.
		if (actionEvent.getSource() == m_pWidgetsContainer->m_pListBoxScrollArea)
		{
			
		}
		if (actionEvent.getSource() == m_pWidgetsContainer->m_pListBox)
		{
			int selected = m_pWidgetsContainer->m_pListBox->getSelected();
			std::string szImsFile = "assets/";
			szImsFile += m_pWidgetsContainer->m_pListBox->getListModel()->getElementAt(selected);

			g_pManager->Stop();
			if (false == g_pManager->LoadIMS((char*)szImsFile.c_str()))
				return;

			g_pManager->Run();
			
		}
	}

	WidgetsContainer* m_pWidgetsContainer;
	Mix_Music* m_pMusic;
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
	int desiredWidth = 640;
	int desiredHeight = 480;
	int ttfFontSize = 20;
	if (m_pManager->m_winHeight >= 480 && m_pManager->m_winHeight < 600)
		ttfFontSize = 20;
	else if (m_pManager->m_winHeight >= 600 && m_pManager->m_winHeight < 768)
		ttfFontSize = 30;
	else if (m_pManager->m_winHeight >= 768)
		ttfFontSize = 40;

	m_pContainer = new gcn::Container();
	m_pContainer->setDimension(gcn::Rectangle(0, 0, m_pManager->m_winWidth, m_pManager->m_winHeight));

	m_pManager->m_pGcn->setTop(m_pContainer);

	// Now we load the font used in this example.
	m_pFont = new gcn::ImageFont("font.png", " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,!?-+/():;%&''*#=[]\"");
	// Widgets may have a global font so we don't need to pass the
	// font object to every created widget. The global font is static.
	gcn::Widget::setGlobalFont(m_pFont);

	TrueTypeFont* pTrueFont = TrueTypeFont::load("H2MJRE.TTF", ttfFontSize, 0);
	//gcn::Widget::setGlobalFont(pTrueFont);

	m_pListBox = new gcn::ListBox(&imsListModel);
	m_pListBox->setWidth(m_pManager->m_winWidth);
	m_pListBox->setHeight((m_pManager->m_winHeight/10) * 5);
	m_pListBox->setPosition(0, 0);
	m_pListBox->setActionEventId("midiList");

	m_pListBoxScrollArea = new gcn::ScrollArea(m_pListBox);
	m_pListBoxScrollArea->setWidth(m_pManager->m_winWidth);
	m_pListBoxScrollArea->setHeight((m_pManager->m_winHeight / 10) * 5);
	m_pListBoxScrollArea->setScrollbarWidth(40);
	m_pListBoxScrollArea->setPosition(0, 0);

	m_pSlider = new gcn::Slider(0, 100);
	m_pSlider->setSize(m_pManager->m_winWidth, (m_pManager->m_winHeight / 10));

	m_plistBoxScrollListener = new ListBoxScrollListener(this);
	m_pListBoxScrollArea->addActionListener(m_plistBoxScrollListener);
	m_pListBox->addActionListener(m_plistBoxScrollListener);
	m_pListBox->setFont(pTrueFont);

	m_pTextBox = new gcn::TextBox("");
	m_pTextBox->setBackgroundColor(gcn::Color(255, 150, 200, 0));
	m_pTextBox->setFont(pTrueFont);

	m_pWindow = new gcn::Window("Lyrics");
	m_pWindow->setBaseColor(gcn::Color(255, 150, 200, 190));
	m_pWindow->add(m_pTextBox);
	m_pWindow->setWidth(m_pManager->m_winWidth);
	m_pWindow->setHeight((m_pManager->m_winHeight / 10) * 4);
	m_pWindow->setTitleBarHeight(40);

	m_pContainer->add(m_pListBoxScrollArea, 0, 0);
	m_pContainer->add(m_pSlider, 0, (m_pManager->m_winHeight / 10) * 5);
	m_pContainer->add(m_pWindow, 0, (m_pManager->m_winHeight / 10) * 6);

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

void WidgetsContainer::SetTrueTypeFont(TTF_Font* pFont)
{
	
	//m_pListBox->setFont(pFont);
}