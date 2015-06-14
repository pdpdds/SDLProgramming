#pragma once
#include "IWidgetContainer.h"

#include <guichan.hpp>
#include <guichan/sdl.hpp>

class GUIManager;
class ListBoxScrollListener;

class WidgetsContainer : public IWidgetsContainer
{
public:
	WidgetsContainer(GUIManager* pManager);
	virtual ~WidgetsContainer();

	virtual bool BuildWidgets();
	void UpdateSlider();
	void SetTrueTypeFont(TTF_Font* pFont);

public:
	gcn::Container* m_pContainer;
	gcn::ImageFont* m_pFont;
	
	gcn::Slider* m_pSlider;

	ListBoxScrollListener* m_plistBoxScrollListener;
	gcn::ScrollArea* m_pListBoxScrollArea;
	gcn::ListBox* m_pListBox;
	gcn::TextBox* m_pTextBox;
	gcn::Window* m_pWindow;
	
	GUIManager* m_pManager;

};

