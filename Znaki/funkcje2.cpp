#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <windows.h>
/*
*/
using namespace std;

void klawisz()
{
	cout<<endl<<"Nacisnij ENTER by kontnuowac"<<endl;
	getchar();
	cout<<endl;
}

void klawisz2()
{
	char tekst[30];
	int i;
	strcpy(tekst, "Nacisnij ENTER by kontnuowac");
	cout<<endl;
	for(int i=0; i<strlen(tekst); i++)
	{
		cout<<tekst[i]<<" ";
		Sleep(50);
	}
	getchar();
	cout<<endl;
}


int main() 
{
	char znak, t1[20], t2[20], t3[20];
	int dlugosc, liczba;
	
/*	cout<<"Wczytaj liczbe: ";
	cin>>liczba;
	getchar();*/
	cout<<"PROGRAM TESTOWY";
	klawisz();
	cout<<"Wczytaj tekst t1: ";
	gets(t1);
	strcpy(t2, "Napis kopiowany");
	strcpy(t3,t1);
	cout<<"tekst T1 to "<<t1<<endl;
	cout<<"tekst T2 to "<<t2<<endl;
	cout<<"tekst T3 to "<<t3<<endl;
	klawisz2();
	for(int i=0; i<strlen(t1); i++)
	{
		cout<<t1[i]<<" ";
		Sleep(50);
	}
	klawisz2();
	
	return 0;
}