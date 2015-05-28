//mapowanie
//odczyt windowsem
//odczyt c
#include <iostream>
#include <windows.h>
#include <cmath>
#include <stdio.h>
using namespace std;
void obliczenia(int, char);

int main(int argc, char* argv[]) // pot3
{
	obliczenia(10,'@');
	
	char buf[35] ;FillMemory(buf, 35, '*');puts("Podaj tekst do zapisania:");   gets(buf); 
	HANDLE f = CreateFile("e:\\moje\\tekst3.txt", GENERIC_READ|GENERIC_WRITE,0,0,CREATE_ALWAYS,0,0);
	//--------------Utworzenie obiektu reprezentujacego plik zmapowany
	HANDLE fm = CreateFileMapping(
    	f,NULL,PAGE_READWRITE,0,/*maly*/sizeof(buf),NULL ); 
	//-------Przydzielenie obszaru w PAO na odwzorowanie pliku 
	char* pb = (char*)MapViewOfFile(
    	fm,	FILE_MAP_WRITE, 0/*maly*/,0/*od poczatku*/,0/*caly*/);
    	
	CopyMemory(pb, buf, sizeof(buf));       // bezposredni zapis do PAO
	memcpy(pb + 12, "123456", 9);           // bezposredni zapis do PAO
	UnmapViewOfFile((void *)pb);CloseHandle(fm);  CloseHandle(f);

	puts("---------Odczyt funkcjami systemu Windows:");     
	f = CreateFile("e:\\moje\\tekst3.txt", GENERIC_READ|GENERIC_WRITE, 0,0, OPEN_EXISTING, 0,0);
	fm = CreateFileMapping(f,0,PAGE_READWRITE,0,0,NULL);
	pb = (char*)MapViewOfFile(fm, FILE_MAP_READ,0,0,0); 
	puts(pb);          
	UnmapViewOfFile((void *)pb);
	CloseHandle(fm);   CloseHandle(f);

	puts("---------Odczyt funkcjami jezyka C++");
	char zn;  
	FILE *pF = fopen("e:\\moje\\tekst3.txt", "r");
	while ((zn=getc(pF)) !=EOF) putc(zn, stdout); 
	fclose(pF);
	
	puts("\nKoniec Pot3 - Wcisnij Enter");  
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

