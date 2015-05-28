#include <windows.h>		     // mapowanie pliku w przestrzeni procesu, przed jego zapisaniem
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()   										// Mapp1
{
char buf[35];   char nameF[30] = "nowy.txt", *pb ;
FillMemory(buf, 35, '*');						// inicjowanie bufora
cout << buf << endl << endl;
puts("Podaj tekst do zapisania:");   gets(buf); 
// ----------- Utworzenie ObiektuPliku w j¹drze 
 HANDLE  f = CreateFile(nameF, GENERIC_READ|GENERIC_WRITE,0,0,CREATE_ALWAYS,0,0);
//--------------Utworzenie obiektu reprezentujacego plik zmapowany
HANDLE fm = CreateFileMapping(
    f,				 	    // wskaznik na ObiektPlikowy od  CreateFile
    NULL,					// standardowe atrybuty bezpieczenstwa
    PAGE_READWRITE,		    // czytanie i pisanie (powiazany z 2-gim param. CreateFile)
    0,					    // maly plik
    sizeof(buf),			// rozmiar pliku
    NULL );				    // bez wlasnej nazwy 
//-------Przydzielenie obszaru w PAO na odwzorowanie pliku 
pb = (char*)MapViewOfFile(
    fm,					       // uchwyt zwrócony przez  CreateFileMapping
    FILE_MAP_WRITE,			   // tylko do pisania
    0,					       // maly plik
    0,					       // mapowanie od poczatek pliku
    0  );					   // mapowania calego pliku
CopyMemory(pb, buf, sizeof(buf));       // bezposredni zapis do PAO
memcpy(pb + 12, "123456", 7);           // bezposredni zapis do PAO //trzeci parametr bajtow do skopiowania
UnmapViewOfFile((void *)pb);            // zwolnienie pamieci przeznaczonej na odwzorowanie pliku
CloseHandle(fm);   CloseHandle(f);       // zamkniecie uchwytow do Obiektów j¹dra

puts("---------Odczyt funkcjami systemu Windows:");    //napotka 0 i lipa 
f = CreateFile(nameF, GENERIC_READ|GENERIC_WRITE, 0,0, OPEN_EXISTING, 0,0);
fm = CreateFileMapping(f,0,PAGE_READWRITE,0,0,NULL);
pb = (char*)MapViewOfFile(fm, FILE_MAP_READ,0,0,0); 
puts(pb);          
UnmapViewOfFile((void *)pb);
CloseHandle(fm);   CloseHandle(f);


puts("---------Odczyt funkcjami jezyka C++");
char zn;  
FILE *pF = fopen(nameF, "r");
while ((zn=getc(pF)) !=EOF) putc(zn, stdout); 
fclose(pF);
getchar();   
return 0;
}

