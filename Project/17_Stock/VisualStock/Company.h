#pragma once
#include <map> 
#include <iostream> 
#include <fstream> 

class CArchive;

struct DayStockInfo {
	CString date;		//날짜
	LONG startVal;		//시가
	LONG highVal;		//고가
	LONG lowVal;		//저가
	LONG lastVal;		//종가
	LONG vol;			//거래량
};

class Company
{
	
public:
	Company();
	virtual ~Company();

	typedef std::map<std::string, t1302OutBlock1> mapTR1302;

	bool SerializeToFile(bool bStore);

	CString m_szCode;
	CString m_szName;
	CString m_szDataKey;
	std::map<std::string, DayStockInfo> m_mapDayStock;
	int m_pushCount;

	int serialize(CArchive* pArchive);

	mapTR1302 m_mapTR1302;

	bool AddDayStockDataPerMinute(t1302OutBlock1& info);
	mapTR1302& GetDayStockData(){ return m_mapTR1302; }
	void	Init();

};

