/*
Program prosi o podanie kolejnych dochodĂłw miesiÄ™cznych
Na poczÄ…tek 12. Program wylicza Ĺ‚Ä…czny dochĂłd i Ĺ›redni miesiÄ™czny.
ile miesiÄ™cy
*/

/*
Cel zapytaj się ile miesięcy
*/

/*
Program przerobiony aby stosował tablicę
*/
#include <iostream>
#include <cmath>
#define N 7		//liczba miesięcy i... rozmiar tablicy(powiększymy go o 1)

using namespace std;

int main()
{
	float kwota[N+1], suma, srednia;	//tablica powiększona o 1
	int miesiac, n;
	
	cout<<"Program DOCHODY NA TABLICY"<<endl;
	
	/*do
	{
	cout<<"Z ilu miesiecy chesz obliczyc dochod?"<<endl;
	cin>>n;
	if(n<=0)
		cout<<"ERROR miesiace musza byc wieksze od 0"<<endl;
	}
	while(n<=0);
	*/
	suma=0;
	for(miesiac = 1;miesiac<=N;miesiac++)
	{
		do
		{
			cout<<"Podaj kwote dochodu z m-ca nr "<<miesiac<<": ";
			cin>>kwota[miesiac];
			if(kwota<0)
				cout<<"Kwota nie moze byc ujemna. Podaj ponownie"<<endl;
		}
		while(kwota[miesiac]<0);
		suma += kwota[miesiac];
	}
	srednia=suma/N;
	cout<<"Dochod sumaryczny ="<<suma<<endl;
	cout<<"Dochod sredni ="<<srednia<<endl;
	
	system("pause");
	return 0;
}

