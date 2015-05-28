#include <iostream>
#include <windows.h>
using namespace std;

int main(int argc, char* argv[]) // Proces1
{
char cmd1[ ] = "prog1 ";
char cmd2[ ] = "prog1    24  225  81";
char cmd3[ ] = "explorer";
   
//minimalne parametry startowe
   STARTUPINFO si = {0};
    si.cb = sizeof(STARTUPINFO);
	
	//trzeba zaalokowaæ 
    PROCESS_INFORMATION  pi;
	
	
	//L2S 22 24
	
	
CreateProcess(
0, //nazwa pliku
cmd1, //nazwa + parametry zaklada ze .exe
0, //bezpieczenstwo proces
0,	//bezpieczenstwo thread
0, //wspó³praca z bezpieczenstwem czyli dwoma poprzzednimi
0, //flagi na proces twozenia np zawieszony bez pokazania okna
0, //blok pamieci napisy srodowiekowe NULL zwykle
0,  //pozwala procesowi nadrzednemu ustawic katalog i napêd
&si, //parametry startowe
&pi
);
CreateProcess(0, cmd2, 0,0,0,0,0,0,  &si, &pi);
CreateProcess(0, cmd3, 0,0,0,0,0,0,  &si, &pi);
// wypisuje parametry programu Proces1
	cout << "Parametry wywolania programu:" << endl;
	for(int i = 0; i < argc; i++)
		cout << "argv[" << i << "] -> " << argv[i] << endl;
cout << "Koniec MAIN- Wcisnij Enter \n"; cin.get();
return 0;
}


