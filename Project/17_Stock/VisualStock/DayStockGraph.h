#pragma once
#include "IGraph.h"

class DayStockGraph : public IGraph
{
public:
	DayStockGraph();
	virtual ~DayStockGraph();

	virtual bool OnRender(char* szStockCode) override;

protected:

private:
};

