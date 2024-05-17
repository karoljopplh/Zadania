#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <ctime>
#include <string.h>
#include <stdio.h>
/*
funkcje do zrobienia
wyszukaj
sortuj		//zrobione
maksimum 	//zrobione
minimum		//zrobione
suma		//zrobione
srednia		//zrobione
*/

struct towar
{
	char nazwa[20];
	float cena;
	int sztuk;
};

using namespace std;

void losuj(towar magazyn[], int liczba_danych);							//od 1 do liczba danych
void generujPosortowane(towar magazyn[], int liczba_danych);			//od 1 do liczba danych
void generujOdwrotniePosortowane(towar magazyn[], int liczba_danych);	//od 1 do liczba danych
void dodajTowar(towar magazyn[], towar nowy, int *liczba_danych);		//dopisuje na koniec
void wypisz(towar towary[], int ile);									//od 1 do liczba danych
float sumaWartosci(towar magazyn[], int int n);
float sredniaCena(towar magazyn[], int liczba_danych);
void wyszukajCena(towar magazyn[], int ile_danych, towar wyszukane[], int *ile_wyszukanych, float min, float max);
float wyszukiwanie_min(towar magazyn[], int n);
float wyszukiwanie_max(towar magazyn[], int n);
void minmaxCena(towar magazyn[], int liczba_danych, float *min, float *max);
void przecena(towar magazyn[], int liczba_danych, float procent);
void selectionSort(towar magazyn[], int liczba_danych);

int main() 
{
	towar *magazyn, *wyszukane, nowy;
	float suma, srednia, minimum, maksimum, procent;
	int rozmiar=0, liczba_danych=0, liczba_wyszukanych=0;
	char znak;
	cout<<"OBSLUGA MAGAZYNU"<<endl<<endl;
	srand(time(NULL));
	
	do
	{
		fflush(stdin);
		cout<<endl<<endl<<"Nacisnij ENTER"<<endl;
		getchar();
		system("cls");
		cout<<"0. Dynamiczne tworzenie magazynu"<<endl;
		cout<<"1. Losowanie calego magazynu"<<endl;
		cout<<"2. Generowanie calego magazynu posortowanego"<<endl;
		cout<<"3. Generowanie calego magazynu odwrotnie posortowanego"<<endl;
		cout<<"4. Dopisanie towaru do magazynu"<<endl;
		cout<<"5. Wypisanie elementow tablicy"<<endl;
		cout<<"6. Suma wartosci w calym magazynie"<<endl;
		cout<<"7. Srednia cena towaru"<<endl;
		cout<<"8. Maksymalna i minimalna cena"<<endl;
		cout<<"9. Zmiana ceny o podany procent"<<endl;
		cout<<"a. Wyszukiwanie wedlug przedzialu cen"<<endl;
		cout<<"b. Sortowanie rosnace wedlug cen- proste wybieranie"<<endl;
		cout<<"ESC. ---KONIEC PRACY---"<<endl<<endl;
		znak=getch();
		switch(znak)
		{
			case '0':	cout<<"Jaki rozmiar magazynu? ";
						cin>>rozmiar;
						magazyn=new towar[rozmiar+1];
						wyszukane=new towar[rozmiar+1];
						liczba_danych=0;
						liczba_wyszukanych=0;
						break;
			case '1':	cout<<"Ile danych losowac? ";
						cin>>liczba_danych;
						losuj(magazyn, liczba_danych);
						cout<<endl<<"Wylosowano"<<endl;
						break;
			case '2':	cout<<"Ile danych generowac ";
						cin>>liczba_danych;
						generujPosortowane(magazyn, liczba_danych);
						cout<<endl<<"Wygenerowano"<<endl;
						break;
			case '3':	cout<<"Ile dancyh generowac ";
						cin>>liczba_danych;
						generujOdwrotniePosortowane(magazyn, liczba_danych);
						cout<<endl<<"Wygenerowano"<<endl;
						break;
			case '4':	cout<<"Nazwa: ";
						fflush(stdin);
						gets(nowy, nazwa);
						cout<<"Cena: " 
						cin>>nowy.cena;
						cout<<"Sztuk: ";
						cin>>nowy.sztuk;
						cin.ignore();
						dodajTowar(magazyn, nowy, &liczba_danych);
						cout<<"Dopisany"<<endl;
						break;
			case '5':	wypisz(magazyn, liczba_danych);
						cout<<endl;
						break;
			case '6':	cout<<endl<<"Suma wartosci magazynu= "<<sumaWartosci(magazyn, liczba_danych)<<endl<<endl;
						break;
			case '7':	cout<<"Srednia cena"<<sredniaCena(magazyn, liczba_danych)<<endl<<endl;
						break;
			case '8':	minmaxCena(magazyn, liczba_danych, &minimum, &maksimum);
						cout<<"Cena minimalna="<<minimum<<" Cena maksymalna="<<maksimum<<endl;
						break;
			case '9':	cout<<"O jaki procent przeceniasz? (ujemny obniza) ";
						cin>>procent;
						przecena(magazyn, liczba_danych, procent);
						cout<<"Przecenione."<<endl;
						break;
			case 'a':	cout<<"Podaj przedzial szukany."<<endl<<"od wartosci: ";
						cin>>minimum;
						cout<<"do wartosci: ";
						cin>>maksimum;
						getchar();
						wyszukajCena(magazyn, liczba_danych, wyszukan, &liczba_wyszukanych, minimum, maksimum);
						wypisz(wyszukane, liczba_wyszukanych);
						cout<<endl;
						break;
			case 'b':	selectionsort()
						
		}
	}
	while();
	return 0;
}

void wyszukajCena(towar magazyn[], int ile_danych, towar wyszukane[], int *ile_wyszukanych, float min, float max)
{
	int ile=0;
		for(int i=0; i<ile_danych; i++)
			if(magazyn[i]>min && magazyn[i]<max)
				ile++;
		for(int i=0, j=0; i<ile_danych; i++)
			if(magazyn[i]>min && magazyn[i]<max)
			{
				wyszukane[j] = t[i];
				index[j] = i;
				j++;
			}
}

float sumaWartosci(towar magazyn[], int liczba_danych)
{
	long int s=0;
	for(int i=0; i<liczba_danych; i++)
		s+=magazyn[i];
	return s;
}

float sredniaCena(towar magazyn[], int liczba_danych)
{
	float sum = sumaWartosci(towar magazyn[], int liczba_danych);
	return sum/liczba_danych;
}

void selectionSort(towar magazyn[], int n)
{
	int min, imin;
	for(int nr=1; nr<n; nr++)	//opt(n^2) ocz(n^2) pes(n^2)
	{
		min=magazyn[nr];
		imin=nr;
		for(int i=nr+1; i<=n; i++)
		{
			if(t[i]<min)
			{
				min=t[i];
				imin=i;
			}
		}
		magazyn[imin]=magazyn[nr];
		magazyn[nr]=min;
	}
	
}

int wyszukiwanie_min(towar magazyn[], int n)
{
	if(n<=0)
		return -1;	// ERROR - empty table
		
	int min = magazyn[0];
	for(int i=1; i<n; i++)
	{
		if(magazyn[i]<min)
			min=magazyn[i];
	}
	return min;
}

int wyszukiwanie_max(towar magazyn[], int n)
{
	if(n<=0)
		return -1;	// ERROR - empty table
		
	int max = magazyn[0];
	for(int i=1; i<n; i++)
	{
		if(magazyn[i]>max)
			max=magazyn[i];
	}
	return max;
}