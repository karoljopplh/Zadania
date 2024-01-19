#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <conio.h>
#define N 6
#define A 0
#define B 50
/*
LOTTO
v2 = z tablica inwersyjna 
*/
using namespace std;
int main()
{
	bool l[49];
	int k, key;
	srand(time(NULL));
	l[0]=true;
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
			for(int i=1; i<B; i++)			//zerowanie tablicy
				l[i]=false;
			
			cout<<endl<<"losowanie nr "<<g<<endl;
			
			for(int i=0, j; i<N; i++)
			{
				j =(rand() % B - A);
				if(l[j]==false)
				{
					l[j] = true;
					//cout<<j<<"="<<l[j]<<endl;	//debug
					
				}
				else
					i--;
			}
			
			for(int i=1; i<B;i++)
			{
				//cout<<"test "<<i<<" :";		//debug
				if(l[i]==true)
				{
					cout<<i<<" "<<endl;
				}
			}
				
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