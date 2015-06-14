#pragma once
class IGraph
{
public:
	IGraph(){}
	virtual ~IGraph(){}

	virtual bool OnRender(char* szStockCode) = 0;
};