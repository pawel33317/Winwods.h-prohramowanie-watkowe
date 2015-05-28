#include <cstdlib>
#include<cstring>
#include <cstdio>  
#include <cmath>
#include <conio.h>
using namespace std;

long Fib(int n)
{ if (n < 2)  return n;
   else return Fib(n - 2) + Fib(n - 1); }

int main(int argc, char *argv[])  // Fibonacci
{
char plik[33];
int nData; 
long F;
if (argc <= 1 ) { nData = 40; strcpy(plik, "E:\\Fib.asc"); }
else { nData= atoi(argv[1]), strcpy(plik, argv[2]); }
FILE *pF;
if ((pF = fopen(plik, "wt"))== NULL) {
            printf("Blad w:'%s' \n", plik);  return -1; }
for (int n=0; n <= nData; n++) {
     F = Fib(n);  
     fprintf(pF, "%9ld ", F);
     if ((n%4)==0) puts(""); 
     printf("%9ld ", F);
     }
fclose(pF);
printf("\nzapisano w pliku: %s\n", plik);
puts("\nKoniec Fibonacci- Wcisnij klawisz");
getch(); 
return 0;
}



