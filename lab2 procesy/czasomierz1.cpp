#include <iostream>
#include <windows.h>
#include <process.h>
#include <cmath>
using namespace std;

#define Czas  GetTimeFormat(NULL,0,NULL,NULL,buf,255);  cout<<buf<<endl;
UINT WINAPI Licz(LPVOID);
typedef struct PARM {
     char zn;
     int nn;
     } *pPARM;

const int nano100 = 10000000;  			 

int main()  					  // Czasomierz1
{
PARM parmA={'A', 50}, parmB={'B', 50}, parmG={'*', 50};
DWORD wynikWait = 0;
UINT ID1=0, ID2=0;   
HANDLE hWA = NULL, hWB = NULL;    
HANDLE hTimer; 
LARGE_INTEGER  li;
char buf[256];

hTimer = CreateWaitableTimer(NULL, FALSE, NULL);

li.QuadPart = -5 * nano100;
SetWaitableTimer(hTimer, &li,  0,  NULL, NULL, FALSE);   Czas
    //GetTimeFormat(NULL,0,NULL,NULL,buf,255);  cout<<buf<<endl;
wynikWait = WaitForSingleObject(hTimer, INFINITE);
if (wynikWait == WAIT_OBJECT_0) 
     hWA = (HANDLE)_beginthreadex(NULL, 0, Licz, &parmA, 0, &ID1);

li.QuadPart = -10 * nano100;
SetWaitableTimer(hTimer, &li,  0,  NULL, NULL, FALSE);   Czas
    //GetTimeFormat(NULL,0,NULL,NULL,buf,255);  cout<<buf<<endl;  Czas
wynikWait = WaitForSingleObject(hTimer, INFINITE);
if (wynikWait == WAIT_OBJECT_0)  
   hWB = (HANDLE)_beginthreadex(NULL, 0, Licz, &parmB, 0, &ID2);

li.QuadPart = -20 * nano100;
SetWaitableTimer(hTimer, &li,  0,  NULL, NULL, FALSE);  Czas
   //GetTimeFormat(NULL,0,NULL,NULL,buf,255);  cout<<buf<<endl;
wynikWait = WaitForSingleObject(hTimer, INFINITE);
  if (wynikWait == WAIT_OBJECT_0) Licz(&parmG);  Czas
    //GetTimeFormat(NULL,0,NULL,NULL,buf,255);  cout<<buf<<endl;

CloseHandle(hWA); CloseHandle(hWB);
CloseHandle(hTimer); 
cout << "KONIEC."; cin.get();    
return (0);
}  

UINT WINAPI Licz(LPVOID parametr)  
{
pPARM st = (pPARM)parametr;   
char zn= st->zn; int n= st->nn;
double w = 0;;
for (int k1=0; k1 < n; k1++){   
  for (long k2=0; k2 < 10000; k2++) 
    w += cos(sin(pow(log(k2+1),2.2))); 
  cout << zn;
 } 
}

  


