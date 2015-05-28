#include <iostream>//w¹tek zatrzymanie i wznawianie
#include <windows.h>//priorytety
#include <cmath>
#include <stdio.h>
#include <process.h>
using namespace std;
UINT WINAPI obliczenia(LPVOID);
struct PAR{int n1;char zn;};
int main(int argc, char* argv[]) // pot3
{
	PAR parr2={30,'*'};UINT id_G=0;
	PAR parr3={30,'!'};UINT id_Gb=0;
	HANDLE hWatekb=(HANDLE)_beginthreadex(0,0,obliczenia,&parr3,CREATE_SUSPENDED,&id_Gb);
	
	//zmiana priorytetu
	BOOL zpzp=SetThreadPriority(hWatekb,THREAD_PRIORITY_IDLE);
	ResumeThread(hWatekb);
	
	HANDLE hWatek=(HANDLE)_beginthreadex(0,0,obliczenia,&parr2,0,&id_G);
	SuspendThread(hWatek);
	int z;	if (argc>1)z= atof(argv[2]);else z=22;
	for(int i=1;i<20;i++){
		cout << "zz" << z << "zz";Sleep(40);
	}
	ResumeThread(hWatek);
	
	puts("\nKoniec Pot3 - Wcisnij Enter");  
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
	      }  puts("");
}

