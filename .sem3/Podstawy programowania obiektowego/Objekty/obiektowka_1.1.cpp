#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string.h>

using namespace std;
class towar
{
	protected:	//private
		char nazwa[20];
		float cena;
		int sztuk;
	public:
	//	towar();
		void czysc();
		void setNazwa(char *naz);
		bool setCena(float cena);		//zabezpieczenie przed zla cena
		void setSztuk(int szt);
		void pobierz(char *naz, float cen, int szt);
		char* getNazwa();
		float getCena();
		int getSztuk();
		float wartosc();
};
/*
towar::towar()
{
	strcpy(nazwa," ");
	cena=0;
	sztuk=0;
}
*/
void towar::czysc()
{
	strcpy(nazwa, " ");
	cena=0;
	sztuk=0;
}

void towar::setNazwa(char *naz)
{
	strcpy(nazwa,naz);
}
											//W WIEKSZOSCI KLAS TRZEBA MIEC WIECEJ SET'OW
bool towar::setCena(float cena)
{
	if(cena>0)
	{
		this->cena=cena; //this-> sluzy jako odnosnik do zmiennej, która nie bêdzie lokalna
		return 1;
	}
	else //nie musi
	{
		return 0;
	}
}

void towar::setSztuk(int szt) //powinno byc tak jak dla ceny
{
	sztuk=szt;	
}

void towar::pobierz(char *naz, float cen, int szt)
{
	strcpy(nazwa,naz);
	cena=cen;
	sztuk=szt;
}

char* towar::getNazwa()
{
	return nazwa;
}

float towar::getCena()
{
	return cena;
}

int towar::getSztuk()
{
	return sztuk;
}

float towar::wartosc()
{
	return cena*sztuk;
}

int main(int argc, char** argv) {
	towar t1, t2, tablica[5];
	char n[20],zn;
	float c;
	int sz;
	
	do
	{
		cout<<"1.czyszczenie"<<endl;
		cout<<"2.czytanie"<<endl;
		cout<<"3.wypisanie"<<endl;
		cout<<"4.wartosc"<<endl;
		cout<<"6.SetNazwa..."<<endl;
		cout<<"7.SetCena..."<<endl;
		cout<<"8.GetNazwa..."<<endl;
		cout<<"9.GetCena..."<<endl;
		cout<<"5.koniec"<<endl;
		
		zn=getch();
		switch(zn)
		{
			case '1':	t1.czysc();
				break;
			case '2':	{
							cout<<"nazwa: "; gets(n);
							cout<<"cena: "; cin>>c;
							cout<<"sztuk: "; cin>>sz;
							cin.ignore();
							t1.pobierz(n,c,sz); //lub seterami
							break;
						}
			case '3':		cout<<"Nazwa torwaru:	"<<t1.getNazwa()<<endl;
						cout<<"Cena torwaru:	"<<t1.getCena()<<endl;
						cout<<"Liczba sztuk:	"<<t1.getSztuk()<<endl<<endl;
				break;
			case '4':	cout<<"Wartosc towaru w magazynie: "<<t1.wartosc()<<endl;
				break;
			case '6':	cout<<"Nazwa: "; gets(n);
						t1.setNazwa(n);	//TYLKO DLA TESTOW MAMY STALA WARTOSC
				break;
			case '7':	cout<<"cena: "; cin>>c;
						cin.ignore();
						if(!t1.setCena(c))
							cout<<"Zla cena! Nie ustawiono ceny"<<endl;
						//t1.setCena(99.99);		//TYLKO DLA TESTOW MAMY STALA WARTOSC
				break;
			case '8':	cout<<"Nazwa towaru: "<<t1.getNazwa()<<endl;
				break;
			case '9':	cout<<"Cena towaru: "<<t1.getCena()<<endl;
				break;
			case '5':	cout<<"do widzenia"<<endl;
				getchar();
		}
	}
	while(zn!='5');
	return 0;
}
