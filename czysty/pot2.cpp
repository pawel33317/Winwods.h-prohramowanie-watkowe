#include <iostream>
#include <windows.h>
#include <cmath>
#include <stdio.h>
#include <process.h>
using namespace std;
UINT WINAPI obliczenia(LPVOID);
struct PAR{int n1;char zn;};
int main(int argc, char* argv[]) // pot2
{
	PAR parr2={30,'*'};UINT id_G=0;
	HANDLE hWatek=(HANDLE)_beginthreadex(0,0,obliczenia,&parr2,0,&id_G);
	int z;
	if (argc>1)z= atof(argv[2]);else z=22;
	for(int i=1;i<20;i++){
		cout << "zz" << z << "zz";Sleep(40);
	}
	
	puts("\nKoniec Pot2 - Wcisnij Enter");  
	cin.get();
return 0;	
}
UINT WINAPI obliczenia(LPVOID parm)
{
	PAR *parmm = (PAR*)parm;
	double w;
	for (int k1=0; k1 < parmm->n1; k1++){   
	      for (int k2=0; k2 < parmm->n1; k2++) w = pow(sin(parmm->n1),3.3)* pow(cos(k1),2.2); 
	      cout << parmm->zn << " "; Sleep(50);
	      }  puts("");
}

