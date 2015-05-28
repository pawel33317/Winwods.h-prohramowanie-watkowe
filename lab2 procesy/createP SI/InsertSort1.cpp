#include <cstdlib>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstring>
using namespace std;
void InsertSort(double *, int);
void Disp(double *, int, char *);
int SaveV(double *, int , char *);

double Generuj(float a, float b) 
 { double w = (a + (b - a)*(double)rand()/RAND_MAX); 
   return floor(w*100+0.5)/100; } 

const int MaxObieg = 5; 

int main(int argc, char *argv[]) 		 // InsertSort1.cpp
{
clock_t T1, T2; 
double Time,oda, dob; 
char name[33], gdzie[15], *s;
int k, nData;
if (argc <= 1 ) { nData = 22000; oda = 2.2; dob = 88.8; strcpy(gdzie,"E:\\dane") ;}
  else { nData= atoi(argv[1]); oda = atof(argv[2]); dob = atof(argv[3]); 
         strcpy(gdzie,argv[4]);}  
double *A = new double[nData];
for (k = 0; k < MaxObieg; k++) {
  strcpy(name, gdzie);
  for (int i = 0; i < nData; i++) A[i] = Generuj(oda, dob);
  if (k==0){ printf("Fragment Danych ( z %d):",nData); Disp(A,6, ""); }
  T1 = clock();    InsertSort(A, nData);  T2 = clock();
  Time = (T2 - T1)/(double)CLOCKS_PER_SEC;
  printf("Obieg Nr %d  czas=%g \n", k, Time);
  sprintf(s, "%d", k);  strcat(strcat(name, s),".asc"); 
  if (!SaveV(A, nData, name)) printf("zapisano w pliku: %s\n", name);
  }
Disp(A, 6, "Po Sortowaniu:" );
printf("Koniec InsertSort- Wcisnij Enter");  getchar();
delete [] A;
return 0;
}

void InsertSort(double *X, int size)
{
int i,j;
double v;
  for(i=1; i < size; i++){
    v = X[i];   j = i-1;
    while (v < X[j] && j >= 0) {
       X[j+1] = X[j];
       j--;
       }
  X[j+1] = v; 
  }
}

void Disp(double *X, int size, char *text)
{
int i;
puts(text);
for (i = 0; i < size; i++) { 
  printf("%g  ", X[i]);
  if ((i+1)%10 == 0) puts(""); 
 }
 if ((i+1)%10 != 0) puts("");
}

int SaveV(double *X, int size, char *plik)
{
FILE *pF;
if ((pF = fopen(plik, "wt"))== NULL) {
            printf("Blad w:'%s' \n", plik);
            return -1;
            }
for (int i=0; i < size; i++) fprintf(pF, "%g  ", X[i]);
fclose(pF);
return 0;
}

