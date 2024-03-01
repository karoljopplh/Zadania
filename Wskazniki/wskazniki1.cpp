#include <iostream>
using namespace std;

int main()
{
	int a, b, c, *cc, *x, *y, *z; 
	float aa, bb, *xx, *tab1, *tab2;
	
	x=new int;
	cout<<"Podaj wartosc do *x";
	cin>>*x;
	
	cc=&x;
	
	y=x;
	(*y)++;
	cout<<"*x="<<*x<<endl;
	cout<<"*y="<<*y<<endl;
	cout<<"Ile chcesz elementow tablicy?"<<endl;
	cin>>a;
	tab1=new float[a];
	cout<<"Podaj b"<<endl;
	cin>>b;
	z=&b;	//*z = b
	cout<<"Tablica zarezerwowana"<<endl;
	for(int i=0; i<a; i++)
		tab1[i]=i*2;
	
	cout<<"Listing kontrolny tablicy"<<endl;
	for(int i=0; i<a; i++)
		cout<<tab1[i]<<endl;
	
	
	tab2=tab1;
	cout<<"Listing kontrolny tablicy"<<endl;
	for(int i=0; i<a; i++)
		cout<<*tab2++<<endl;
	
	tab2=tab1;
	cout<<"Drugi listing kontrolny tablicy"<<endl;
	for(int i=0; i<a; i++)
		cout<<*tab2++<<endl;
	
	/*
	cout<<"Listing kontrolny tablicy"<<endl;
	for(int i=0; i<a; i++)
		cout<<*tab1;
		tab++;
		cout<<endl;
	*/
	cout<<"Przed usunieciem"<<endl;
	system("pause");
	delete x;
	delete tab1;	//uwalnia miejsce zajete przez zmienna wskaznikowa
	
	system("pause");
	return 0;
}