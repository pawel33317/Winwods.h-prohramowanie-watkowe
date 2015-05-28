#include<windows.h>
#include<iostream>
using namespace std;
int WINAPI /*funkcja wspó³pracuje z systemem*/ WinMain(HINSTANCE hlnstance, HINSTANCE hPrevinstance, LPSTR IpCmdLine, int iCmdShow)
{
	
	iCmdShow = SW_HIDE;
	MessageBoxEx(NULL, IpCmdLine,"Tytu³ nowego okna", IDABORT, 0);
	//uchwyt okna bêd¹cego w³ascicielem,adres tekstu wyswietlanego w oknie
	//tytu³ okna, styl okna, jêzyk okna
	DWORD czas = GetTickCount();//zwraca liczbe milisekund od rozpoczêcia programu
	for(int i=0;i<99;i++)cout << "aa" << endl;
	DWORD czasnowy = GetTickCount();	
	std::cout << czasnowy-czas;//czas wykonania pêtli
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
//hPrevinstance pozosta³osc po 16 bitach
//IpCmdLine adres ³añcucha znaków w którym s¹ argumenty programu
//uCmdShow jak powinno pokazac sie g³ówne okno programu l1s3

//HINSTANCE void*
//LPCSTR const char * 
//LPSTR char*
//UINT insigned int
//LPINT int*

//zale¿y od ustawienia linkera czy szuka main czy WinMain l1s5
