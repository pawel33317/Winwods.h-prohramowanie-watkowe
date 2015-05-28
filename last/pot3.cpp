#include <iostream>////////////////MUTEX
#include <windows.h>
#include <cmath>
#include <stdio.h>
#include <process.h>
using namespace std;
UINT WINAPI obliczenia(LPVOID);
struct PAR{int n1;char zn;};
HANDLE hMutex;////////////////MUTEX
int main(int argc, char* argv[]) // pot3
{
		PAR parr2={30,'*'};
		hMutex = CreateMutex (0,FALSE,0);////////////////MUTEX
		
		PAR parr[2]; UINT id_w[2];
		parr[0]={80,'^'};	parr[1]={10,'%'};
		
		HANDLE hWatek[2];
		hWatek[0]=(HANDLE)_beginthreadex(0,0,obliczenia,&parr[0],0,&id_w[0]);
		hWatek[1]=(HANDLE)_beginthreadex(0,0,obliczenia,&parr[1],0,&id_w[1]);
		CloseHandle(hWatek[1]);CloseHandle(hWatek[0]);
		//obliczenia(&parr2);
	
		DWORD wynikm = WaitForSingleObject(hMutex,8000);////////////////MUTEX
		for(int i=0;i<55;i++){Sleep(50);double ff; ff=rand()%999+1; ff=ff/100; cout << i << ". " << ff ;}
		ReleaseMutex(hMutex);CloseHandle(hMutex);////////////////MUTEX

	puts("\nKoniec Pot3 - Wcisnij Enter");  
	cin.get();
return 0;	
}
UINT WINAPI obliczenia(LPVOID parm)
{
	PAR *parmm = (PAR*)parm;
	double w;
	DWORD wynikm = WaitForSingleObject(hMutex,8000);////////////////MUTEX
	for (int k1=0; k1 < parmm->n1; k1++){   
	      for (int k2=0; k2 < parmm->n1; k2++) w = pow(sin(parmm->n1),3.3)* pow(cos(k1),2.2); 
	      cout << parmm->zn << " "; Sleep(50);
	      }  puts("");ReleaseMutex(hMutex);////////////////MUTEX
	     
}

