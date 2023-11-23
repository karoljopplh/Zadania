/*
Program ma wyliczać serię energii kinetycznej. (m*v^2)/2
Użytkownik podaję masę w kilogramach oraz przedział prędkości od do,
następnie używkownik podaje krok wzrostu prędkości w tej serii m/s
podczas obliczen program wypisuje wartość energii dla wyliczanej prędkości.
W wersji 2 (udoskonalonej) zabezpieczamy się przed złymi wartościami

Zrobić inny wariant programu w ktorym podajemy
masę, predkość początkową, krok narastania, ile wyników ma policzyć

Program podobny do wersji 2 jednak z ta zmianą,
że zamiast jednego m czytamy m1 i m2 oraz krok_m - wszystko zabezpieczone
Dla kolejnych mas wypisanych na ekranie wypisujemy poniżej całą serię energii z przedziału prędkości

1. Użytkownik podaje liczbę żądanych obliczeń.
2. Wyniki obliczeń gromadzone są w tablicy, a dopiero potem zawartość tablicy będzie wypisywana na ekran.
*/
#include <iostream>
#include <iomanip>

using namespace std;


int main() 
{
	float m, v1, v2, n, ek, v, m1, m2, krok_m;
	int response, x;
	
	do
		{
			cout<<"Podaj liczbe ilosci obliczeń";							//zapytanie o liczbę obliczeń jaką chce użytkownik wykonać
			cin>>x;
			if(x<1 || x>10)
			{
				cout<<"Ilosc obliczen musi byc wieksza od 0 i mniejsza od 10";
			}
		}
		while(x<1 || x>10);
	
	//do
	for(int i=1;i-1<x;i++)
	{
		cout<<"Obliczenia nr "<<i<<":\n\n";											//podawanie które to obliczenie
		/*
		do
		{
			cout<<"Podaj mase (kg)"<<endl;
			cin>>m;
			if(m<=0)
				cout<<"ERROR - Niepoprawna masa, podaj jeszcze raz"<<endl;
		}
		while(m<=0);
		*/
		
		do
		{
			do
			{
				cout<<"Od jakiej masy (kg)"<<endl;									//zapytanie o pierwszą część przedziału masy
				cin>>m1;
				if(m1<0)
					cout<<"Masa nie może być ujemna, podaj jeszcze raz"<<endl;
			}
			while(m1<0);
			
			do
			{
				cout<<"Do jakiej masy (kg)"<<endl;									//zapytanie o drugą część przedziału masy
				cin>>m2;
				if(m2<0)
					cout<<"Masa nie może być ujemna, podaj jeszcze raz"<<endl;
			}
			while(m2<0);
			
			if(m1>=m2)																//test czy przedział jest poprawny (masa)
				cout<<"ERROR - masa \"od\" jest wieksza od masy \"do\", podaj jeszcze raz"<<endl;
		}
		while(m1>=m2);
		
		do
		{
			cout<<"Podaj krok narastania masy (kg)"<<endl;							//zaytanie o krok narastania masy
			cin>>krok_m;
			if(krok_m<=0)
				cout<<"ERROR - Niepoprawny krok narastania, podaj jeszcze raz"<<endl;
		}
		while(krok_m<=0);
		
		do
		{
			do
			{
				cout<<"Od jakiej predkosci (m/s)"<<endl;							//zapytanie o pierwszą część przedziału prędkośći
				cin>>v1;
				if(v1<0)
					cout<<"Prędkość nie może być ujemna, podaj jeszcze raz"<<endl;
			}
			while(v1<0);
			
			do
			{
				cout<<"Do jakiej predkosci (m/s)"<<endl;							//zapytanie o pierwszą część przedziału prędkośći
				cin>>v2;
				if(v2<0)
					cout<<"Prędkość nie może być ujemna, podaj jeszcze raz"<<endl;
			}
			while(v2<0);
			
			if(v1>=v2)																//test czy przedział jest poprawny (prędkość)
				cout<<"ERROR - predkosc \"od\" jest wieksza od predkosci \"do\", podaj jeszcze raz"<<endl;
		}
		while(v1>=v2);
		
		do
		{
			cout<<"Podaj krok narastania predkosci (m/s)"<<endl;					//zapytanie o krok narastania prędkości
			cin>>n;
			if(n<=0)
				cout<<"ERROR - Niepoprawny krok narastania, podaj jeszcze raz"<<endl;
		}
		while(n<=0);
		
		int c = v2-v1;
		float result[c];
		
		for(int i=0; m1<=m2; m1+=krok_m,i++)
		{
			//result[i]=m1;
			v=v1;
			for(int j=0;v<=v2;v+=n,j++)
			{
				ek = (m1*v*v)/2;
				result[i]=ek;
			}
			
		}
		cout<<result[1];
		
		cout<<fixed<<setprecision(2);
		for(;m1<=m2;m1+=krok_m)
		{
			cout<<"Dla masy="<<m1<<"kg:"<<endl;										//wypisanie dla jakiej masy są wyniki
			v=v1;
			for(;v<=v2;v+=n)
			{
				ek = (m1*v*v)/2;							
				cout<<"Dla v="<<v<<"m/s \tEk="<<ek<<"J"<<endl;						//wypisywanie wyników
				
			}
			
		}
		/*do
		{
			cout<<"Czy chcesz powtozyc obliczenia 1-tak 0-nie"<<endl;
			cin>>response;
			if(response !=1 && response !=0)
				cout<<"Try again"<<endl;
		}
		while(response !=1 && response !=0);*/
		cout<<"\n";
	}
	//while(response==1);
	cout<<"Program zakończony";
	
	system("pause>>null");
	return 0;
}