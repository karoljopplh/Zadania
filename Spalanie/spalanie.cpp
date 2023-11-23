#include <iostream>
#include <cmath>

using namespace std;

/*

*/

int main() 
{
	float dystans, paliwo, spalanie;
	cout<<"Program liczy srednie spalanie"<<endl<<endl;
	do
	{
		cout<<"Podaj dystans w km: ";
		cin>>dystans;
		if(dystans<=0)
			cout<<"Zle podany dystans! Podaj jeszcze raz."<<endl;
	}
	while(dystans<=0);
	do
	{
		cout<<"Ile litrów paliwa spalono? ";
		cin>>paliwo;
		if(paliwo<=0)
			cout<<"Zle podana ilosc paliwa! Podaj jeszcze raz."<<endl;
	}
	while(paliwo<=0);
	spalanie=paliwo/dystans*100;
	cout<<"Srednie spalanie wynosi "<<spalanie<<endl;
	cout<<"KONIEC PROGRAMU"<<endl;
	system("pause");
	return 0;
}
