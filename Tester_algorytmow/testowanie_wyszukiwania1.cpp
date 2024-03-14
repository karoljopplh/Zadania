#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
/*
*/
using namespace std;

void klawisz2();
bool wyszukiwanie_do_1(int t[], int n, int szukana);
void wyszukiwanie_min(int t[], int n, int *o[]);

int main()
{
	int n, i, szukana, *tab, o[];
	bool znaleziono;
	cout<<"Jaki rozmiar tablicy? ";
	cin>>n;
	tab=new int[n];
	srand(time(NULL));
	for (i=0; i<n; i++)
	{
	/*	cout<<"Podaj element o ind. "<<i<<": ";
		cin>>tab[i];
	*/	
	//	tab[i]=i;
	//	tab[i]=-i;
	//	tab[i]=5;
		tab[i]=rand()%32000;
	//	cout<<"tab["<<i<<"]="<<tab[i]<<endl;
	}
	
	klawisz2();
	
	//ponizej badany algorytm
	
	znaleziono = 0;
	cout<<"Czego szukasz? ";
	cin>>szukana;
	/*
	for(i=0; i<n; i++)
		if(szukana==tab[i])
		{
			cout<<"Znaleziono pod indeksem = "<<i<<endl;
			znaleziono=1;
		}
	*/
//	znaleziono=wyszukiwanie_do_1(tab, n, szukana);
	if(wyszukiwanie_do_1(tab, n, szukana))
		cout<<"Szukana jest w tablicy"<<endl;
	else
		cout<<"Niczego nie znaleziono"<<endl;
	
	//koniec algorytmu
	
	delete [] tab;
	klawisz2();
	return 0;
}

bool wyszukiwanie_do_1(int t[], int n, int szukana) //lub int *t
{
	for(int i=0; i<n; i++)
		if(szukana==t[i])
			return 1;
	return 0;
}

int wyszukiwanie_min(int t[], int n, int *o[])	//
{
	if(n<=0)
		return -1;	// ERROR - empty table
		
	int min = t[0], k=0;
	
	for(int i=1; i<n; i++)	//1 because we can start comparing from the second index duh
	{
		if(t[i]<min)
			min=t[i];
	}
	
	for(int i=0 k=0; i<n; i++)
	{
		if(t[i]==min)
		{
			*o[k]=i;
			k++;
		}
	}
	
/*	for(int i=0, j=0; i<k; i++)	//useless, I was sleepy
	{
		if(t[i]==min)
		{
			o[j]=i;
			j++;
		}
	}
*/	return min;
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