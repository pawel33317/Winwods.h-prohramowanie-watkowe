#include <windows.h>
#include <conio.h>
#include <stdio.h>

int main()     					  // Semafor1
{
char zn;
HANDLE hSemafor = NULL;  
DWORD hWynik = 0;
WORD LicznikOdwolan = 0;
hSemafor = CreateSemaphore(NULL, 3, 3, NULL);
while(1){  // wypisuje tekst za kazdym razem gdy uda sie jej przejac semafor
		// oczekujemy na sygnalizacje semafora, nastapi to
		// gdy wartosc jego licznika bedzie wieksza od zera
 hWynik = WaitForSingleObject(hSemafor, 50);
	// jezeli oczekiwanie na semafor zakonczylo sie sukcesem
		// zostala zwrocona wartosc WAIT_OBJECT_0, jego licznik
		// jest zmniejszany o jeden a my wypisujemy tekst
		// okreslajacy numer przejecia semafora
 if(hWynik == WAIT_OBJECT_0) printf("odwolanie%i ", LicznikOdwolan++);
   if(kbhit() != 0) {
     switch(zn = getch()) {
       case 'Q': goto KONIEC;
	// jezeli nacisnieto 1 zwalniamy semafor zwiekszajac jego licznik o 1
      case '1': ReleaseSemaphore(hSemafor, 1, NULL); break;
    // jezeli nacisnieto 2 zwalniamy semafor zwiekszajac jego licznik o 2
      case '2': ReleaseSemaphore(hSemafor, 2, NULL);  break;
      case '3': ReleaseSemaphore(hSemafor, 3, NULL); break;
      case '4': ReleaseSemaphore(hSemafor, 4, NULL);  break;
      }
	} // koniec if(kbhit() != 0)
  } 
KONIEC: CloseHandle(hSemafor);
puts("KONIEC");
getch();
return 0;
}


