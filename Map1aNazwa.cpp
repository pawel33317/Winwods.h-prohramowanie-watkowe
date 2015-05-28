#include<stdio.h>           // wspoldzielenie przez nazwe pliku danych
#include<windows.h>

int main(void)         // Map1aNazwa
{
HANDLE hFile = NULL, hMapFile = NULL;	
char str[3][7], nameF[30] = "nowy.txt";
FILE *pF = fopen(nameF, "w"); fputs("abcdefghijklmnoprstuvwz", pF); fclose(pF);
DWORD sizeF = 30; 
int size = sizeof str[0] - 1, i;        

hFile = CreateFile(nameF, GENERIC_READ|GENERIC_WRITE,0,0, OPEN_ALWAYS,0,0);
   if (hFile == INVALID_HANDLE_VALUE) { 
      printf("CreateFile error: %d.\n", GetLastError()); getchar(); return(1);}

hMapFile=CreateFileMapping (hFile, NULL, PAGE_READWRITE, 0, sizeF,  "Alfa1");
	if(hMapFile==NULL) { printf("CreateFileMapping error: %d\n", GetLastError()); 
                         getchar(); return 1; }
	// Przydzielenie obszaru PAO na odwzorowanie pliku
char *pMapFile = (char *)MapViewOfFile (hMapFile, FILE_MAP_ALL_ACCESS, 0,  0,  0);

	// Odczyt danych z pliku (z PAO) i umieszczenie ich w tablicy
for (i=0; i<3; i++){ memcpy(str[i], pMapFile+i*size, size);  str[i][6]='\0'; }	
printf("\nDane ze zmapowanego pliku:\n"); for (i=0; i<3; i++) puts(str[i]);

STARTUPINFO si = {0};  si.cb = sizeof(STARTUPINFO);  PROCESS_INFORMATION  pi;
CreateProcess(0,  "Map1bNazwa  Create ",  0,0,0,CREATE_NEW_CONSOLE,0,0,  &si, &pi);
Sleep(1000);

UnmapViewOfFile (pMapFile);
CloseHandle(hFile); CloseHandle(hMapFile);
puts("----odczyt z pliku dyskowego przez Map1aNazwa:");
char zn;  FILE *pF1 = fopen(nameF, "r");
while ((zn=getc(pF1)) !=EOF) putc(zn, stdout); fclose(pF1);	

getchar(); return 0;
}


