#include <iostream>      
#include <windows.h>
#include <process.h>
using namespace std;
UINT WINAPI ZNAK(LPVOID); 
UINT WINAPI ZNAK1(LPVOID);   

struct PARM {
       int n; char zn;
       };

int main()   // Watek6b.     Oczekiwanie na zakoñczenie pracy 2-ch w¹tków
{
HANDLE pWatek[2] = {NULL, NULL}, hWatekS = NULL;   
UINT ID_A = 0, ID_B = 0,  ID_S = 0;
PARM  parm1 = {20, 'A'}, parm2 = {100, 'B'},	parm3 = {30, 'S'};
	// uruchomienie 2-ch watkow potomnych
pWatek[0] = (HANDLE)_beginthreadex(NULL, 0, ZNAK, &parm1, 0, &ID_A);
pWatek[1] = (HANDLE)_beginthreadex(NULL, 0, ZNAK, &parm2, 0, &ID_B);
	
    // czekanie az jeden z watkow zawartych w tablicy pWatek zakoncza dzialanie
DWORD ind = WaitForMultipleObjects(2, pWatek, FALSE, INFINITE);
cout << "\n zakonczyl watek idn=" << ind << endl;
hWatekS = (HANDLE)_beginthreadex(NULL, 0, ZNAK, &parm3, 0, &ID_S);	

for(int i = 0; i < 30; i++)	{ // wypisuje 30 razy znak z parametru co 50 ms
		cout << "G ";
		cout.flush();  Sleep(50);
	    } 
for (int k=0; k < 2; k++) CloseHandle(pWatek[k]);   CloseHandle(hWatekS);  
cout << "Koniec - wcisnij ENTER";   cin.get(); 
return 0;
} 

UINT WINAPI ZNAK(LPVOID par)
{
PARM *parm = (PARM*)par;
int M = parm->n;   
char zn = parm->zn,   zn1 = '1';   	
HANDLE  hWatek1;  UINT ID1 = 0;
hWatek1 = (HANDLE)_beginthreadex(NULL, 0, ZNAK1, &zn1, 0, &ID1);
WaitForSingleObject(hWatek1, INFINITE);  	
for(int i = 0; i < 30; i++)	{ // wypisuje 30 razy znak co M ms 
		cout << zn << ' ';
		cout.flush();
		Sleep(M);
    	} cout << endl;
_endthreadex(0);
} 

UINT WINAPI ZNAK1(LPVOID zn)
{
for(int i = 0; i < 30; i++)	{ // wypisuje 30 razy znak co 22 ms 
		cout << *((char*)zn) << ' ';
		cout.flush();
		Sleep(22);
    	} cout << endl;
_endthreadex(0);
} 




