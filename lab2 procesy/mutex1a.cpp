#include <iostream>
#include <windows.h>
#include <process.h>
#include <conio.h>
#include <math.h>
using namespace std;

UINT WINAPI Disp(LPVOID);
void ObLiCzeNia(char, int);
char txtG[] = "glowny ", 
        txtA[] = "AAAAAAAA ", 
        txtB[] = "BBBBBBBBBBBB ";
HANDLE hMutex = NULL;

int main()   				 // Mutex1a
{
UINT     ID_A=0, ID_B=0;
DWORD wynikWait = 0;	 
 hMutex = CreateMutex(NULL, FALSE, NULL); //sygnalizowany, wolny mutex 
HANDLE hWatekA = (HANDLE)_beginthreadex(NULL, 0, Disp, txtA, 0, &ID_A);
HANDLE hWatekB = (HANDLE)_beginthreadex(NULL, 0, Disp, txtB, 0, &ID_B);
    // for (int k=0; k < 5000000; k++) (1.1/2.2);
while(1) {
     //czekanie 5 s. na zwolnienie mutexa przez watek  A lub B
   wynikWait = WaitForSingleObject(hMutex, 5000);		 
     if(wynikWait == WAIT_TIMEOUT) {
         cin.get(); cout << "Nie przechwycono mutexu w ciagu 5s.\n"; return -1; }  
                            
    for(int i = 0; txtG[i] != '\0'; i++)  cout << txtG[i] << flush;
    if (kbhit()!=0) if (getch() == 'Q' ) break;
     for (int k=0; k < 700000; k++) pow(sin(1.1),log(3.3)); //spowolnienie obiegu
	
   ReleaseMutex(hMutex);      // zwolnienie mutexu po wyswietleniu txtG  
		
    //ObLiCzeNia('*', 44);		
		}
CloseHandle(hWatekA); 
CloseHandle(hWatekB);
CloseHandle(hMutex);
cout << "\nKoniec programu Mutex1a."; 
cin.get();
return 0;
} 

UINT WINAPI Disp(LPVOID tekst)
{
LPSTR t, txt = (LPSTR)tekst;
while(1){		
   WaitForSingleObject(hMutex, INFINITE);
      for(int i = 0; *(t=(txt + i)); i++) {
           cout << *t; 
           Sleep(30); 
            }		              
   ReleaseMutex(hMutex);
   }
return 0;
} 

void ObLiCzeNia(char zn, int n)  
{
double w;
for (int k1=0; k1 < n; k1++){   
  for (long k2=0; k2<60000; k2++) 
    w = cos(sin(pow(log(k2+1),2.2))); 
  cout << zn;
 } 
}


