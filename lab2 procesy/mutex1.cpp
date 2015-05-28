#include <iostream>
#include <windows.h>
#include <process.h>
#include <cmath>
using namespace std;
const int MAX = 5;          // krotnosc wyswietlanych lancuchow
UINT WINAPI DispA(LPVOID);
UINT WINAPI DispB(LPVOID);
void OBLICZENIA(char, int);
HANDLE hMutex = NULL;
char txtA[] = "AAAAAAAA ", txtB[] = "BBBBBBBBBBBB ";

int main()       			         // Mutex1
{
UINT     ID_A=0, ID_B=0;
hMutex = CreateMutex(NULL, FALSE, NULL);      // mutex sygnalizowany -> FALSE

HANDLE hWatekA = (HANDLE)_beginthreadex(NULL, 0, DispA, txtA, 0, &ID_A);
HANDLE hWatekB = (HANDLE)_beginthreadex(NULL, 0, DispB, txtB, 0, &ID_B);

OBLICZENIA('*', 70);

CloseHandle(hMutex);
cin.get();
return 0;              
} 

UINT WINAPI DispA(LPVOID tekst)
{
char t, *txt = (LPSTR)tekst;
for(int i=0; i < MAX; i++){		
 OBLICZENIA('1', 6);		            
  WaitForSingleObject(hMutex, INFINITE);  	cout << endl;	                // Czekaj(mutex)
     for(int k=0; (t = *(txt + k)); k++) cout << t;      // Sekcja Krytyczna
  ReleaseMutex(hMutex);                          // Sygnalizuj(mutex), zwalnia
 OBLICZENIA('a', 10);  // -------Reszta Kodu  	
  } 
cout << "Koniec1"; 
_endthreadex(0);
} 

UINT WINAPI DispB(LPVOID tekst)
{
LPSTR txt = (LPSTR)tekst;
for(int i=0; i < MAX; i++){		
  OBLICZENIA('2', 4);	cout << endl;	            
  WaitForSingleObject(hMutex, INFINITE);
    for(int i = 0; *(txt + i); i++) cout << *(txt + i); 
  ReleaseMutex(hMutex);
  OBLICZENIA('b', 8);
} 
cout << "Koniec2";  
_endthreadex(0); 
} 


void OBLICZENIA(char zn, int n)  
{
double w;
for (int k1=0; k1 < n; k1++){   
  for (long k2=0; k2<60000; k2++) w = cos(sin(pow(log(k2+1),2.2))); 
  cout << zn;
 } 
}




