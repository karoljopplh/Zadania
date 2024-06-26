#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
/*
Zaprojektować funkcję z wyszukiwaniem liniowym w tablicy
Parametry: 
intowa tablica źródłowa
liczba elementów tablicy źródłowej (n)
dolny kres szukania (od) (przedział domknięty)
górny kres szukania (do) (przedział domknięty)
tablica znalezionych wartości
tablica indeksów znalezionych wartości

Funkcja ma oddać jakie wartości z przedziału zostały znalezione i na których pozycjach (indeksach) oraz ile ich było
*/
using namespace std;

void klawisz2();
bool wyszukiwanie_do_1(int t[], int n, int szukana);
int wyszukiwanie_min(int t[], int n);
int wyszukiwanie_max(int t[], int n);
bool znajdz(int t[], int n, int szukana);
int wyszukiwanie_od_do(int t[], int n, int from, int to, int *z, int *index);

int main()
{
	int n, i, szukana, *tab, *o, min, max, from, to , *z, *index, ile;
	bool znaleziono;
	cout<<"Jaki rozmiar tablicy? ";
	cin>>n;
	tab=new int[n];
	z=new int[n];
	index=new int[n];
	srand(time(NULL));
	for (i=0; i<n; i++)
	{
	/*
		cout<<"Podaj element o ind. "<<i<<": ";
		cin>>tab[i];
	*/	
	//	tab[i]=i;
	//	tab[i]=-i;
		tab[i]=5;
	//	tab[i]=rand()%32000;
	//	cout<<"tab["<<i<<"]="<<tab[i]<<endl;
	}
	
	klawisz2();
	
	//ponizej badany algorytm
	
	cout<<"Wyszukiwanie od do \n";
	cout<<"Podaj wartosc od \n";
	cin>>from;
	cout<<"Podaj wartosc do \n";
	cin>>to;
	
	ile = wyszukiwanie_od_do(tab, n, from, to, z, index);
	cout<<ile<<endl;
	
	cout<<"Wyniki: \n";
	for(int i=0; i<ile; i++)
		cout<<"Wynik "<<i<<" = "<<z[i]<<" index = "<<index[i]<<endl;
	/*
	min = wyszukiwanie_min(tab, n);
	cout<<"Wartosc minimalna = "<<min<<endl;
	for(i=0; i<n; i++)
		if(min==tab[i])
			cout<<"Wartosc minimalna pod indeksem = "<<i<<endl;
	
	cout<<endl;
	
	max = wyszukiwanie_max(tab, n);
	cout<<"Wartosc maxymalna = "<<max<<endl;
	for(i=0; i<n; i++)
		if(max==tab[i])
			cout<<"Wartosc maksymalna pod indeksem = "<<i<<endl;
	
	znaleziono = 0;
	cout<<"Czego szukasz? ";
	cin>>szukana;
	*/
	/*
	for(i=0; i<n; i++)
		if(szukana==tab[i])
		{
			cout<<"Znaleziono pod indeksem = "<<i<<endl;
			znaleziono=1;
		}
	*/
	/*
	znaleziono=znajdz(tab, n, szukana);
	if(znajdz(tab, n, szukana))
		cout<<"Szukana jest w tablicy"<<endl;
	else
		cout<<"Niczego nie znaleziono"<<endl;
	*/
//	znaleziono=wyszukiwanie_do_1(tab, n, szukana);
/*	if(wyszukiwanie_do_1(tab, n, szukana))
		cout<<"Szukana jest w tablicy"<<endl;
	else
		cout<<"Niczego nie znaleziono"<<endl;
*/	
	//koniec algorytmu
	
	delete [] tab;
	klawisz2();
	return 0;
}

int wyszukiwanie_od_do(int t[], int n, int from, int to, int z[], int index[])
{
	int ile=0;
	for(int i=0; i<n; i++)
		if(t[i]>from && t[i]<to)
			ile++;
//	z=new int[ile];
//	index=new int[ile];
	for(int i=0, j=0; i<n; i++)
		if(t[i]>from && t[i]<to)
		{
			z[j] = t[i];
			index[j] = i;
			j++;
		}
	return ile;
}

bool wyszukiwanie_do_1(int t[], int n, int szukana) //lub int *t
{
	for(int i=0; i<n; i++)
		if(szukana==t[i])
			return 1;
	return 0;
}

int wyszukiwanie_min(int t[], int n)
{
	if(n<=0)
		return -1;	// ERROR - empty table
		
	int min = t[0];
	for(int i=1; i<n; i++)
	{
		if(t[i]<min)
			min=t[i];
	}
	return min;
}

int wyszukiwanie_max(int t[], int n)
{
	if(n<=0)
		return -1;	// ERROR - empty table
		
	int max = t[0];
	for(int i=1; i<n; i++)
	{
		if(t[i]>max)
			max=t[i];
	}
	return max;
}

/*
int wyszukiwanie_min(int t[], int n, int *o[])	//I wasn't in a good mental condition at that time
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
			k++;
	}
	
	o=new int[k];
	
	for(int i=0, j=0; i<k; i++)
	{
		if(t[i]==min)
		{
			o[j]=i;
			j++;
		}
	}
	return min;
}
*/

bool znajdz(int t[], int n, int szukana)
{
	int l=0, p=n-1, sr;
	do
	{
		sr=(l+p)/2;
		if(szukana>t[sr])
			p=sr-1;
		else if(szukana<t[sr])
			l=sr+1;
		else
			return 1;
	}
	while(!(l==p) );
	//while(!znaleziono || !(l==p) )
	return 0;
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