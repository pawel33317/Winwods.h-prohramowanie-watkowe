#include <iostream>
#include <windows.h>
#include <cmath>
#include <stdio.h>
#include <process.h>
using namespace std;
UINT WINAPI obliczenia(LPVOID);
struct PAR{int n1;char zn;};
int main(int argc, char* argv[]) // pot3
{
	cout << "lalalal" << endl;
		PAR parr2={30,'*'};
	obliczenia(&parr2);
	for(int i=0;i<55;i++){double ff; ff=rand()%999+1; ff=ff/100; cout << i << ". " << ff << endl;}
	puts("\nKoniec Pot3 - Wcisnij Enter");  
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

