/** 
	@file	TextFieldFactory.h
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	SDL 라이브러리에서 Text틀 띄우기 위한 Surface를 만들어주는 클래스.
*/

#pragma once
class TextFieldFactory
{
public:
	static TextFieldFactory* Shared();
	SDL_Surface* CreateTextFieldSurface(char* text, int fontsize=15, int r=0, int g =0, int b=0);
	std::string StringAndInt(std::string str, int number);

private:
	TTF_Font *font;

	TextFieldFactory(void) {}
	~TextFieldFactory(void) {}
};

