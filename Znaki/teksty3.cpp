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
	strcpy(t2, "Napis kopiowany");
	strcpy(t3,t1);
	cout<<"tekst T1 to "<<t1<<endl;
	cout<<"tekst T2 to "<<t2<<endl;
	cout<<"tekst T3 to "<<t3<<endl;
	
	if(strcmp(t1, "TAK") == 0)
		cout<<"teksty zgodne"<<endl;
	else
		cout<<"teksty NIE zgodne"<<endl;
	system("pause");
	
	return 0;
}