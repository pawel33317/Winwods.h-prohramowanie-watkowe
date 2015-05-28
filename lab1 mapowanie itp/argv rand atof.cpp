#include<cstdlib>
#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;
int main(int argc, char *argv[])
{
	int i;
	for(i=0;i<argc;i++)cout << i << ". " << argv[i] << endl;	//wypisuje parametry przekazane do programu np. main.exe aaa bbb ccc
	for(i=0;i<5;i++){double ff; ff=rand()%9+1; ff=ff/10; cout << i << ". " << ff << endl;} //generuje liczby z przedzia³u 0.1 do 0.9
	char zz[] = "555"; int zzz=atof(zz); cout << zzz << "  " << zz << endl; // zamienia chara na liczbe
	cin.get();
	return 0;
}
