#include <iostream>
#include <cmath>

using namespace std;

/*
Program wczytuje zmienne a,b,c, oblicza deltÄ™, jej pierwiastek,
wskazuje iloĹ›Ä‡ miejsc zerowych i oblicza ich wartoĹ›Ä‡ x na ukĹ‚adzie wspĂłjrzÄ™dnych.

Zadanie : czy chcesz powtĂłrzyÄ‡ obliczenia, do while na caĹ‚y i jeden do while sprawdzajÄ…cy czy a jest dodatnie
*/

int main()
{
	float a, b, c, delta, wynik, x0, x1, x2; //ewentualnie moĹĽna uĹĽyÄ‡ double dla wiÄ™kszej dokĹ‚adnoĹ›ci
	int answer;
	
	do
	{
		do
        {
            cout<<"Prosze wpisac wartosc a" <<endl;
            cin>>a;
            if (a>1000 || a<-1000)
            {
                cout<<"Wartosc a musi zawierac sie pomiedzy -1000 a 1000"<<endl;
            }
            if (a == 0)
            {
                cout<<"Wartosc a musi byc inna niz zero"<<endl;
            }
        } while (a == 0 || a>1000 || a<-1000);
		
		do
		{
		cout<<"Prosze wpisac wartosc b"<<endl;
		cin>>b;
		if (b>1000 || b<-1000)
            {
                cout<<"Wartosc b musi zawierac sie pomiedzy -1000 a 1000"<<endl;
            }
		}
		while(b>1000 || b<-1000);
		
		do
		{
		cout<<"Prosze wpisac wartosc c"<<endl;
		cin>>c;
		if (c>1000 || c<-1000)
            {
                cout<<"Wartosc c musi zawierac sie pomiedzy -1000 a 1000"<<endl;
            }
		}
		while(c>1000 || c<-10);
		
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
		else //jeĹ›li delta>0
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
