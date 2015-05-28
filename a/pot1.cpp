//dziedziczenie przez mapowanie
#include <iostream>
#include <windows.h>
#include <cmath>
#include <stdio.h>
using namespace std;
void obliczenia(int, char);
int main(int argc, char* argv[]) // pot1
{
HANDLE hMapFile;

if (argc <= 1 ) { puts("Brak Danych"); return 10; }
 else {sscanf(argv[4], "%p", &hMapFile);} // pobranie wartoœci uchwytu od rodzica 

BYTE *pMapFile = (BYTE *)MapViewOfFile(hMapFile, FILE_MAP_WRITE, 0,0, 0);
	if(pMapFile==NULL) { printf("in Map1bDz MapVievOfFile error: %d\n", GetLastError()); getchar(); return 1; }
                        
	puts("  -->zapis Danych do pliku mapowanego");
	double A[22]={112,243.5,3.2,43.5,3.2,4.5,3.2,4.56,3.2,
	4.6,3.3,65.4,2.5,3,4.6,3.4,6.4,3.7,4.5,7.4,65.7};
	memcpy(pMapFile, A, 22*sizeof(double));
	for(int i=0;i<21;i++)cout << A[i] <<" ";
UnmapViewOfFile(pMapFile);CloseHandle(hMapFile);

	puts("\nKoniec Pot1 - Wcisnij Enter");  
	cin.get();
	return 0;	
}
void obliczenia(int n1, char zn)       // d³ugotrwa³e obliczenia
{
	double w;
	for (int k1=0; k1 < n1; k1++){   
	      for (int k2=0; k2 < n1; k2++) w = pow(sin(n1),3.3)* pow(cos(k1),2.2); 
	      cout << zn << " "; Sleep(50);
	      }  puts("");
}

