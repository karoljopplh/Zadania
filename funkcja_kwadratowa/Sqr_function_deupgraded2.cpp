#include <iostream>
#include <cmath>

using namespace std;

/*
Program wczytuje zmienne a,b,c, oblicza deltę, jej pierwiastek,
wskazuje ilość miejsc zerowych i oblicza ich wartość x na układzie wspójrzędnych.

usuni�to dla uproszczenia:
====Dodatkowo oblicza wierzchołek tej funkcji, czy jest on najwyższym czy najniższym punktem funkcji i skierowanie ramion paraboli.====

Zadanie : czy chcesz powtórzyć obliczenia, do while na cały i jeden do while sprawdzający czy a jest dodatnie
*/

int main()
{
	float a, b, c, delta, wynik, x0, x1, x2; //ewentualnie można użyć double dla większej dokładności
	int answer;
	
	do
	{
		do
        {
            cout<<"Prosze wpisac wartosc a" <<endl;
            cin>>a;
            if (a == 0)
            {
                cout<<"Wartosc a musi byc inna niz zero"<<endl;
            }
        } while (a == 0);
		
		cout<<"Prosze wpisac wartosc b"<<endl;
		cin>>b;
		
		cout<<"Prosze wpisac wartosc c"<<endl;
		cin>>c;
		
		delta = b * b -4 * a * c; //b*b = pow(b,b)
		cout<<"Delta = "<<delta<<endl;
		
		wynik = sqrt(delta);
		
		if(delta<0)
		{
			cout<<"Ta funkcja nie ma miejsc zerowych"<<endl;
		}
		else if(delta==0)
		{
			cout<<"Ta funkcja ma jedno miejsce zerowe"<<endl;
			cout<<"Pierwiastek delty = "<<wynik<<endl;
			
			x0 = -b / (2 * a);
			cout<<"x0 = "<<x0<<endl;
		}
		else //jeśli delta>0
		{
			cout<<"Ta funkcja ma dwa miejsca zerowe"<<endl;
			cout<<"Pierwiastek delty = "<<wynik<<endl;
			
			x1 = (-b - wynik) / (2 * a);
			x2 = (-b + wynik) / (2 * a);
			cout<<"x1 = "<<x1<<endl;
			cout<<"x2 = "<<x2<<endl;
		}
		cout<<"Czy chcesz powtorzyc obliczenia? (1 - tak, 0 - nie): ";
        cin>>answer;
	}
	while (answer == 1);
	return 0;
}
