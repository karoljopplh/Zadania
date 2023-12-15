#include <iostream>
#include <conio.h>	//biblioteka do getch()

/**/
using namespace std;
int main() 
{
	char znak;
	cout<<"Podaj znak"<<endl;
	znak=getch();
	switch(znak)
	{
		case 48 ... 57	: cout<<"Wczytano cyfre"<<endl; //numery ascii 27 == ESC
				break;
		case 65 ... 90	: cout<<"Wczytano litere wielka"<<endl;
				break;
		case 97 ... 122	: cout<<"Wczytano litere mala"<<endl;
				break;
		default	: cout<<"Wczytano znak "<<znak	//pokazuje znak
				<<" o kodzie: "<<(int) znak<<endl; 	//pokazuje kod ASCII
	}
	cout<<"nacisnij ENTER aby zakonczyc";
	getchar();
	return 0;
}