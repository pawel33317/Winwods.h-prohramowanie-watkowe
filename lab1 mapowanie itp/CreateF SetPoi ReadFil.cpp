#include<cstdlib>
#include<iostream>
#include<cmath>
#include<stdio.h>
#include<windows.h>
#include<ctime>
using namespace std;
int main()
{
	HANDLE hfile;//trzeba tez zamknac
	hfile=CreateFile(//l1s9 tworzy plik w j�drze
		"E:\\plik.txt",	//nazwa
		GENERIC_READ|GENERIC_WRITE,//czytanie i zapisywanie
		FILE_SHARE_READ,//wsp�dzielenie
		NULL, //parametr bezpiecze�stwa
		OPEN_EXISTING,//musi istnie�|CREATE_NEW
		FILE_ATTRIBUTE_NORMAL, //bez specyficznych parametr�w
		NULL //nie korzystamy z template
	);
	if(hfile==INVALID_HANDLE_VALUE){cout << GetLastError();}
	
	DWORD miejsceodczytu=SetFilePointer(//ustawia miejsce do odczytu
		hfile, //uchwyt
		11,//liczba bajt�w do przesuni�cia
		NULL,//przy d�ugich plikach
		FILE_BEGIN // na poczatek pliku
	);
	if(miejsceodczytu==0xFFFFFFF){cout << GetLastError();}
	
	char tab[200];
	DWORD ws=0;
	BOOL wynik=ReadFile(//odczyt zapisw lab l1s9
		hfile,//uchwyt
		tab,//tablica wyjsciowa
		200,//znak�w do wczytania
		&ws,//wskaznik na liczbe wczytanych znakow
		NULL//operacja synchroniczna
	);
	if(!wynik){cout << GetLastError();}
	if(ws==200){cout << "Pelen odczyt";}
	else {cout << "wczytano znakow" << ws << endl;}
	
	
	
	
	
	CloseHandle(hfile);
	puts(tab);
	cin.get();
	return 0;
}
