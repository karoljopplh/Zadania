/*
Program prosi o podanie kolejnych dochodÄ‚Ĺ‚w miesiĂ„â„˘cznych
Na poczĂ„â€¦tek 12. Program wylicza Äąâ€šĂ„â€¦czny dochÄ‚Ĺ‚d i Äąâ€şredni miesiĂ„â„˘czny.
ile miesiĂ„â„˘cy
*/

/*
Program przerobiony aby stosowaĹ‚ tablicÄ™ z uĹĽyciem od 0
W wersji 5 dorobiemy wyszukiwanie dochodu
*/
#include <iostream>
#include <cmath>
#define N 7		//liczba miesiÄ™cy i... rozmiar tablicy

using namespace std;

int main()
{
	float suma, srednia, szukana;
	int miesiac, n;
	
	
	cout<<"Program DOCHODY NA TABLICY"<<endl;
	
	do
	{
		cout<<"Z ilu miesiecy chesz obliczyc dochod?"<<endl;
		cin>>n;
		if(n<=0)
			cout<<"ERROR miesiace musza byc wieksze od 0"<<endl;
		if(n>100)
			cout<<"ERROR miesiace nie moga przekraczaÄ‡ liczby 100"<<endl;
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
		//suma += kwota[miesiac];
	}
	cout<<endl<<"Listing kontrolny"<<endl;
	for(miesiac=0;miesiac<n;miesiac++)
		{
			cout<<"W miesiacu nr "<<miesiac+1<<" = "<<kwota[miesiac]<<endl;
		}
	
	cout<<endl<<"Listing kontrolny od tyłu"<<endl;
	for(miesiac=n-1;miesiac>=0;miesiac--)
		{
			cout<<"W miesiacu nr "<<miesiac+1<<" = "<<kwota[miesiac]<<endl;
		}
	
	for(miesiac=0;miesiac<n;miesiac++)
		suma+=kwota[miesiac];
	
	srednia=suma/n;
	cout<<"Dochod sumaryczny ="<<suma<<endl;
	cout<<"Dochod sredni ="<<srednia<<endl;
	
	//Użytkownik podaje wartośc szukanej a program przeszukując tablicę wypisuje te miesiące (nr) w których szukany dochód wystąpił.
	//Gdyby jednak nie wystąpił ani razu to program wypisuje stosowny komunikat
	
	cout<<endl<<"TERAZ WYSZUKIWANIE DOCHODU:"<<endl;
	do
	{
	cout<<"Podaj szukana kwote"<<endl;
	cin>>szukana;
	if(szukana<0)
		cout<<"Szukana nie może być ujemna"<<endl;
	}
	while(szukana<0);
	bool znaleziono = false;	//albo znaleziono=0	
	for(miesiac=0;miesiac<n;miesiac++)
	{
		if(kwota[miesiac]==szukana)
		{
			znaleziono = true;
			cout<<"Znaleziono w miesiacu nr "<<miesiac+1<<endl;
		}
	}
	
	if(!znaleziono)
		cout<<"Nie znaleziono szukanego dochodu"<<endl;
	
	cout<<endl<<"Poniżej szukamy przedziału <a,b>"<<endl;
	/*
	Użytkownik podaje dolny i górny kres szukanego przedziału domkniętego.
	Gdy przedział źle podany musi podać ponownie.
	W przypadku znalezienia program wypisuje w którym miesiącu jaką kwotę znaleziono.
	Na koniec wypisujemy ile znaleziono albo że w ogóle nie znaleziono.
	*/
	float p1, p2;
	int ile_z = 0;
	znaleziono = false;
	do
	{
		do
		{
		cout<<"Podaj początek przedziału"<<endl;
		cin>>p1;
		if(p1<0)
			cout<<"Przedział nie może być ujemny"<<endl;
		}
		while(p1<0);
		
		do
		{
		cout<<"Podaj koniec przedziału"<<endl;
		cin>>p2;
		if(p2<0)
			cout<<"Przedział nie może być ujemny"<<endl;
		}
		while(p2<0);
		
		if(p1>p2)
			cout<<"ERROR"<<endl;
	}
	while(p1>p2);
	
	for(miesiac=0;miesiac<n;miesiac++)
	{
		if(kwota[miesiac]>=p1 && kwota[miesiac]<=p2)
		{
			znaleziono = true;
			cout<<"Znaleziono w miesiacu nr "<<miesiac+1<<" kwote:"<<kwota[miesiac]<<endl;
			ile_z++;
		}
	}
	if(ile_z==1)
		cout<<"Znaleziono "<<ile_z<<" wynik"<<endl;
	else if((ile_z%10)>1 && (ile_z%10)<5 && (ile_z>21 || ile_z<10))
		cout<<"Znaleziono "<<ile_z<<" wyniki"<<endl;
	else//(ile_z>0)
		cout<<"Znaleziono "<<ile_z<<" wynikow"<<endl;
	
	if(!znaleziono)
		cout<<"Nie znaleziono szukanego dochodu"<<endl;
	
	/*
	Poniżej nastąpi odwrócenie kolejności danych w tablicy i kontrolny listing.
	Dodeklarowac zmienną pomocniczą.
	*/
	if(n%2==1)
	{
	for(int i=0, j=n-1;)
	}
	
	system("pause");
	return 0;
}