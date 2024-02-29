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
unsigned long long silnia_rec(unsigned int n);	//Silnia obliczana funkcją rekurencyjna
float pole_prost(float a, float b);

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
	
	cout<<"Obliczanie pola prostokata"<<endl;
	pole = pole_prost(bok1, bok2);
	if(pole>0)
		cout<<"Pole prostokata = "<<pole<<endl;
	else if(pole == -1)
		cout<<"ERROR - a niepoprawne"<<endl;
	else if(pole == -2)
		cout<<"ERROR - b niepoprawne"<<endl;
	else if(pole == -3)
		cout<<"ERROR - obie (a i b) niepoprawne"<<endl;
	else
		cout<<"ERROR"<<endl;
	
	cout<<endl<<"Obliczanie silni"<<endl;
	cout<<"Podaj n = ";
	cin>>n;
	if(silnia(n)==-1)
		cout<<"ERROR - n niepoprawne (n<0)"<<endl;
	else
		cout<<silnia(n);
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
	int wynik=1;
	if(n<0)
		return -1;	//n ujemne - ERROR
	if(n==0 || n==1)
		return 1;	//1! == 0! == 1
	for(; n>1; n--)
		wynik*=n;
	return wynik;
}

unsigned long long silnia_rec(int n)	//Silnia obliczana funkcją rekurencyjna
{
	if(n<0)
		return -1;	//n ujemne - ERROR
    // Obsługa przypadku dla n równego 0 lub 1
    if (n == 0 || n == 1) {
        return 1;
    } else {
        // Obliczanie silni dla n większego od 1
        return n * silnia(n - 1);
    }
}

float pole_prost(float a, float b)
{
    // Obliczanie pola prostokąta
    if(a<=0 && b<=0)
		return -3;	// bad a and b
	if(b<=0 && a>0)
		return -2;	//bad b
	if(a<=0 && b>0)
		return -1;	//bad a
    return a*b;
}