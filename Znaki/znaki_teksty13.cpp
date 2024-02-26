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
	cin.sync();		//clear stream
//	fflush(stdin);	//clear bufor
//	getchar();		//get ENTER
	cout<<"Podaj tekst1: ";
	gets(tekst1);
	cout<<"Podaj tekst2: ";
	gets(tekst2);
	cout<<"Podaj tekst3: ";
	gets(tekst3);
	cout<<endl<<endl<<"liczba: "<<liczba<<endl;
	cout<<"tekst1: "<<tekst1<<endl;
	puts(tekst1);
	cout<<"tekst2: "<<tekst2<<endl;
	cout<<"tekst3: "<<tekst3<<endl;
	cout<<"......................"<<endl;
	system("pause");
}