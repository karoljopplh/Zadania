#include <iostream>
#include <cstdlib>
/**/
using namespace std;

struct dane
{
	char naz[20];
	int cena;
	dane *kolejny;
};

int main() 
{
	dane *poczatek, *koniec, *roboczy;
	int i, n;
	cout<<"KOLEJKA"<<endl<<endl;
	
	
	poczatek=NULL;
	cout<<"Ile elementow dopisac? ";
	cin>>n;
//uniwersalne dopisanie drugiego elementu (2 w 1)
	for(i=1; i<=n; i++)
	{
		roboczy=new dane;
		cout<<"Nazwa: ";
		cin>>roboczy->naz;
		cout<<"Cena: ";
		cin>>roboczy->cena;
		roboczy->kolejny=NULL;
		if(poczatek==NULL)
			poczatek=roboczy;
		else
			koniec->kolejny=roboczy;
		koniec=roboczy;
	}
	
//usuniecie pierwszego elementu
	if(poczatek==NULL)
		cout<<"Brak kolejki"<<endl;
	else
	{
		roboczy=poczatek;
		cout<<"Usuwamy element: "<<roboczy->naz<<"\t"<<roboczy->cena<<endl;
		poczatek=roboczy->kolejny;
		delete roboczy;
	}
	
//wypisanie	
	if(poczatek == NULL)
		cout<<"Brak Kolejki"<<endl;
	else
	{
		roboczy=poczatek;
		while(roboczy != NULL)
		{
			cout<<"Nazwa: "<<roboczy->naz<<"\tCena: "<<roboczy->cena<<endl;
			roboczy=roboczy->kolejny;
			
		}
	}
	
	system("pause");
}