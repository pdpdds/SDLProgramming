#include "stdafx.h"
#include "Company.h"

Company::Company()
{
	m_pushCount = 0;
}


Company::~Company()
{
}

int Company::serialize(CArchive* pArchive)
{
	int nStatus = 0;

	try
	{
		if (pArchive->IsStoring()) {
			// Write employee name and id
			(*pArchive) << m_szCode;
			(*pArchive) << m_szName;
			(*pArchive) << m_szDataKey;
			(*pArchive) << m_pushCount;

			auto iter = m_mapDayStock.begin();

			for (; iter != m_mapDayStock.end(); iter++)
			{
				DayStockInfo& info = iter->second;
				
				(*pArchive) << info.date;
				(*pArchive) << info.highVal;
				(*pArchive) << info.lastVal;
				(*pArchive) << info.lowVal;
				(*pArchive) << info.startVal;
				(*pArchive) << info.vol;
			}
		}
		else 
		{
			(*pArchive) >> m_szCode;
			(*pArchive) >> m_szName;
			(*pArchive) >> m_szDataKey;
			(*pArchive) >> m_pushCount;

			for (int i = 0; i < m_pushCount; i++)
			{
				DayStockInfo info;

				(*pArchive) >> info.date;
				(*pArchive) >> info.highVal;
				(*pArchive) >> info.lastVal;
				(*pArchive) >> info.lowVal;
				(*pArchive) >> info.startVal;
				(*pArchive) >> info.vol;

				m_mapDayStock.insert(std::make_pair(info.date.GetString(), info));
			}
		}
	}
	catch (CException* pException)
	{
		nStatus = -1;
	}
	return (nStatus);
}

bool Company::SerializeToFile(bool bReading)
{
	CFile* pFile = new CFile();
	CString szFileName = "000020.bin";

	if (!pFile->Open(szFileName, CFile::modeReadWrite | CFile::shareExclusive)) {

		return false;
	}

	CArchive* pArchive = NULL;
	try
	{
		pFile->SeekToBegin();
		UINT uMode = (bReading ? CArchive::load : CArchive::store);
		pArchive = new CArchive(pFile, uMode);
		ASSERT(pArchive != NULL);
	}
	catch (CException* pException)
	{
		// Handle error
		return false;
	}

	serialize(pArchive);

	pArchive->Close();
	delete pArchive;
	pFile->Close();
	delete pFile;

	return true;
}

bool Company::AddDayStockDataPerMinute(t1302OutBlock1& info)
{
	m_mapTR1302.insert(std::make_pair(info.chetime, info));

	return true;
}

void	Company::Init()
{
	m_mapTR1302.clear();
}