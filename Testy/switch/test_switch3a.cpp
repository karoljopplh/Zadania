#include <iostream>
#include <conio.h>	//biblioteka do getch()

/**/
using namespace std;
int main() 
{
	char znak;
	cout<<"Podaj wartosc (a, b lub c)"<<endl;
	znak=getch();
	switch(znak)
	{
		case 'a': cout<<"Wczytano a"<<endl;
				break;
		case 'b': cout<<"Wczytano b"<<endl;
				break;
		case 'c': cout<<"Wczytano c"<<endl;
				break;
		case 27	: cout<<"ESC"<<endl;
				break;
		default: cout<<"Wczytano cos innego"<<endl;
	}
	cout<<"nacisnij ENTER aby zakonczyc";
	getchar();
	return 0;
}