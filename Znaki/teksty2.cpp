#include <iostream>
#include <conio.h>
#include <stdio.h>
/*

*/

using namespace std;
int main() 
{
	char znak, t1[20], t2[20], t3[20];
	int dlugosc, liczba;
	
	cout<<"Wczytaj liczbe: ";
	cin>>liczba;
	getchar();
	cout<<"Wczytaj tekst t1: ";
	gets(t1);
	cout<<"Wczytaj tekst t2: ";
	gets(t2);
	cout<<"Wczytaj tekst t3: ";
	gets(t3);
	cout<<"tekst T1 to "<<t1<<endl;
	cout<<"tekst T2 to "<<t2<<endl;
	cout<<"tekst T3 to "<<t3<<endl;
	
	system("pause");
	
	return 0;
}