#include <iostream>
#include <stdio.h>
#include <conio.h>	//biblioteka do getch()

/**/
using namespace std;
int main() 
{
	char znak;
	do
	{
		cout<<"Podaj znak"<<endl;
		znak=getch();
	
		switch(znak)
		{
			case 48 ... 57	: cout<<"Wczytano cyfre"<<endl; //kody ascii od 48 do 57
					break;
			case 65 ... 90	: cout<<"Wczytano litere wielka"<<endl;
					break;
			case 97 ... 122	: cout<<"Wczytano litere mala"<<endl;
					break;
			case 32:	cout<<"Wczytano spacje"<<endl;
					break;
			case 13:	cout<<"Wczytano ENTER"<<endl;
					break;
			case 27:	cout<<"Wczytano ESC"<<endl; 
					break;
			default	: cout<<"Wczytano znak "<<znak	//pokazuje znak
					<<" o kodzie: "<<(int) znak<<endl; 	//pokazuje kod ASCII
		}
	}
	while(znak!=27);
	cout<<"nacisnij ENTER aby zakonczyc";
	getchar();
	return 0;
}