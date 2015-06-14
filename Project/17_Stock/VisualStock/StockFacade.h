#pragma once

class IXingAPI;
class IRequestCallback;
class StockManager;
class Company;
class BotManager;
class IBot;

class StockFacade
{
public:
	virtual ~StockFacade();

	static StockFacade* GetInstance();

	bool Initialize();

	bool Connect(HWND hWnd, char* szID, char* szPassword);
	bool Disconnect();
	bool Update();

	bool GetCompanyData(char* pCompanyCode);
	bool RequestT1302(char* szStockCode);
	bool ProcessReceiveData(WPARAM wParam, LPARAM lParam);

	StockManager* GetStockManager(){ return m_pStockManager; }
	Company* GetCompany(char* szStockCode);
	IXingAPI* GetXingAPI(){ return m_pXingAPI; }
	HWND& GetHwnd(){ return m_hWnd; }

	CString szSelectedCompany;

protected:
	bool ProcessT1302(LPARAM lParam);
	bool XingRequest(char* szDirective, LPVOID pData, int size);

private:
	IXingAPI* m_pXingAPI;
	
	HWND m_hWnd;
	IRequestCallback* m_pCallback;
	bool m_bFirstT8430Req;
	CStringA m_date;

	StockFacade();

	StockManager* m_pStockManager;
	static StockFacade* m_pStockFacade;
};
