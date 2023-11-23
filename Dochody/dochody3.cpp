/*
Program prosi o podanie kolejnych dochodów miesięcznych
Na początek 12. Program wylicza łączny dochód i średni miesięczny.
ile miesięcy
*/

/*
Cel zapytaj si� ile miesi�cy
*/
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float kwota, suma, srednia;	//lub: ..., suma=0, srednia;
	int miesiac, miesiac_ile;	//lub: int miesiac=1
	
	cout<<"Program DOCHODY 1"<<endl;
	
	miesiac = 1;	//lub w doklaracji
	cout<<"Z ilu miesiecy chesz obliczyc dochod?"<<endl;
	cin>>miesiac_ile;
	
	suma = 0;		//lub w doklaracji
	do
	{
		cout<<"Podaj kwote dochodu z m-ca nr "<<miesiac<<": ";
		cin>>kwota;
		suma += kwota;
		miesiac++;
	}
	while(miesiac<=miesiac_ile); //lub miesiac<13
	srednia=suma/miesiac_ile;
	cout<<"Dochod sumaryczny ="<<suma<<endl;
	cout<<"Dochod sredni ="<<srednia<<endl;
	
	system("pause");
	return 0;
}

