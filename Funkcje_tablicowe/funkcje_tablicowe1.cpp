#include <iostream>
#include <stdio.h>
#include <conio.h>
#define XX 4
#define YY 3

using namespace std;

long int suma(int tab[],int n)
{
	long int s=0;
	for(int i=0; i<n; i++)
		s+=tab[i];
	return s;
}
long int suma(int tab[][YY],int x, int y=2)
{
	long int s=0;
	for(int iy=0; iy<y;iy++)
		for(int ix=0; ix<x;ix++)
			s+=tab[ix][iy];
	return s;
}

/**/

int main() 
{
	int t1[XX], t2[XX][YY], i, ix, iy;
	cout<<"Podaj wartosci tablicy 1-wymiarowej"<<endl;
	for(i=0;i<XX;i++)
		cin>>t1[i];
	cout<<"Suma tablice 1-wymiarowej="<<suma(t1, XX)<<endl<<endl;
	cout<<"Podaj wartosci tablicy 2-wymiarowej"<<endl;
	for(iy=0;iy<YY;iy++)
		for(ix=0;ix<XX;ix++)
			cin>>t2[ix][iy];
	cout<<"Suma tablice 2-wymiarowej="<<suma(t2, XX, YY)<<endl<<endl;
	cout<<"Suma tablice 2-wymiarowej (2 wymiar domyslny)="<<suma(t2, XX)<<endl<<endl;
	
	system("pause");
	return 0;
}