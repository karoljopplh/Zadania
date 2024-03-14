#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
/*
*/

void klawisz2();

using namespace std;
int main()
{
	int n, i, szukana, *tab;
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
	for(i=0; i<n; i++)
		if(szukana==tab[i])
		{
			cout<<"Znaleziono pod indeksem = "<<i<<endl;
			znaleziono=1;
		}
	if(!znaleziono)
		cout<<"Niczego nie znaleziono"<<endl;
	
	//koniec algorytmu
	
	delete [] tab;
	klawisz2();
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