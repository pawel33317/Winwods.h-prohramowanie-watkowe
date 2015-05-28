#include<stdio.h>           // mapowanie pliku danych w przestrzeni procesu
#include<windows.h>

int main()         // Mapp2
{
char str[3][7],*s;
FILE *pF = fopen("e:\\moje\\tekst4.txt", "w"); fputs("abcdefghijklmnoprstuvwz", pF); fclose(pF);
//DWORD sizeF = 30; 
int size = sizeof(str[0])-1, i;        

	HANDLE hFile = CreateFile("e:\\moje\\tekst4.txt", GENERIC_READ|GENERIC_WRITE,0,0, OPEN_ALWAYS,0,0);
   			if (hFile == INVALID_HANDLE_VALUE) { printf("CreateFile error: %d.\n", GetLastError()); getchar(); return(1);}
	
	DWORD sizeF=GetFileSize(hFile, 0); printf("sizeFile = %d\n", sizeF);
	
	HANDLE hMapFile=CreateFileMapping (hFile, NULL, PAGE_READWRITE, 0, sizeF+8,  NULL);
			if(hMapFile==NULL) { printf("CreateFileMapping error: %d\n", GetLastError());  getchar(); return 1; }

	// Przydzielenie obszaru PAO na odwzorowanie pliku
	char * pMapFile = (char *)MapViewOfFile (hMapFile, FILE_MAP_ALL_ACCESS, 0,  0,  0);
	puts(pMapFile);  

	// Odczyt danych z pliku (z PAO) i umieszczenie ich w tablicy
	for (i=0; i<3; i++){ memcpy(str[i], pMapFile+i*size, size);  str[i][6]='\0'; }	
	printf("\nDane ze zmapowanego pliku:\n"); for (i=0; i<3; i++) puts(str[i]);

	// zmiana danych w pliku poprzez bezposredni zapis do PAO
	strncpy(str[1],"123456", 6);
	memcpy(pMapFile+1*size, str[1], size);

UnmapViewOfFile (pMapFile);
CloseHandle(hFile); CloseHandle(hMapFile);
puts("----odczyt z pliku dyskowego:");
char zn;
FILE *pF1 = fopen("e:\\moje\\tekst4.txt", "r");
while ((zn=getc(pF1)) !=EOF) putc(zn, stdout); fclose(pF1);	

getchar(); 
return 0;
}


