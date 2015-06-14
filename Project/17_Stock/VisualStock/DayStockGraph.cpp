#include "stdafx.h"
#include "DayStockGraph.h"
#include "SDL.h"
#include "SDL_gfxPrimitives.h"
#include "StockFacade.h"
#include "Company.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define POINT_INTERVAL 1

extern SDL_Surface* screen;

#define START_POINT_X 0.0f
#define START_POINT_Y 300.0f
#define MAX_T1302_DATA 700.0f
#define SCREEN_RATIO (SCREEN_WIDTH / MAX_T1302_DATA)
DayStockGraph::DayStockGraph()
{
}


DayStockGraph::~DayStockGraph()
{
}

bool DayStockGraph::OnRender(char* szStockCode)
{
	Company* pCompany = StockFacade::GetInstance()->GetCompany(szStockCode);

	if (!pCompany)
		return false;

	lineRGBA(screen, START_POINT_X, START_POINT_Y,
		START_POINT_X + SCREEN_WIDTH, START_POINT_Y,
		255, 0, 0, 255);

	auto& data = pCompany->m_mapTR1302;
	auto& iter = data.begin();
	int i = 0;
	t1302OutBlock1* pPrevData = NULL;
	t1302OutBlock1* pCurData = NULL;
	for (; iter != data.end(); iter++, i++)
	{
		pCurData = &iter->second;
		if (i != 0)
		{
			float fPrevDiff = _ttof(pPrevData->diff);
			float fCurDiff = _ttof(pCurData->diff);

			lineRGBA(screen, (START_POINT_X + POINT_INTERVAL * (i - 1)) * SCREEN_RATIO, START_POINT_Y + fPrevDiff * -20.0f,
				(START_POINT_X + POINT_INTERVAL * (i)) * SCREEN_RATIO, START_POINT_Y + fCurDiff * -20.0f,
				255, 255, 255, 255);
		}
		
		pPrevData = &iter->second;					

	}

	return true;
}