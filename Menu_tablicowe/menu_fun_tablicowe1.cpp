#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <windows.h>
#include <iomanip>
#include <conio.h>
/**/

using namespace std;

void wypisz(char tekst[]);
void generujLosowo(int tab[], int n);
void generujRosnaco(int tab[], int n);
void generujMalejaco(int tab[], int n);
int minimum(int tab[], int n);
int maksimum(int tab[], int n);
void insertSort(int tab[], int n);
void bubbleSort(int tab[], int n);
void selectionSort(int tab[], int n);
void displayarray_1(int t[], int n);
void wyszukiwanie_od_do(int t[], int n, int min, int max, int wyniki[], int *liczba_znalezionych);

int main() 
{
	int a, b, n, *dane, *znalezione, *indeksy_znalezionych, licznosc, min, max;
	cout<<"Jaki rozmiar tablicy?";
	cin>>n;
	dane=new int[n+1];	//dane w tablicy od indeksu 1
	znalezione=new int[n+1];
	indeksy_znalezionych=new int[n+1];
	bool poprawne;
	char txt[50], znak;
	strcpy(txt, "Program testuje funkcje tablicowe.");
	
	do
	{
		system("cls");
		wypisz(txt);
		wypisz("0. Wyjscie z programu");
		wypisz("1. Generowanie danych losowych");
		wypisz("2. Generowanie danych posortowanych rosnaco");
		wypisz("3. Generowanie danych posortowanych malejaco");
		wypisz("4. Wczytanie danych z klawiatury");
		wypisz("5. Listing danych");
		wypisz("6. Wartosc minimalna");
		wypisz("7. Wartosc maksymalna");
		wypisz("8. Sortowanie rosnace metoda Bubble Sort");
		wypisz("9. Wyszukiwanie z przedzialu domknietego");
		
		znak=getch();
		switch(znak)
		{
				case '1':	generujLosowo(dane, n);
							break;
				case '2':	generujRosnaco(dane, n);
							break;
				case '3':	generujMalejaco(dane, n);
							break;
				case '4':	getch();
							break;
				case '5':	displayarray_1(dane, n);
							cout<<endl<<"Min = "<<min<<" Max = "<<max<<endl;
							system("pause");
							break;
				case '6':	min=minimum(dane, n);
							break;
				case '7':	max=maksimum(dane, n);
							break;
				case '8':	bubbleSort(dane, n);
							break;
				case '9':	cout<<"Podaj a i b"<<endl;
							cout<<"a = ";
							cin>>a;
							cout<<"b = ";
							cin>>b;
						
							fflush(stdin);
							break;
				case '0':	return 0;
		}
	}
	while(znak!=0);
	
	return 0;
}

void wypisz(char tekst[])
{
	cout<<tekst<<endl;
}

void generujLosowo(int tab[], int n)
{
	for (int i=0; i<n; i++)
		tab[i]=rand()%32000;
}
void generujRosnaco(int tab[], int n)
{
	for (int i=0; i<n; i++)
	{
		tab[i]=i;
	}
}

void generujMalejaco(int tab[], int n)
{
	for (int i=0; i<n; i++)
	{
		tab[i]=-i;
	}
}

void bubbleSort(int *t, int n)	//opt. O(N^2), oczekiwana O(N^2), pesymistyczna O(N^2)
{
	int pom;
	for(int nr=1; nr<n; nr++)
		for(int i=1; i<n-nr; i++)
			if(t[i]>t[i+1])
			{
				pom=t[i];
				t[i]=t[i+1];
				t[i+1]=pom;
			}
}

void insertSort(int *t, int n)
{
	for(int nr=2, i; nr<=n; nr++)
	{
		t[0]=t[nr];
		i=nr-1;
		while(t[i]>t[0])
		{
			t[i+1]=t[i];
			i--;
		}
		t[i+1]=t[0];
	}
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

void displayarray_1(int t[], int n)
{
	for(int i=1; i<n; i++)
		cout<<t[i]<<" ";
}

void wyszukiwanie_od_do(int t[], int n, int min, int max, int wyniki[], int *liczba_znalezionych)
{
	for(int i=0, j=0; i<n; i++)
		if(t[i]>min && t[i]<max)
		{
			wyniki[j] = t[i];
		//	index[j] = i;
			liczba_znalezionych++;
			j++;
		}
}

int minimum(int t[], int n)
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

int maksimum(int t[], int n)
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