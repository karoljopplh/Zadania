/*
Program prosi o podanie kolejnych dochodĂłw miesiÄ™cznych
Na poczÄ…tek 12. Program wylicza Ĺ‚Ä…czny dochĂłd i Ĺ›redni miesiÄ™czny.
ile miesiÄ™cy
*/

/*
Program przerobiony aby stosował tablicę z użyciem od 0
W wersji 5 dorobiemy wyszukiwanie dochodu
*/
#include <iostream>
#include <cmath>
#define N 7		//liczba miesięcy i... rozmiar tablicy

using namespace std;

int main()
{
	float suma, srednia;
	int miesiac, n;
	
	cout<<"Program DOCHODY NA TABLICY"<<endl;
	
	do
	{
		cout<<"Z ilu miesiecy chesz obliczyc dochod?"<<endl;
		cin>>n;
		if(n<=0)
			cout<<"ERROR miesiace musza byc wieksze od 0"<<endl;
		if(n>100)
			cout<<"ERROR miesiace nie moga przekraczać liczby 100"<<endl;
	}
	while(n<=0 || n>100);
	
	float kwota[n];
	suma=0;
	
	for(miesiac = 0;miesiac<n;miesiac++)
	{
		do
		{
			cout<<"Podaj kwote dochodu z m-ca nr "<<miesiac+1<<": ";
			cin>>kwota[miesiac];
			if(kwota[miesiac]<0)
				cout<<"Kwota nie moze byc ujemna. Podaj ponownie"<<endl;
		}
		while(kwota[miesiac]<0);
		suma += kwota[miesiac];
	}
	
	
	cout<<endl<<"Listing kontrolny od ty�u"<<endl;
	for(miesiac=n-1;miesiac>=0;miesiac--)
		{
			cout<<"W miesiacu nr "<<miesiac+1<<" = "<<kwota[miesiac]<<endl;
		}
	
	for(miesiac=0;miesiac<n;miesiac++)
		suma+=kwota[miesiac];
	
	srednia=suma/n;
	cout<<"Dochod sumaryczny ="<<suma<<endl;
	cout<<"Dochod sredni ="<<srednia<<endl;
	
	//U�ytkownik podaje warto�c szukanej a program przeszukuj�c tablic� wypisuje te miesi�ce (nr) w kt�rych szukany doch�d wyst�pi�.
	//Gdyby jednak nie wyst�pi� ani razu to program wypisuje stosowny komunikat
	cout<<endl<<"TERAZ WYSZUKIWANIE DOCHODU:"<<endl;	
	
	system("pause");
	return 0;
}

