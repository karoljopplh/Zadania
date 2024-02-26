#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <string>
using namespace std;

void klawisz();
void klawisz2();
float obw_prost1(float a, float b);

int main() 
{
	float bok1, bok2, obwod, pole;
	cout<<"Proba nr 1 z wartosciami: 2 i 5"<<endl;
	obwod=obw_prost1(2, 5);
	cout<<"Obwod nr 1 = "<<obwod<<endl;
	cout<<"Proba nr 2"<<endl;
	cout<<"Podaj dlugosc boku a = ";
	cin>>bok1;
	cout<<"Podaj dlugosc boku b = ";
	cin>>bok2;
	obwod=obw_prost1(bok1, bok2);
	if(obwod>0)
		cout<<"Obwod nr 2 = "<<obwod<<endl;
	else
		cout<<"ERROR"<<endl;
	
	klawisz2();
	return 0;
}

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
	fflush(stdin);
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

float obw_prost1(float a, float b)
{
	if(a<=0 || b<=0)
		return -1;	//-1 to kod bledu
	return 2*a+2*b;	//2*(a+b)
}
/*
float obw_prost1(float a, float b)
{
	if(a<=0 || b<=0)
		return -1;	//-1 to kod bledu
	float obwod;
	obwod=a*2+b*2;
	return obwod;	

}
*/