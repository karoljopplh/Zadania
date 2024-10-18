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
		towar();
		towar(char *naz, float cen, int szt);
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

towar::towar()
{
	strcpy(nazwa," ");
	cena=0;
	sztuk=0;
}

towar::towar(char *naz, float cen, int szt)
{
	strcpy(nazwa,naz);
	cena=cen;
	sztuk=szt;
}

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
	towar t1, t2("test", 6, 10), kopiat2(t2), tablica[5];// maj¹c 2 konstruktory, pierwszy jest bezparametryczny, a drugi parametryczny
	char n[20],zn;
	float c;
	int sz;
	
	do
	{
		cout<<"1.czyszczenie"<<endl;
		cout<<"2.czytanie"<<endl;
		cout<<"3.wypisanie"<<endl;
		cout<<"4.wartosc"<<endl;
		cout<<"5.koniec"<<endl;
		cout<<"6.czyszczenie t2"<<endl;
		cout<<"7.czytanie t2"<<endl;
		cout<<"8.wypisanie t2"<<endl;
		cout<<"9.wartosc t2"<<endl;
		cout<<"a.czyszczenie kopiat2"<<endl;
		cout<<"b.czytanie kopiat2"<<endl;
		cout<<"c.wypisanie kopiat2"<<endl;
		cout<<"d.wartosc kopiat2"<<endl<<endl;
		
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
			case '3':	cout<<"Nazwa torwaru:	"<<t1.getNazwa()<<endl;
						cout<<"Cena torwaru:	"<<t1.getCena()<<endl;
						cout<<"Liczba sztuk:	"<<t1.getSztuk()<<endl<<endl;
				break;
			case '4':	cout<<"Wartosc towaru w magazynie: "<<t1.wartosc()<<endl;
				break;
			case '6':	t2.czysc();
//						cout<<"Nazwa: "; gets(n);
//						t1.setNazwa(n);	//TYLKO DLA TESTOW MAMY STALA WARTOSC
				break;
			case '7':	{
							cout<<"nazwa: "; gets(n);
							cout<<"cena: "; cin>>c;
							cout<<"sztuk: "; cin>>sz;
							cin.ignore();
							t2.pobierz(n,c,sz); //lub seterami
							break;
						}	
//						cout<<"cena: "; cin>>c;
//						cin.ignore();
//						if(!t1.setCena(c))
//							cout<<"Zla cena! Nie ustawiono ceny"<<endl;
						//t1.setCena(99.99);		//TYLKO DLA TESTOW MAMY STALA WARTOSC
				break;
			case '8':	cout<<"Nazwa torwaru:	"<<t2.getNazwa()<<endl;
						cout<<"Cena torwaru:	"<<t2.getCena()<<endl;
						cout<<"Liczba sztuk:	"<<t2.getSztuk()<<endl<<endl;
//						cout<<"Nazwa towaru: "<<t1.getNazwa()<<endl;
				break;
			case '9':	cout<<"Wartosc towaru w magazynie: "<<t2.wartosc()<<endl;
//						cout<<"Cena towaru: "<<t1.getCena()<<endl;
				break;
			case 'a':	kopiat2.czysc();
				break;
			case 'b':	{
							cout<<"nazwa: "; gets(n);
							cout<<"cena: "; cin>>c;
							cout<<"sztuk: "; cin>>sz;
							cin.ignore();
							kopiat2.pobierz(n,c,sz); //lub seterami
							break;
						}	
				break;
			case 'c':	cout<<"Nazwa torwaru:	"<<kopiat2.getNazwa()<<endl;
						cout<<"Cena torwaru:	"<<kopiat2.getCena()<<endl;
						cout<<"Liczba sztuk:	"<<kopiat2.getSztuk()<<endl<<endl;
				break;
			case 'd':	cout<<"Wartosc towaru w magazynie: "<<kopiat2.wartosc()<<endl;
				break;
			case '5':	cout<<"do widzenia"<<endl;
				getchar();
		}
	}
	while(zn!='5');
	return 0;
}
