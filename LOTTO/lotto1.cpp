#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <conio.h>
#define N 6
#define A 0
#define B 50
/*LOTTO*/
using namespace std;
int main()
{
	int k, l[N], key;
	srand(time(NULL));
	do
	{
		int g=1;
		do
		{
		cout<<"Podaj liczbe losowan miedzy 1 a 99"<<endl;
		cin>>k;
		if(k<=0 || k>=100)
			cout<<"ERROR - podaj jeszcze raz";
		}
		while(k<=0 || k>=100);
		
		
		do
		{
			cout<<endl;
			for(int i=0; i<N; i++)
			{
				l[i] = (rand() % B - A);
			}
			
			for(int i=0; i<N; i++)
				cout<<l[i]<<" ";
			cout<<endl;
			g++;
		}
		while(g<=k);
		cout<<"Wcisnij ENTER aby powtorzyc, inny klawisz aby wyjsc"<<endl;
		key=getch();
	}
	while(key==13);
	system("pause>>NULL");
}