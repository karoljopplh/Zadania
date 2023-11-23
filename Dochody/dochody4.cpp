/*
Program prosi o podanie kolejnych dochodĂłw miesiÄ™cznych
Na poczÄ…tek 12. Program wylicza Ĺ‚Ä…czny dochĂłd i Ĺ›redni miesiÄ™czny.
ile miesiÄ™cy
*/

/*
Cel zapytaj się ile miesięcy
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
		do
		{
			cout<<"Podaj kwote dochodu z m-ca nr "<<miesiac<<": ";
			cin>>kwota;
			if(kwota<0)
				cout<<"Kwota nie moze byc ujemna. Podaj ponownie"<<endl;
		}
		while(kwota<0);
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

