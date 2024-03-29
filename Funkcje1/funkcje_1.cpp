#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <string>
using namespace std;

void klawisz();
void klawisz2();
float obw_prost1(float a, float b);
float obw_prost2(float a, float b);
int silnia(int n);

int main() 
{
	float bok1, bok2, obwod, pole;
	int n=0;
	cout<<"Proba nr 1 z wartosciami: 2 i 5"<<endl;
	obwod=obw_prost1(2, 5);
	cout<<"Obwod nr 1 = "<<obwod<<endl;
	cout<<"Proba nr 2"<<endl;
	cout<<"Podaj dlugosc boku a = ";
	cin>>bok1;
	cout<<"Podaj dlugosc boku b = ";
	cin>>bok2;
	obwod=obw_prost2(bok1, bok2);
	if(obwod>0)
		cout<<"Obwod nr 2 = "<<obwod<<endl;
	else if(obwod == -1)
		cout<<"ERROR - a niepoprawne"<<endl;
	else if(obwod == -2)
		cout<<"ERROR - b niepoprawne"<<endl;
	else if(obwod == -3)
		cout<<"ERROR - obie (a i b) niepoprawne"<<endl;
	else
		cout<<"ERROR"<<endl;
	
	cout<<endl<<"Obliczanie silni"<<endl;
	cout<<"Podaj n = ";
	cin>>n
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
float obw_prost2(float a, float b)	//-1 gdy pierwszy parametr, -2 gdy 2, -3 gdy oba
{
	if(a<=0 && b<=0)
		return -3;	// bad a and b
	if(b<=0 && a>0)
		return -2;	//bad b
	if(a<=0 && b>0)
		return -1;	//bad a
	return 2*a+2*b;	//2*(a+b)
}

int silnia(int n)
{
	/*
	if(n<0)
		return -1;	//n ujemne
	if(n==0)
		return 0;	//n == 0 0*0=0
	*/
	for(int wynik=1; n>1; n--)
		wynik*=n;
	return wynik;
}