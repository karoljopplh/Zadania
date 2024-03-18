#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
/*
*/
using namespace std;

void klawisz2();
bool wyszukiwanie_do_1(int t[], int n, int szukana);
int wyszukiwanie_min(int t[], int n);
int wyszukiwanie_max(int t[], int n);
bool znajdz(int t[], int n, int szukana);
void selectionSort(int *t, int n);
void displayarray_1(int t[], int n);
//bool wysz_bin(int t[], int n, int szukana);

int main()
{
	int n, i, szukana, *tab, *o, min, max, imin, imax;
	bool znaleziono;
	cout<<"Jaki rozmiar tablicy? ";
	cin>>n;
	tab=new int[n+1];	//because we want to start from index 1 to n for selection sort for some reason xd uvu ;_; ._. :3 XwX
	srand(time(NULL));
	for (i=1; i<=n; i++)	//tu poprawki
	{
	/*
		cout<<"Podaj element o ind. "<<i<<": ";
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
	cout<<"PRZED SORTOWANIEM"<<endl;
	displayarray_1(tab, n);
	cout<<endl<<endl;
	selectionSort(tab, n);
	cout<<endl<<endl<<"POSORTOWANO"<<endl;
	displayarray_1(tab, n);
	cout<<endl<<endl;
	
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

void selectionSort(int t[], int n)
{
	int min, imin;
	for(int nr=1; nr<n; nr++)	//opt(n^2) ocz(n^2) pes(n^2)
	{
		min=t[nr];
		imin=nr;
		for(int i=nr+1; i<=n; i++)
		{
			if(t[i]<min)
			{
				min=t[i];
				imin=i;
			}
		}
		t[imin]=t[nr];
		t[nr]=min;
	}
	
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

void displayarray_1(int t[], int n)
{
	for(int i=1; i<n; i++)
		cout<<t[i]<<" ";
}