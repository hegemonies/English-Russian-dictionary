#include <iostream>
#include <string>
#include <locale>
#include <stdlib.h>
using namespace std;

int main(void)
{
	// wstring str;
	// str = L"Привет";
	
	string str = "привет";

	wchar_t* pWChr = new wchar_t[str.size()];
	//size_t outSize;
	//mbstowcs_s(&outSize, pWChr, str.size(), str.c_str(), str.size());
	mbstowcs(pWChr, str.c_str(), str.length() + 1);

	wstring wstr(pWChr);
	delete[] pWChr;

	locale system("");
    locale::global(system);
	
	wcout << wstr.c_str << endl;
}