#include <iostream>
#include <cmath>

using namespace std;

/*
Program wczytuje zmienne a,b,c, oblicza deltê, jej pierwiastek,
wskazuje iloœæ miejsc zerowych i oblicza ich wartoœæ x na uk³adzie wspójrzêdnych.
Dodatkowo oblicza wierzcho³ek tej funkcji.
*/

int main()
{
	float a, b, c, delta, wynik, x0, x1, x2, xw, yw; //ewentualnie mo¿na u¿yæ double dla wiêkszej dok³adnoœci
	
	cout<<"Prosze wpisac wartosc a"<<endl;
	cin>>a;
	if(a==0)
	{
		cout<<"Ta funkcja nie jest funkcja kwadratowa (a==" << a << ")"<<endl;
		return 0;
	}
	cout<<"Prosze wpisac wartosc b"<<endl;
	cin>>b;
	cout<<"Prosze wpisac wartosc c"<<endl;
	cin>>c;
	
	delta = b * b -4 * a * c;
	cout<<"Delta = "<<delta<<endl;
	
	wynik = sqrt(delta);
	
	if(delta<0)
	{
		cout<<"Ta funkcja nie ma miejsc zerowych"<<endl;
		
		xw = -b / 2 * a;
		yw = -delta / (4 * a);
		cout<<"Wspolzedne wierzcholka tej funkcji to ("<<xw<<","<<yw<<")"<<endl;
	}
	else if(delta==0)
	{
		cout<<"Ta funkcja ma jedno miejsce zerowe"<<endl;
		cout<<"Pierwiastek delty = "<<wynik<<endl;
		
		x0 = -b / 2 * a;
		xw = x0;
		cout<<"x0 = "<<x0<<endl;
		//xw = -b / 2 * a;
		yw = -delta / (4 * a);
		cout<<"Wspolzedne wierzcholka tej funkcji to ("<<xw<<","<<yw<<")"<<endl;
		
	}
	else //jeœli delta>0
	{
		cout<<"Ta funkcja ma dwa miejsca zerowe"<<endl;
		cout<<"Pierwiastek delty = "<<wynik<<endl;
		
		x1 = (-b - wynik) / (2 * a);
		x2 = (-b + wynik) / (2 * a);
		cout<<"x1 = "<<x1<<endl;
		cout<<"x2 = "<<x2<<endl;
		xw = -b / 2 * a;
		yw = -delta / (4 * a);
		cout<<"Wspolzedne wierzcholka tej funkcji to ("<<xw<<","<<yw<<")"<<endl;
	}
	return 0;
}
