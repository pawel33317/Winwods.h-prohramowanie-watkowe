#include <iostream>
//CreateFile
//SetFilePointer
//ReadFile WriteFile
//GetFileSize
//VOID CopyMemory(dest, source, length)
//VOID FillMemory(dest, source, "*")
//VOID ZetoMemory(dest, length)
#include <windows.h>
#include <cmath>
#include <stdio.h>
using namespace std;
void obliczenia(int, char);

int main(int argc, char* argv[]) // pot2
{
	obliczenia(10,'*');
	
	//////////////////otwieranie !zamkniecie
	HANDLE hFile = CreateFile(
		"e:\\moje\\tekst2.txt",GENERIC_READ|GENERIC_WRITE,0,0,OPEN_EXISTING,0,0 );      					
		if(hFile == INVALID_HANDLE_VALUE){printf("CreateFile error %d.\n", GetLastError()) ;getchar(); return (1); }
	//////////////////wskaznik
	DWORD dwPtr = SetFilePointer(
		hFile,3/*do przesuniecia*/ ,0,FILE_BEGIN);
     	if(dwPtr == 0xFFFFFFFF){ printf("SetFilePointer error %d.\n", GetLastError()) ;getchar(); return (2); }
	//////////////////odczyt
	char Wy[150]; DWORD readed=0;
	BOOL bResult = ReadFile(hFile,Wy,/*tab*/150,/*bajtow do wczytania*/
		&readed,/*liczba wczytanych*/ 0) ;		
   		if(!bResult){ printf("ReadFile error %d.\n", GetLastError()) ;getchar(); return (3); }
	/////////////////ile zapisano
	if(readed == 150) printf("Pelny Odczyt zakonczony pomyslnie\n");else printf("Wczytano %d ze %d bajtow zalozonych\n", readed, 150);
	cout <<"wynik: ";puts(Wy);
	/////////////////zapis
	char We[]="lala"; DWORD writed=4;
	BOOL bResultw = WriteFile(hFile,We,/*tab*/4,/*bajtow do wczytania*/
		&writed,/*liczba wczytanych*/ 0) ;
	cout << endl  << "wielkosc pliku: " << GetFileSize(hFile,0) << endl; 
	CloseHandle(hFile);

	
	
	
	
	
	puts("\nKoniec Pot2 - Wcisnij Enter");  
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

