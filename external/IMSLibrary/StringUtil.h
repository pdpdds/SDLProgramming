#pragma once
#include <string>

using namespace std;

std::string ConvertExt(std::string& szFileName, std::string strModExt);
std::string GetExt(std::string& szPassName);

#ifdef _WIN32
std::wstring s2ws(const std::string& s);
std::string ws2s(const std::wstring& s);
#endif