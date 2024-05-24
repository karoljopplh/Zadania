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
	cout<<"KOLEJKA"<<endl<<endl;
	
	
	poczatek=NULL;
	//tworzenie pierwszego elementu
	poczatek=new dane;
	cout<<"Nazwa: ";
	cin>>(*poczatek).naz;
	cout<<"Cena: ";
	cin>>(*poczatek).cena;
	(*poczatek).kolejny=NULL;
	koniec=poczatek;
	
	//dopisanie drugiego elementu
	
	roboczy=new dane;
	cout<<"Nazwa: ";
	cin>>(*roboczy).naz;
	cout<<"Cena: ";
	cin>>(*roboczy).cena;
	(*poczatek).kolejny=roboczy;
	(*roboczy).kolejny=NULL;
	koniec=roboczy;
	
	if(poczatek == NULL)
		cout<<"Brak Kolejki"<<endl;
	else
	{
		roboczy=poczatek;
		while(roboczy != NULL)
		{
			cout<<"Nazwa: "<<(*roboczy).naz<<"\t
			Cena: "<<(*roboczy).cena<<endl;
			roboczy=(*roboczy).kolejny;
			
		}
	}
	
	system("pause");
	
	return 0;
}