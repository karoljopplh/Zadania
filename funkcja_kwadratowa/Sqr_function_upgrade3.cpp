#include <iostream>
#include <cmath>

using namespace std;

/*
Program wczytuje zmienne a,b,c, oblicza deltę, jej pierwiastek,
wskazuje ilość miejsc zerowych i oblicza ich wartość x na układzie wspójrzędnych.
Dodatkowo oblicza wierzchołek tej funkcji, czy jest on najwyższym czy najniższym punktem funkcji i skierowanie ramion paraboli.
Zadanie : czy chcesz powtórzyć obliczenia, do while na cały i jeden do while sprawdzający czy a jest dodatnie
*/

int main()
{
	float a, b, c, delta, wynik, x0, x1, x2, xw, yw; //ewentualnie można użyć double dla większej dokładności
	
	bool ramiona; // true gdy ramiona są skierowane do góry, false gdy ramiona są skierowane do dołu
	
	cout<<"Prosze wpisac wartosc a"<<endl;
	cin>>a;
	if(a==0)
	{
		cout<<"Ta funkcja nie jest funkcja kwadratowa (a=0)"<<endl;
		return 0;
	}
	else if(a>0)
	{
		ramiona = true;
	}
	else
	{
		ramiona = false;
	}
	
	cout<<"Prosze wpisac wartosc b"<<endl;
	cin>>b;
	
	cout<<"Prosze wpisac wartosc c"<<endl;
	cin>>c;
	
	if(ramiona)
	{
		cout<<"Ramiona paraboli sa skierowane do gory"<<endl;
	}
	else
	{
		cout<<"Ramiona paraboli sa skierowane do dolu"<<endl;
	}
	
	delta = b * b -4 * a * c; //b*b = pow(b,b)
	cout<<"Delta = "<<delta<<endl;
	
	wynik = sqrt(delta);
	
	if(delta<0)
	{
		cout<<"Ta funkcja nie ma miejsc zerowych"<<endl;
		
		xw = -b / (2 * a);
		yw = -delta / (4 * a);
		cout<<"Wspolzedne wierzcholka tej funkcji to W = ("<<xw<<","<<yw<<")"<<endl;
		
		if(ramiona)
		{
			cout<<"Wierzcholek jest najnizszym punktem tej funkcji";
		}
		else
		{
			cout<<"Wierzcholek jest najwyzszym punktem tej funkcji";
		}
	}
	else if(delta==0)
	{
		cout<<"Ta funkcja ma jedno miejsce zerowe"<<endl;
		cout<<"Pierwiastek delty = "<<wynik<<endl;
		
		x0 = -b / (2 * a);
		xw = x0;
		cout<<"x0 = "<<x0<<endl;
		
		//xw = -b / 2 * a;
		yw = -delta / (4 * a);
		cout<<"Wspolzedne wierzcholka tej funkcji to W = ("<<xw<<","<<yw<<")"<<endl;
		
		if(ramiona)
		{
			cout<<"Wierzcholek jest najnizszym punktem tej funkcji";
		}
		else
		{
			cout<<"Wierzcholek jest najwyzszym punktem tej funkcji";
		}
	}
	else //jeśli delta>0
	{
		cout<<"Ta funkcja ma dwa miejsca zerowe"<<endl;
		cout<<"Pierwiastek delty = "<<wynik<<endl;
		
		x1 = (-b - wynik) / (2 * a);
		x2 = (-b + wynik) / (2 * a);
		cout<<"x1 = "<<x1<<endl;
		cout<<"x2 = "<<x2<<endl;
		
		xw = -b / (2 * a);
		yw = -delta / (4 * a);
		cout<<"Wspolzedne wierzcholka tej funkcji to W = ("<<xw<<","<<yw<<")"<<endl;
		
		if(ramiona)
		{
			cout<<"Wierzcholek jest najnizszym punktem tej funkcji";
		}
		else
		{
			cout<<"Wierzcholek jest najwyzszym punktem tej funkcji";
		}
	}
	return 0;
}
