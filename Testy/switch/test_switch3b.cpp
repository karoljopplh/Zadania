#include <iostream>
#include <conio.h>	//biblioteka do getch()

/**/
using namespace std;
int main() 
{
	char znak;
	cout<<"Podaj znak (ESC, space, ENTER, backspace)"<<endl;
	znak=getch();
	switch(znak)
	{
		case 27	: cout<<"Wczytano ESC"<<endl; //numery ascii 27 == ESC
				break;
		case 32	: cout<<"Wczytano spacje"<<endl;
				break;
		case 13	: cout<<"Wczytano ENTER"<<endl;
				break;
		case 8	: cout<<"Wczytano backspace"<<endl;
				break;
		default	: cout<<"Wczytano znak "<<znak	//pokazuje znak
				<<" o kodzie: "<<(int) znak<<endl; 	//pokazuje kod ASCII
	}
	cout<<"nacisnij ENTER aby zakonczyc";
	getchar();
	return 0;
}