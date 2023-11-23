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
	int miesiac, n;	//lub: int miesiac=1, n-liczba miesięcy
	
	cout<<"Program DOCHODY 1"<<endl;
	
	do
	{
	cout<<"Z ilu miesiecy chesz obliczyc dochod?"<<endl;
	cin>>n;
	if(n<=0)
		cout<<"ERROR miesiace musza byc wieksze od 0"<<endl;
	}
	while(n<=0);
	
	
	for(miesiac = 1;miesiac<=n;miesiac++)
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
	}
	srednia=suma/n;
	cout<<"Dochod sumaryczny ="<<suma<<endl;
	cout<<"Dochod sredni ="<<srednia<<endl;
	
	system("pause");
	return 0;
}

