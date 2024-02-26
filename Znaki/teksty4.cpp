#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <windows.h>
/*

*/

using namespace std;
int main() 
{
	char znak, t1[20], t2[20], t3[20];
	int dlugosc, liczba;
	
/*	cout<<"Wczytaj liczbe: ";
	cin>>liczba;
	getchar();*/
	cout<<"Wczytaj tekst t1: ";
	gets(t1);
	strcpy(t2, "Napis kopiowany");
	strcpy(t3,t1);
	cout<<"tekst T1 to "<<t1<<endl;
	cout<<"tekst T2 to "<<t2<<endl;
	cout<<"tekst T3 to "<<t3<<endl;
	for(int i=0; i<strlen(t1); i++)
	{
		cout<<t1[i]<<" ";
		Sleep(50);
	}
	system("pause");
	
	return 0;
}