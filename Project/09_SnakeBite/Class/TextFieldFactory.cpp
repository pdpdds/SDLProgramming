/** 
	@file	TextFieldFactory.cpp
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	SDL 라이브러리에서 Text틀 띄우기 위한 Surface를 만들어주는 싱글톤 클래스.
*/

#include "StdAfx.h"
#include "TextFieldFactory.h"
#include "han2unicode.h"
#include <sstream>

/**
	@brief	싱글톤 함수. 자기 자신의 객체 반환
	@return 자신의 객체
*/
TextFieldFactory* TextFieldFactory::Shared()
{
	static TextFieldFactory* instance = NULL;
	if(instance == NULL)
		instance = new TextFieldFactory;
	return instance;
}


/**
	@brief SDL_Surface에 뿌려질 TTF를 생성해주는 함수
	@param text 뿌려질 문자열
	@param fontsize 폰트 크기
	@param r 폰트 색 r
	@param g 폰트 색 g
	@param b 폰트 색 b
	@return 인자값으로 설정된 SDL_Surface
*/
SDL_Surface* 
TextFieldFactory::CreateTextFieldSurface(char* text, int fontsize, int r, int g, int b)
{
	TTF_Font* font = TTF_OpenFont("arial.ttf", fontsize);

	SDL_Color color;
	color.r = r;
	color.g = g;
	color.b = b;

	unsigned short unicode[128];
	han2unicode(text ,unicode); ///< char* 를 unicode로 변환

	return TTF_RenderUNICODE_Blended(font, unicode, color);
}

/**
	@brief "문자열" 숫자값 형태의 문자열을 만들어주는 함수.
	@param str 문자열
	@param number 숫자값
	@return 문자열 숫자값 이 이어진 형태의 문자열
*/
std::string 
TextFieldFactory::StringAndInt(std::string str, int number)
{
	std::stringstream ss;
	ss << str << number;

	return ss.str();
}