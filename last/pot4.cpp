#include <iostream>////////SEKCJA KRYTYCZNA
#include <windows.h>
#include <cmath>
#include <stdio.h>
#include <process.h>
using namespace std;
UINT WINAPI obliczenia(LPVOID);
struct PAR{int n1;char zn;};
CRITICAL_SECTION cs;////////SEKCJA KRYTYCZNA
int main(int argc, char* argv[]) // pot4
{
	//////////////Multi Object WAITTTTT
	PAR parr[2]; UINT id_w[2];
	parr[0]={80,'^'};	parr[1]={10,'%'};
	HANDLE hWatek[2];
	
	InitializeCriticalSection(&cs);////////SEKCJA KRYTYCZNA
	
	hWatek[0]=(HANDLE)_beginthreadex(0,0,obliczenia,&parr[0],0,&id_w[0]);
	hWatek[1]=(HANDLE)_beginthreadex(0,0,obliczenia,&parr[1],0,&id_w[1]);
	DWORD iwynik= WaitForMultipleObjects(2,hWatek,TRUE,8000);
	
	puts("\nKoniec Pot4 - Wcisnij Enter");  
	cin.get();
return 0;	
}
UINT WINAPI obliczenia(LPVOID parm)       // d³ugotrwa³e obliczenia
{
	PAR *parmm = (PAR*)parm;
	double w;EnterCriticalSection(&cs);////////SEKCJA KRYTYCZNA
	for (int k1=0; k1 < parmm->n1; k1++){   
	      for (int k2=0; k2 < parmm->n1; k2++) w = pow(sin(parmm->n1),3.3)* pow(cos(k1),2.2); 
	      cout << parmm->zn << " "; Sleep(50);
	      }  puts("");cout << endl;LeaveCriticalSection(&cs);////////SEKCJA KRYTYCZNA
}
