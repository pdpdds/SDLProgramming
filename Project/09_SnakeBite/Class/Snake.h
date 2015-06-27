/** 
	@file	Snake.h
	@date	2013-03-03
	@author 심재환(sim436@gmail.com)
	@brief	뱀에 대한 정보를 가지고 있는 클래스
*/

#pragma once
#include "common.h"
#include "SnakeGameObject.h"
#include <vector>
class ItemManager;
class Point2D;

class Snake : public SnakeGameObject
{
private:
	std::vector<Point2D*> body; ///< 뱀 머리+몸통의 좌표
	ItemManager	*itemMgr;		///< 아이템
	time_t	getItemTime; ///< 아이템 획득 시간
	int		speed;		 ///< 속도
	bool	isSpeedUp;	 ///< 스피드 업 상태인가
	bool	isArrive;	 ///< 살아 있나

	int		lastUpdateTime; ///< 마지막으로 업데이트 된 시간

	void CheckIntersection();
	void CheckSpeedUpTime();

public:
	Snake(int startPosX, int startPosY);

	typedef enum {
		kLEFT,
		kRIGHT,
		kUP,
		kDOWN,
	}DIR;
	DIR dir; ///< 진행 방향

	void Init();	
	void Update();	
	void Draw();	

	void SetDir(DIR d);
	int BodyCount() const;
	int Speed() const;
	bool IsArrive() const;
	void SetItemManager(ItemManager* itemmanger);

	
};

