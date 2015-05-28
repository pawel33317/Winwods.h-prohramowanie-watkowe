#include <iostream>
#include <windows.h>
#include <cmath>
#include <stdio.h>
using namespace std;
void obliczenia(int, char);

int main(int argc, char* argv[]) // glowny
{
	cout << "GLOWNY" << endl;
	char cmd1[ ] = "pot1 2000 3.3 99.8 ";	char cmd2[ ] = "pot2 24 72";
	char cmd3[ ] = "pot3 11 43";			char cmd4[ ] = "pot4 22 33";

	STARTUPINFO si0 = {sizeof(si0), NULL,NULL,  0, 100, 370, 420, 250, 0, 0,
		0x2e,STARTF_USEFILLATTRIBUTE | STARTF_USEPOSITION | STARTF_USESIZE, 0, 0 ,NULL,NULL,NULL  };
	STARTUPINFO si1 = {sizeof(si1), NULL,NULL,  0, 535, 370, 420, 250, 0, 0,
		0x1c,STARTF_USEFILLATTRIBUTE | STARTF_USEPOSITION | STARTF_USESIZE, 0, 0 ,NULL,NULL,NULL  };
	STARTUPINFO si2 = {sizeof(si2), NULL,NULL,  0, 100, 660, 420, 250, 0, 0,
		0x05,STARTF_USEFILLATTRIBUTE | STARTF_USEPOSITION | STARTF_USESIZE, 0, 0 ,NULL,NULL,NULL  };
	STARTUPINFO si3 = {sizeof(si3), NULL,NULL,  0, 535, 660, 420, 250, 0, 0,
		0x1b,STARTF_USEFILLATTRIBUTE | STARTF_USEPOSITION | STARTF_USESIZE, 0, 0 ,NULL,NULL,NULL  };
	PROCESS_INFORMATION  pi;
	
	
	BOOL okpot1 = CreateProcess(0, cmd1, 0,0,TRUE,CREATE_NEW_CONSOLE,0,0,  &si0, &pi);
		if(!okpot1){cout << "Error create pot1:" << GetLastError();cin.get();return 1;}	
	BOOL okpot2 = CreateProcess(0, cmd2, 0,0,0,CREATE_NEW_CONSOLE,0,0,  &si1, &pi);
		if(!okpot2){cout << "Error create pot2:" << GetLastError();cin.get();return 1;}
	BOOL okpot3 = CreateProcess(0, cmd3, 0,0,0,CREATE_NEW_CONSOLE,0,0,  &si2, &pi);
		if(!okpot3){cout << "Error create pot3:" << GetLastError();cin.get();return 1;}
	BOOL okpot4 = CreateProcess(0, cmd4, 0,0,0,CREATE_NEW_CONSOLE,0,0,  &si3, &pi);
		if(!okpot4){cout << "Error create pot4:" << GetLastError();cin.get();return 1;}
			

	obliczenia(100,'#');
	puts("\nKoniec GLOWNY - Wcisnij Enter");  
	cin.get();
	return 0;	
}
void obliczenia(int n1, char zn)
{
	double w;
	for (int k1=0; k1 < n1; k1++){   
	      for (int k2=0; k2 < n1; k2++) w = pow(sin(n1),3.3)* pow(cos(k1),2.2); 
	      cout << zn << " "; Sleep(50);
	      }  puts("");
}

