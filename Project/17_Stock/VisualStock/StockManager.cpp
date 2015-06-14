#include "stdafx.h"
#include "StockManager.h"


StockManager::StockManager()
{
	
}

StockManager::~StockManager()
{
}

bool StockManager::AddCompany(Company* pStock)
{
	m_mapStock.insert(std::make_pair(pStock->m_szCode.GetString(), pStock));
	return true;
}

void StockManager::SetCurrentSelectedCompany(char* szCode)
{
	if (szCode == NULL)
	{
		auto iter = m_mapStock.begin();
		m_szCurrentSelectedCompany = iter->first;
	}
	else
	{
		m_szCurrentSelectedCompany = szCode;
	}
}

Company* StockManager::GetCurrentSelectedCompany()
{
	auto iter = m_mapStock.find(m_szCurrentSelectedCompany);

	if (iter == m_mapStock.end())
		return NULL;

	return iter->second;
}

Company* StockManager::FindCompany(char* szCode)
{
	auto iter = m_mapStock.find(szCode);

	if (iter == m_mapStock.end())
		return NULL;

	return iter->second;
}

Company* StockManager::FindCompanyWithDataKey(char* szDataKey)
{
	auto iter = m_mapStock.begin();

	for (; iter != m_mapStock.end(); iter++)
	{
		Company* pCompany = iter->second;
		if (pCompany->m_szDataKey.Compare(szDataKey) == 0)
			return pCompany;
	}

	return NULL;
}

