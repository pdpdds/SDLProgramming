/** 
	@file	Wall.cpp
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	벽, 장애물들에 대한 정보를 가지고 있는 클래스.
*/

#include "stdafx.h"

#include "Wall.h"
#include <stdio.h>

/**
	@brief 생성자. 정보가 담긴 txt 파일을 읽어와 벽과 장애물을 구성한다.
	@param mapFileName 맵 정보가 담긴 txt파일의 이름.
*/
Wall::Wall(const char* mapFileName)
{
	FILE *file = fopen(mapFileName, "rt"); ///< 스트림 시작 읽기모드 

	char ch;
	int w=0, h=0;
	std::vector<char> horizontal;	 ///< 맵의 가로한줄의 정보를 담기위한 벡터 지역변수.
	while( (ch=fgetc(file)) != EOF ) ///< 파일의 끝이 나올때 까지 한 문자씩 읽어옴
	{
		if(ch=='\n') ///< 줄바꿈이 나오면,
		{
			h++;	 ///< 타일정보의 다음줄로 넘어가고
			w=0;	 ///< 가로 index 값을 0으로 초기화.
			blocks.push_back(horizontal);	///< 가로 한줄 벡터 정보를 세로 벡터에 삽입.
			horizontal.clear();				///< 가로 정보 벡터 초기화
			continue;						///< 반복문의 처음으로
		}
		horizontal.push_back(ch);	///< 가로 벡터에 문자 삽입
		w++;						///< 가로 index 증가
	}

	fclose(file);	///< 스트림 종료
}

/**
	@brief 오브젝트 초기화 함수
*/
void Wall::Init()
{
	bg = IMG_Load("gameBG.bmp");
}

/**
	@brief 오브젝트 갱신 함수 \n
		   장애물, 벽의 정보를 snakeMap 객체  등록한다.
*/
void Wall::Update()
{	
	for(int h=0; h < blocks.size(); h++)
	{
		for(int w=0; w<blocks.at(h).size(); w++)
		{
			snakeMap_->SetTilesInfoOfIndex(w, h, blocks.at(h).at(w));
		}
	}
}

/**
	@brief 오브젝트 렌더 함수 \n
		   tiles의 정보를 화면에 그린다.
*/
void Wall::Draw()
{	
	DrawSurface(screen_, 0, 0, bg);
	
	for(int h=0; h < blocks.size(); h++)
	{
		for(int w=0; w<blocks.at(h).size(); w++)
		{
			if(blocks.at(h).at(w)=='#') ///< 타일의 정보가 #이면 
			{
				SDL_Surface* block = IMG_Load("block.bmp");  
				DrawSurface(screen_, w*20, h*20, block); ///< 블록 이미지 출력
				SDL_FreeSurface(block);
			}
		}
	}
}