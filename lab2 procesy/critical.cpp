// Critical Section synchronizuje dostêp do wspolnej tablicy
#include <iostream>         
#include <windows.h>
#include <process.h>
#include <math.h>
using namespace std;
 
UINT WINAPI GEN(LPVOID);
void Disp(int, double *, char *);

double Generuj(float a, float b) 
 { double w = (a + (b - a)*(double)rand()/RAND_MAX);    return floor(w*100+0.5)/100; } 
void ObLiCzeNia(char, int);

const int MAXDATA = 2000;
double B[2000], A[MAXDATA];        // zmienna dzielona to tablica A
    typedef struct PARM { 
float aa, bb; 
char zn; } *pPARM;

CRITICAL_SECTION cs;

int main()                                      // Critical
{
PARM parm1 = {-9.0, -1.1, 'A'}, parm2 = {11.11, 99.9, 'B'};  
UINT  ID1=0, ID2=0;
InitializeCriticalSection(&cs);
HANDLE hWA = (HANDLE)_beginthreadex(NULL, 0, GEN,  &parm1, 0, &ID1);
HANDLE hWB = (HANDLE)_beginthreadex(NULL, 0, GEN,  &parm2, 0, &ID2);
ObLiCzeNia('*', 40);
cout << "\nKoniec programu Critical1";  cin.get();
return 0;              
} 

UINT WINAPI GEN(LPVOID parametr) 
{
pPARM st = (pPARM)parametr;
float oda = st->aa,  dob = st->bb; 
char zn=st->zn;
ObLiCzeNia(zn, 10);
  EnterCriticalSection( &cs );  
     for (int i = 0; i < MAXDATA; i++) {
          for (int k=0; k<9000; k++) pow(2.2, 3.3);
          A[i] = pow(Generuj(oda, dob), 1.0);
          }
     //Disp(22, A, " ");
     cout << 22 << A << " ";
  LeaveCriticalSection( &cs );  
double w=0; 
for (int j=0; j < 2000; j++) B[j]= w +=oda;
cout << "\nKoniec Watka" << zn << ". w="<<w;
_endthreadex(0); 
}

void ObLiCzeNia(char zn, int n)  
{
double w;
for (int k1=0; k1 < n; k1++) {   
  for (long k2=0; k2<60000; k2++) w = cos(sin(pow(log(k2+1),2.2))); 
  cout << zn;
 } 
}

void Disp(int size, double *X, char *text)
{
int i;
cout << text << endl;
for (i = 0; i < size; i++) { 
  cout << X[i] << "  ";
  if ((i+1)%6 == 0) cout << endl; 
 }
 if ((i+1)%6 != 0) cout << endl;
}

void WatekGlowny(int n1, int n2, char zn)  // d³ugotrwa³e obliczenia
{
double w;
for (int k1=0; k1 < n1; k1++){   
      for (int k2=0; k2 < n2; k2++) w = pow(sin(k1),3.3)* pow(cos(k1),2.2); 
     // printf("%c", zn);
      cout << zn;
      } cin.get();
	  // puts("");
}


