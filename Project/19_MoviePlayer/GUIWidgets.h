#pragma once
#include <balor/gui/all.hpp>

using namespace balor::gui;

class GUIWidgets
{
public:
	GUIWidgets(int width, int height);
	virtual ~GUIWidgets();


	void RunMessageLoop();
	void SetSize(int width, int height);

	Frame* m_pFrame;
	Panel* m_pPanel;
	Button* m_pButton;
	ScrollBar* m_pSearchBar;

	int m_panelWidth;
	int m_panelHeight;
	int m_scrollValue;
	DWORD m_resizeSendTime;
};


