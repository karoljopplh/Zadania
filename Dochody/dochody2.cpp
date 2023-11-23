/*
Program prosi o podanie kolejnych dochodów miesięcznych
Na początek 12. Program wylicza łączny dochód i średni miesięczny.
ile miesięcy
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float kwota, suma, srednia;	//lub: ..., suma=0, srednia;
	int miesiac;	//lub: int miesiac=1
	
	cout<<"Program DOCHODY 1"<<endl;
	miesiac = 1;	//lub w doklaracji
	suma = 0;		//lub w doklaracji
	do
	{
		cout<<"Podaj kwote dochodu z m-ca nr "<<miesiac<<": ";
		cin>>kwota;
		suma += kwota;
		miesiac++;
	}
	while(miesiac<=12); //lub miesiac<13
	srednia=suma/12;
	cout<<"Dochod sumaryczny ="<<suma<<endl;
	cout<<"Dochod sredni ="<<srednia<<endl;
	
	system("pause");
	return 0;
}