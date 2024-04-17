#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <windows.h>
#include <conio.h>
/**/

using namespace std;

void wypisz(char text);
void generujLosowo(int tab[], int n);
void generujRosnaco(int tab[], int n);
void generujMalejaco(int tab[], int n);
int min(int tab[], int n);
int max(int tab[], int n);
void insertSort(int tab[], int n);
void bubbleSort(int tab[], int n);
void selectionSort(int tab[], int n);

int main() 
{
	int a, b, n, *dane, *znalezione, *indeksy_znalezionych, licznosc;
	cout<<"Jaki rozmiar tablicy?";
	cin>>n;
	dane=new int[n+1];	//dane w tablicy od indeksu 1
	znalezione=new int[n+1];
	indeksy_znalezionych=new int[n+1];
	bool poprawne;
	char txt[50], znak;
	
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
		
		znak=getch()
		
	}
	
	strcpy(txt, "Program testuje funkcje tablicowe.");
	return 0;
}