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
int pot(int p, int w);
void prostokat1(float a, float b, float *ob, float *po);
void prostokat1Ref(float a, float b, float &ob, float &po);
void prostokat2(float a, float b, float *ob, float *po, int *error);

int main() 
{
	float bok1, bok2, obwod, pole, pod, w;
	float *o, *p;
	int n=0, error;
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
	cout<<endl<<"Obliczanie potegi"<<endl;
	cout<<"Podaj pod = ";
	cin>>pod;
	cout<<"Podaj w = ";
	cin>>w;
	cout<<pot(pod,w)<<endl;
	
//	ponizej zmiana v4: pracujemy NIE z "obwod", "pole lecz z wskazywanymi przez wskazniki "o" oraz "p"
	o=new float;
	p=new float;
	
	cout<<"Wywolanie fun. prostokat1"<<endl;
	prostokat1(bok1, bok2, o, p);
	cout<<"Obwod = "<<*o<<endl;
	cout<<"Pole = "<<*p<<endl;
	
	cout<<"Wywolanie fun. prostokat1Ref"<<endl;
	prostokat1Ref(bok1, bok2, *o, *p);
	cout<<"Obwod = "<<*o<<endl;
	cout<<"Pole = "<<*p<<endl;
	
	cout<<"Wywolanie fun. prostokat2"<<endl;
	prostokat2(bok1, bok2, o, p, &error);
	if(error==0)
	{
		cout<<"Pole = "<<*p<<endl;
		cout<<"Obwod = "<<*o<<endl;
	}
	else
	{
		//cout<<error<<endl;	//d-debug
		switch (error)
		{
			case -1:	cout<<"Bok a zly"<<endl;
						break;
			case -2:	cout<<"Bok b zly"<<endl;
						break;
			case -3:	cout<<"Oba boki zle"<<endl;
		}	
	}
	
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
	if(n<0)
		return -1;	//n ujemne - ERROR
	if(n==0 || n==1)
		return 1;	//1! == 0! == 1
	int wynik=1;
	for(; n>1; n--)
		wynik*=n;
	return wynik;
}

unsigned long long silnia_rec(int n)	//Silnia obliczana funkcją rekurencyjna
{
	if(n<0)
		return -1;				//n ujemne - ERROR
    if (n == 0 || n == 1)		// Obsługa przypadku dla n równego 0 lub 1
        return 1;
    return n * silnia(n - 1);	// Obliczanie silni dla n większego od 1
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
/*
int pot(int p, int w)
{
	if(p==0)
	{
		if(w==0)
			return -1;	//niejednoznaczne
		if(w>0)
			return 0;
		if(w<0)
			return -2;	//nieokreslone
	}
	int wynik=1;
	while(w>0)
	{
		wynik*=p;
		w--;
	}
	if(w==0)
		return wynik;
	w *= -1;
	while(w>0)
	{
		wynik*=p;
		w--;
	}
	wynik=1/wynik;
	return wynik;
}
*/
int pot(int p, int w)
{
	if(p==0 && w<0)
		return -1;	//nieokreslone
	if(p==0 && w==0)
		return -2;	//niejednoznaczne
	int wynik = 1;
	while(w>0)
	{
		wynik*=p;
		w--;
	}
	while(w<0)
	{
		wynik*=(1/p);
		w++;
	}
	return wynik;
}

void prostokat1(float a, float b, float *ob, float *po)
{
	*ob=2*(a+b);
	*po=a*b;
}

void prostokat1Ref(float a, float b, float &ob, float &po)
{
	ob=2*(a+b);
	po=a*b;
}

void prostokat2(float a, float b, float *ob, float *po, int *error)
{
	*error=0;
	if(b<=0)
		*error -= 2;	//bad b
	if(a<=0)
		*error -= 1;	//bad a, if a and b are bad then -3
	*ob=2*(a+b);
	*po=a*b;
}