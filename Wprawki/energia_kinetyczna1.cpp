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
*/
#include <iostream>
#include <iomanip>

using namespace std;


int main() 
{
	float m, v1, v2, n, ek;
	int response;
	
	do
	{
		do
		{
			cout<<"Podaj mase (kg)"<<endl;
			cin>>m;
			if(m<=0)
				cout<<"ERROR - Niepoprawna masa, podaj jeszcze raz"<<endl;
		}
		while(m<=0);
		
		do
		{
			cout<<"Podaj krok narastania predkosci (m/s)"<<endl;
			cin>>n;
			if(n<=0)
				cout<<"ERROR - Niepoprawny krok narastania, podaj jeszcze raz"<<endl;
		}
		while(n<=0);
		
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
				cout<<"ERROR - predkosc \"od\" jest wieksza od \"do\", podaj jeszcze raz"<<endl;
		}
		while(v1>=v2);
		
		cout<<fixed<<setprecision(2);
		while(v1<=v2)
		{
			ek = (m*v1*v1)/2;
			cout<<"Dla v="<<v1<<"m/s \tEk="<<ek<<"J"<<endl;
			v1 +=n;
		}
		
		do
		{
			cout<<"Czy chcesz powtozyc obliczenia 1-tak 0-nie"<<endl;
			cin>>response;
			if(response !=1 && response !=0)
				cout<<"Try again"<<endl;
		}
		while(response !=1 && response !=0);
	}
	while(response==1);
		
	
	system("pause");
	return 0;
}