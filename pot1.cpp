//otwarcie notatnikiem
//argv
//fopen
//
//
#include <iostream>
#include <windows.h>
#include <cmath>
#include <stdio.h>
using namespace std;
void obliczenia(int, char);

int main(int argc, char* argv[]) // pot1
{
	cout << "POT1" << endl;
	obliczenia(10,'$');
/////////////////////////////////////otwarcie notatnikiem	
	char linia[] = "notepad e:\\moje\\tekst.txt";
	STARTUPINFO si = {0}; si.cb = sizeof(STARTUPINFO);
	PROCESS_INFORMATION  pi;
	
	BOOL okpot1 = CreateProcess(0, linia, 0,0,0,CREATE_NEW_CONSOLE,0,0,  &si, &pi);
		if(!okpot1){cout << "Error create pot1:" << GetLastError();cin.get();return 1;}
/////////////////////////////////////argv	
	if (argc<=1){cout << "blad brak parametrow"; cin.get();return 1;}
	for(int i=0;i<argc;i++)cout << "Parametr" << i << ": " << argv[i] << endl;	
		int x = atof(argv[2]);cout << endl << x << endl;
////////////////////////////////////fopen
	////////odczyt intow
	FILE *pF = fopen("e:\\moje\\tekst.txt", "rt");  long F;
	while (!feof(pF)) { fscanf(pF, "%ld", &F); printf("%ld ", F); }
	fclose(pF);
	////////

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

