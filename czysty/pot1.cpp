#include <iostream>
#include <windows.h>
#include <cmath>
#include <stdio.h>
using namespace std;
void obliczenia(int, char);

int WINAPI WinMain(HINSTANCE hlnstance, HINSTANCE hPrevinstance, LPSTR IpCmdLine, int iCmdShow)
{

DWORD czas = GetTickCount();
	if (_argc <= 1 ) { puts("Brak Danych"); return 10; }
	else {cout << _argv[2] << endl;}
	Sleep(20);
	
	
DWORD czasnowy = GetTickCount();	
	cout << czasnowy-czas << endl;//czas wykonania pêtli
	puts("\nKoniec Pot1 - Wcisnij Enter");  
	cin.get();
	return 0;	
}
void obliczenia(int n1, char zn)
{
	double w;
	for (int k1=0; k1 < n1; k1++){   
	      for (int k2=0; k2 < n1; k2++) w = pow(sin(n1),3.3)* pow(cos(k1),2.2); 
	      cout << zn << " "; Sleep(50);
	      }  puts("");
}

