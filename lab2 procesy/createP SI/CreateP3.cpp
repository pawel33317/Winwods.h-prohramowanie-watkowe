#include<windows.h>
#include<math.h>
#include <stdio.h> 
void ProgramGlowny(int, char);

int main(int argc, char *argv[]) 		 // CreateP3.cpp
{
PROCESS_INFORMATION pi1, pi2;
char cmd1[80] = "InsertSort1  25000 5.5 66.6 E:\\dane";
STARTUPINFO si1 = {
   sizeof(si1), //sizeof
   NULL,//null
   NULL,  //null ustawia na pulpit
   "InsertSort1",//tytul okna konsolowego
    500, //wspó³rzedne x okna procesu
	370, //y
	420, //szerokosc okna
	250, //wysokosc
        0,//szerokosc znaku
		0,//wys
        0xf2,                   // kolor tekstu i t³a
        STARTF_USEFILLATTRIBUTE | STARTF_USEPOSITION | STARTF_USESIZE, //konieczne ustawia parametru które beda wykorzystane l2s24
        0, //sposob wyswietlania pierwszego okna procesu potomnego
		0 ,//0
		NULL,//null
		NULL,//
		NULL  //null uchwyt bufora konsolowego na strumien wyjscia wejscia
		};

char cmd2[80] = "Fibonacci  30  E:\\Fib.asc";
STARTUPINFO si2 = {
   sizeof(si2), NULL,NULL,  "Fibonacci", 40, 370, 420, 280, 0, 0,
        0xe3,                   // fill attribute
        STARTF_USEFILLATTRIBUTE | STARTF_USEPOSITION | STARTF_USESIZE, 
        0, 0,NULL,NULL,NULL  };

CreateProcess(0, cmd1, NULL,NULL,0, CREATE_NEW_CONSOLE, NULL,NULL, &si1, &pi1);
CreateProcess(0, cmd2, NULL,NULL,0, CREATE_NEW_CONSOLE, NULL,NULL, &si2, &pi2);

ProgramGlowny(260, '*'); 
puts("---------Odczyt z dysku wynikow dzialania programu Fibonacci.exe------");
long F;
FILE *pF = fopen("E:\\Fib.asc", "rt");  
while (!feof(pF)) { fscanf(pF, "%ld", &F); printf("%ld ", F); }
fclose(pF);
puts("\nKoniec MAIN - Wcisnij Enter");  
getchar();
return 0;
}

void ProgramGlowny(int n, char zn)        // d³ugotrwa³e obliczenia
{
double w;
for (int k1=0; k1 < n; k1++){   
      for (int k2=0; k2 < 20000; k2++) w = pow(sin(k1),3.3)* pow(cos(k1),2.2); 
      printf("%c ", zn);
      } puts("");
}





