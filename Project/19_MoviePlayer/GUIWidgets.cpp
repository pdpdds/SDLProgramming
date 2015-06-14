#include "stdafx.h"
#include "GUIWidgets.h"
#include "SDL.h"

#ifdef _DEBUG
#pragma comment(lib, "balor_debug.lib")
#else
#pragma comment(lib, "balor.lib")
#endif

GUIWidgets::GUIWidgets(int width, int height)
{
	m_resizeSendTime = 0;
	m_scrollValue = 0;

	m_pFrame = new Frame(L"SDL With Windows GUI", width, height, Frame::Style::sizable);
	m_pPanel = new Panel(*m_pFrame, 0, 0, width, height - 50);

	m_panelWidth = m_pFrame->clientSize().width;
	m_panelHeight = m_pFrame->clientSize().height;

	m_pButton = new Button(*m_pFrame, 10, 430, 100, 50, L"button0");
	m_pButton->onClick() = [&](Button::Click&) {
		
		SDL_Event event;
		event.type = FF_STREAM_PAUSE;
		
		SDL_PushEvent(&event);
	};

	m_pFrame->onResize() = [&](Frame::Resize& k) {
		SetWindowPos(m_pPanel->handle(), NULL, 0, 0, m_pFrame->clientSize().width, m_pFrame->clientSize().height -50, 0);
		m_panelWidth = m_pFrame->clientSize().width;
		m_panelHeight = m_pFrame->clientSize().height;		
		SDL_Event event;


		event.type = FF_WINDOW_RESIZE;
		SDL_PushEvent(&event);
		
		
	};

	m_pSearchBar = new ScrollBar(*m_pFrame, 120, 450, 200, 20, 0, 60*60*60);
	m_pSearchBar->value(50);
	/*m_pSearchBar->onValueChange() = [&](TrackBar::ValueChange& valueChange) {

		int value = valueChange.newValue();

		SDL_Event event;
		event.type = FF_SEEK_BAR_EVENT;		
		SDL_PushEvent(&event);
		
	};*/

	m_pSearchBar->onScroll() = [&](ScrollBar::Scroll& e) {

	m_scrollValue = e.newValue();

	SDL_Event event;
	event.type = FF_SEEK_BAR_EVENT;
	SDL_PushEvent(&event);

	};	

	m_pFrame->visible();
}

void GUIWidgets::SetSize(int width, int height)
{
	SetWindowPos(m_pFrame->handle(), NULL, 0, 0, width, height, 0);
	SetWindowPos(m_pPanel->handle(), NULL, 0, 0, width, height - 50, 0);
}

void GUIWidgets::RunMessageLoop()
{
	if (m_pFrame)
		m_pFrame->runMessageLoop();
}


GUIWidgets::~GUIWidgets()
{
	delete m_pSearchBar;
	delete m_pButton;
	delete m_pPanel;
	delete m_pFrame;
}
