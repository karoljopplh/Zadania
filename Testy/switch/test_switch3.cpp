#include <iostream>

/**/
using namespace std;
int main() 
{
	char znak;
	cout<<"Podaj wartosc (a-d)"<<endl;
	cin>>znak;
	switch(znak)
	{
		case 'a': cout<<"Wczytano a"<<endl;
				break;
		case 'b': cout<<"Wczytano b"<<endl;
				break;
		case 'c': cout<<"Wczytano c"<<endl;
				break;
		case 'd': cout<<"Wczytano d"<<endl;
				break;
		default: cout<<"Wczytano cos innego"<<endl;
	}
	cout<<"nacisnij ENTER aby zakonczyc";
	getchar();
	return 0;
}