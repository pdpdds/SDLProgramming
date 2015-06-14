#pragma once
#include <map>
#include "Company.h"

typedef std::map<std::string, Company*> mapStock;

class StockManager
{
public:
	StockManager();
	virtual ~StockManager();

	bool LoadStockInfoFile(char* szFileName);
	bool AddCompany(Company* pStock);
	Company* FindCompany(char* szCode);
	Company* FindCompanyWithDataKey(char* szDataKey);

	Company* GetCurrentSelectedCompany();
	void SetCurrentSelectedCompany(char* szCode);

	mapStock m_mapStock;
	std::string m_szCurrentSelectedCompany;
};