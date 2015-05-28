#include <iostream>//synchronizacja wait
#include <windows.h>//
#include <cmath>
#include <stdio.h>
#include <process.h>
using namespace std;
UINT WINAPI obliczenia(LPVOID);
struct PAR{int n1;char zn;};
int main(int argc, char* argv[]) // pot4
{
	PAR pas1={30,'*'};UINT id_G1=0;
	PAR pas2={43,'&'};UINT id_G2=0;
		//////////////singleobjectWAIT
		HANDLE hWatekk1=(HANDLE)_beginthreadex(0,0,obliczenia,&pas1,0,&id_G1);
		DWORD wynik = WaitForSingleObject(hWatekk1,8000);
		HANDLE hWatekk2=(HANDLE)_beginthreadex(0,0,obliczenia,&pas2,0,&id_G2);
		wynik = WaitForSingleObject(hWatekk2,8000);
		
	//////////////Multi Object WAITTTTT
	PAR parr[4]; UINT id_w[4];
	parr[0]={80,'^'};	parr[1]={10,'%'};
	parr[2]={20,'$'};	parr[3]={30,'#'};
	HANDLE hWatek[2],hWatekk[2];
	hWatek[0]=(HANDLE)_beginthreadex(0,0,obliczenia,&parr[0],0,&id_w[0]);
	hWatek[1]=(HANDLE)_beginthreadex(0,0,obliczenia,&parr[1],0,&id_w[1]);
	DWORD iwynik= WaitForMultipleObjects(2,hWatek,TRUE,8000);
	hWatekk[0]=(HANDLE)_beginthreadex(0,0,obliczenia,&parr[2],0,&id_w[2]);
	hWatekk[1]=(HANDLE)_beginthreadex(0,0,obliczenia,&parr[3],0,&id_w[3]);
	
	iwynik= WaitForMultipleObjects(2,hWatekk,FALSE,8000);
	puts("\nKoniec Pot4 - Wcisnij Enter");  
	cin.get();
return 0;	
}
UINT WINAPI obliczenia(LPVOID parm)       // d³ugotrwa³e obliczenia
{
	PAR *parmm = (PAR*)parm;
	double w;
	for (int k1=0; k1 < parmm->n1; k1++){   
	      for (int k2=0; k2 < parmm->n1; k2++) w = pow(sin(parmm->n1),3.3)* pow(cos(k1),2.2); 
	      cout << parmm->zn << " "; Sleep(50);
	      }  puts("");cout << endl;
}

