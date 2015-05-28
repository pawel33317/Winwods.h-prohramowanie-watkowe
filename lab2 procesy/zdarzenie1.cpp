#include <iostream>
#include <windows.h>
#include <process.h>
#include <conio.h>
using namespace std;
UINT WINAPI Wypelniaj(LPVOID);
const int MAX = 33;

HANDLE hZMain = NULL, hZWatek = NULL;
char tabC[MAX];

int main()              // Zdarzenie1.cpp
{
UINT IDW = 0;
	  
hZMain =  CreateEvent(NULL, FALSE,  TRUE,  NULL);     // sygnalizowane
hZWatek = CreateEvent(NULL, FALSE, FALSE,  NULL);     // niesygnalizowane

HANDLE hW = (HANDLE)_beginthreadex(NULL, 0, Wypelniaj,	NULL, 0, &IDW);
for(;;){	// wpisuje zawartosc tabC
  // czekanie na zasygnalizowanie Zdarzenia hZWatek, az watek pochodny wypelni tabC
   WaitForSingleObject(hZWatek, INFINITE);
   for (int i = 0; i < MAX; i++) cout << tabC[i]; cout << endl;
   if (kbhit() != 0) if (getch() == 'Q' ) break; 
   Sleep(700);   // przerwa miêdzy wypisywaniem wierszy   
		  SetEvent(hZMain); // sygnalizacja zdarzenie hZMain, na ktore oczekuje watek pomocniczy
 } 
CloseHandle(hW); CloseHandle(hZMain);   CloseHandle(hZWatek);
return 0;
} 

UINT WINAPI Wypelniaj(LPVOID lpVoid)      // modyfikacja tablicy tabC
{
static char zn = 'A';
while (1){  
  //oczekiwanie na zasygnalizowanie hZMain tzn. az watek glowny wypisze tablice 
   WaitForSingleObject(hZMain, INFINITE);
   for(int i = 0; i < MAX; i++)	tabC[i] = zn;  //wype³nia tablice jednym znakiem	  
   SetEvent(hZWatek);// sygnalizowanie zdarzenia hZWatek, na ktore oczekuje glowny watek
   if(zn < 'Z') zn++; else zn = 'A';    // zmienia znak wypelniaj¹cy
	}
_endthreadex(0);
//return 0;
} 


