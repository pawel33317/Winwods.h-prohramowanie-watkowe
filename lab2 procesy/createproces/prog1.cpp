#include <cstdlib>      // Dev-C++ ver. 4.9.9.2
#include <iostream>  
#include <cmath>
using namespace std;

int main(int argc, char *argv[])        // Prog1
{
double x;
   if (argc < 2 ) {cout << "Brak parametrow w " << *argv; 
                   cout << endl; cin.get(); return -1; }
for (int i=1; i < argc; i++) {
     x = atof(argv[i]);  // konwersja ³añcucha na liczbê
     cout <<  "sqrt(" << x << ") = " << sqrt(x) << endl;
     }
cout << "Koniec Prog1- Wcisnij klawisz \n";
cin.get();  
return 0;
}


