#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
using namespace std;
main()
{ 
	char tekst1[20], tekst2[20], tekst3[20];
	float liczba;
	cout<<"Podaj liczbe: ";
	cin>>liczba;
	cout<<"Podaj tekst1: ";
	cin>>tekst1;		//a co gdy wpiszemy wyrazy ze spacjami?
	getchar();
	cout<<"Podaj tekst2: ";
	cin>>tekst2;
	cout<<"Podaj tekst3: ";
	cin>>tekst3;
	cout<<endl<<endl<<"liczba: "<<liczba<<endl;
	cout<<"tekst1: "<<tekst1<<endl;
	cout<<"tekst2: "<<tekst2<<endl;
	cout<<"tekst3: "<<tekst3<<endl;
	cout<<"......................"<<endl;
	system("pause");
}