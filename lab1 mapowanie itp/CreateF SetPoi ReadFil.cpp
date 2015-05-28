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
	hfile=CreateFile(//l1s9 tworzy plik w j¹drze
		"E:\\plik.txt",	//nazwa
		GENERIC_READ|GENERIC_WRITE,//czytanie i zapisywanie
		FILE_SHARE_READ,//wspó³dzielenie
		NULL, //parametr bezpieczeñstwa
		OPEN_EXISTING,//musi istnieæ|CREATE_NEW
		FILE_ATTRIBUTE_NORMAL, //bez specyficznych parametrów
		NULL //nie korzystamy z template
	);
	if(hfile==INVALID_HANDLE_VALUE){cout << GetLastError();}
	
	DWORD miejsceodczytu=SetFilePointer(//ustawia miejsce do odczytu
		hfile, //uchwyt
		11,//liczba bajtów do przesuniêcia
		NULL,//przy d³ugich plikach
		FILE_BEGIN // na poczatek pliku
	);
	if(miejsceodczytu==0xFFFFFFF){cout << GetLastError();}
	
	char tab[200];
	DWORD ws=0;
	BOOL wynik=ReadFile(//odczyt zapisw lab l1s9
		hfile,//uchwyt
		tab,//tablica wyjsciowa
		200,//znaków do wczytania
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
