#include <iostream>//////////////////DZIEDZICZENIE PRZEZ MAPOWANIE DO PROC 1 BINARNIE
//sprintf(cmd1, "Map1bDziedziczenie %d %g %g %p", nData, pocz, kon, hMapFile);
//wsprintf(bufor,"lalalal '%s' lalala",zmienna);
//proces 1 to przekazywanie przez mapowanie 
#include <windows.h>
#include <cmath>
#include <stdio.h>
using namespace std;
void obliczenia(int, char);

int main(int argc, char* argv[]) // glowny
{
	cout << "GLOWNY" << endl;
	char cmd1[ ] = "pot1 2000 3.3 99.8 ";	char cmd2[ ] = "pot2 24 22";
	char cmd3[ ] = "pot3 11 43";	char cmd4[ ] = "pot4 22 33";
	STARTUPINFO si = {0}; si.cb = sizeof(STARTUPINFO);
	PROCESS_INFORMATION  pi;
	////////////////do procesu 1;
	int nData = 2000; double pocz = 3.3, kon = 99.8;
	DWORD sizeF = nData*sizeof(double);
	HANDLE hFile = CreateFile("e:\\moje\\a\\test1.bin", GENERIC_READ|GENERIC_WRITE,0,0, CREATE_ALWAYS,0,0);
   				if (hFile == INVALID_HANDLE_VALUE) { printf("CreateFile error: %d.\n", GetLastError()); getchar(); return(1);}
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(sa); sa.lpSecurityDescriptor = NULL;sa.bInheritHandle = TRUE;   // zmiana uchwytu na dziedziczny.
	HANDLE hMapFile=CreateFileMapping (hFile, &sa, PAGE_READWRITE, 0, sizeF,  NULL);
			if(hMapFile==NULL) { printf("CreateFileMapping error: %d\n", GetLastError());   getchar(); return 1; }
	BYTE *pMapFile = (BYTE *)MapViewOfFile (hMapFile, FILE_MAP_WRITE, 0,  0,  0);	if(pMapFile==NULL) { printf("in Map1aDz MapVievOfFile error: %d\n", GetLastError()); getchar(); return 1; }
	sprintf(cmd1, "%s %p",cmd1,hMapFile);
	//////////////////////////////////////////
	/////PROCES1
	//////////////////////////////////////////
	BOOL okpot1 = CreateProcess(0, cmd1, 0,0,TRUE,CREATE_NEW_CONSOLE,0,0,  &si, &pi);
		if(!okpot1){cout << "Error create pot1:" << GetLastError();cin.get();return 1;}	
	CloseHandle(hMapFile);UnmapViewOfFile (pMapFile);  CloseHandle(hFile); 
	Sleep(2000); 
	puts("\n----odczyt z pliku dyskowego w Map1aDz:");double *B = new double[nData]; 
	FILE *pF1 = fopen("e:\\moje\\a\\test1.bin", "rb");fread(B, sizeof(double), nData, pF1); fclose(pF1);
	for (int i = 0; i < sizeof(double); i++)  printf("%6.2f ", B[i]);delete [] B;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	BOOL okpot2 = CreateProcess(0, cmd2, 0,0,0,CREATE_NEW_CONSOLE,0,0,  &si, &pi);
		if(!okpot2){cout << "Error create pot2:" << GetLastError();cin.get();return 1;}
	BOOL okpot3 = CreateProcess(0, cmd3, 0,0,0,CREATE_NEW_CONSOLE,0,0,  &si, &pi);
		if(!okpot3){cout << "Error create pot3:" << GetLastError();cin.get();return 1;}
	BOOL okpot4 = CreateProcess(0, cmd4, 0,0,0,CREATE_NEW_CONSOLE,0,0,  &si, &pi);
		if(!okpot4){cout << "Error create pot4:" << GetLastError();cin.get();return 1;}	
	obliczenia(100,'#');
	puts("\nKoniec GLOWNY - Wcisnij Enter");  
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

