#include<windows.h>
#include<iostream>
using namespace std;
int WINAPI /*funkcja wsp�pracuje z systemem*/ WinMain(HINSTANCE hlnstance, HINSTANCE hPrevinstance, LPSTR IpCmdLine, int iCmdShow)
{
	
	iCmdShow = SW_HIDE;
	MessageBoxEx(NULL, IpCmdLine,"Tytu� nowego okna", IDABORT, 0);
	//uchwyt okna b�d�cego w�ascicielem,adres tekstu wyswietlanego w oknie
	//tytu� okna, styl okna, j�zyk okna
	DWORD czas = GetTickCount();//zwraca liczbe milisekund od rozpocz�cia programu
	for(int i=0;i<99;i++)cout << "aa" << endl;
	DWORD czasnowy = GetTickCount();	
	std::cout << czasnowy-czas;//czas wykonania p�tli
	//wyswietlenie aktualnego czasu l1 s7
	char buf[256];
	GetTimeFormat(NULL,0,NULL,NULL,buf,255);//wyswietlanie czasu l1s7
	cout << endl << buf << endl ;
	GetDateFormat(NULL,NULL,NULL,NULL,buf,255);
	cout << endl << buf << endl ;
	cin.get();
	return 0;
}
//hlnstance uchwyt
//hPrevinstance pozosta�osc po 16 bitach
//IpCmdLine adres �a�cucha znak�w w kt�rym s� argumenty programu
//uCmdShow jak powinno pokazac sie g��wne okno programu l1s3

//HINSTANCE void*
//LPCSTR const char * 
//LPSTR char*
//UINT insigned int
//LPINT int*

//zale�y od ustawienia linkera czy szuka main czy WinMain l1s5
