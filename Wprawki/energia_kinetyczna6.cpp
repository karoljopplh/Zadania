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
			cout<<"Podaj liczbe ilosci obliczen"<<endl;
			cin>>x;
			if(x<1 || x>10)
			{
				cout<<"Ilosc obliczen musi byc wieksza od 0 i mniejsza od 10";
			}
		}
		while(x<1 || x>10);
	
	//do
	for(int i=1;x>0;x--,i++)
	{
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
		cout<<"Jest to obliczenie nr"<<i<<endl<<endl;
		do
		{
			do
			{
				cout<<"Od jakiej masy (kg)"<<endl;
				cin>>m1;
				if(m1<0)
					cout<<"Masa nie może być ujemna, podaj jeszcze raz"<<endl;
			}
			while(m1<0);
			
			do
			{
				cout<<"Do jakiej masy (kg)"<<endl;
				cin>>m2;
				if(m2<0)
					cout<<"Masa nie może być ujemna, podaj jeszcze raz"<<endl;
			}
			while(m2<0);
			
			if(m1>=m2)
				cout<<"ERROR - masa \"od\" jest wieksza od masy \"do\", podaj jeszcze raz"<<endl;
		}
		while(m1>=m2);
		
		do
		{
			cout<<"Podaj krok narastania masy (kg)"<<endl;
			cin>>krok_m;
			if(krok_m<=0)
				cout<<"ERROR - Niepoprawny krok narastania, podaj jeszcze raz"<<endl;
		}
		while(krok_m<=0);
		
		do
		{
			do
			{
				cout<<"Od jakiej predkosci (m/s)"<<endl;
				cin>>v1;
				if(v1<0)
					cout<<"Prędkość nie może być ujemna, podaj jeszcze raz"<<endl;
			}
			while(v1<0);
			
			do
			{
				cout<<"Do jakiej predkosci (m/s)"<<endl;
				cin>>v2;
				if(v2<0)
					cout<<"Prędkość nie może być ujemna, podaj jeszcze raz"<<endl;
			}
			while(v2<0);
			
			if(v1>=v2)
				cout<<"ERROR - predkosc \"od\" jest wieksza od predkosci \"do\", podaj jeszcze raz"<<endl;
		}
		while(v1>=v2);
		
		do
		{
			cout<<"Podaj krok narastania predkosci (m/s)"<<endl;
			cin>>n;
			if(n<=0)
				cout<<"ERROR - Niepoprawny krok narastania, podaj jeszcze raz"<<endl;
		}
		while(n<=0);
		
		int ile_v=(v2-v1)/n;
		float tab[ile_v];
		
		cout<<fixed<<setprecision(2);
		while(m1<=m2)
		{
			cout<<"Dla masy="<<m1<<"kg:"<<endl;
			v=v1;
			while(v<=v2)
			{
				int i=0;
				ek = (m1*v*v)/2;
				//cout<<"Dla v="<<v<<"m/s \tEk="<<ek<<"J"<<endl;
				tab[i]=ek;
				i++;
				v +=n;
			}
			
			v=v1;
			while(v<=v2)
			{
				int i=0;
				ek = (m1*v*v)/2;
				cout<<"Dla v="<<v<<"m/s \tEk="<<tab[i]<<"J"<<endl;
				i++;
				v+=n;
			}
			m1+=krok_m;
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
	cout<<"Program zakonczony";
	
	system("pause>>null");
	return 0;
}
