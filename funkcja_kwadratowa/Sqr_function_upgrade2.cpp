#include <iostream>
#include <cmath>

using namespace std;

/*
Program wczytuje zmienne a,b,c, oblicza delt�, jej pierwiastek,
wskazuje ilo�� miejsc zerowych i oblicza ich warto�� x na uk�adzie wsp�jrz�dnych.
Dodatkowo oblicza wierzcho�ek tej funkcji, czy jest on najwy�szym czy najni�szym punktem funkcji i skierowanie ramion paraboli.
*/

int main()
{
	float a, b, c, delta, wynik, x0, x1, x2, xw, yw; //ewentualnie mo�na u�y� double dla wi�kszej dok�adno�ci
	
	bool ramiona; // true gdy ramiona s� skierowane do g�ry, false gdy ramiona s� skierowane do do�u
	
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
	else //je�li delta>0
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
