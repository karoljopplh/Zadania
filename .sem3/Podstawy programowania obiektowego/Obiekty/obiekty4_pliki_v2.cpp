#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string.h>
#include <windows.h>

using namespace std;
class towar
{
	protected:	//private
		char nazwa[20];
		float cena;
		int sztuk;
	public:
		towar();
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
class pojazd:public towar //
{
	protected:
		int predkosc;
		int moc;
	public:
		bool setPredkosc(int v);
		bool setMoc(int v);
		int getPredkosc();
		int getMoc();
};
*/
class bazatowar
{
	protected:
		int rozmiar;
		int licznosc;
		int current;	//-1 = brak
		towar *tab;			//wskazanie do obiektu towar
	private:
		int i;	//bardziej uniwersalnym orzwiazaniem jest deklarowanie lokalnego "i" w metodach
	public:
		bazatowar(int rozmiar);
		bazatowar();
		void dodajkolejny(char *naz, float cen, int szt);
		void czysccalosc();
		towar getTowar(int i);
		towar* getTab();
		int getLicznosc();
		int getRozmiar();
		float sumawartosc();
		void saveFile();
		void readFile();//powinny byc one jako bool'e
		bool	setCurrent(int index);
		bool	next();
		bool	previous();
		int		getCurrent();
		
};

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x-1;
	c.Y = y-1;
	SetConsoleCursorPosition(GetStdHandle (STD_OUTPUT_HANDLE), c);
}
void piszTowarXY(towar t, int x, int y);

//				METODY KLASY BAZATOWAR
bazatowar::bazatowar(int rozmiar) //konstrukt zyska� parametr
{
	this->rozmiar=rozmiar;
	tab=new towar[rozmiar];
	for (i=0;i<rozmiar;i++)
		tab[i].czysc();
	licznosc=0;
	current=-1;
}
bazatowar::bazatowar()
{
	this->rozmiar=10; //this nie jest konieczne
	tab=new towar[10];
	for(i=0;i<10;i++)
		tab[i].czysc();
	licznosc=0;
	current=-1;
}
void bazatowar::czysccalosc()
{
	rozmiar=10;
	for(i=0;i<rozmiar;i++)
		tab[i].czysc();
	licznosc=0;	
}
void bazatowar::dodajkolejny(char *naz, float cen, int szt)
{
	if(licznosc<rozmiar)
	{
		tab[licznosc].pobierz(naz,cen,szt);
		licznosc++;
		current=licznosc-1;
	}	
}
float bazatowar::sumawartosc()
{
	float suma_wart=0;
	for(i=0;i<rozmiar;i++)
		suma_wart+=tab[i].wartosc();
		return suma_wart;
}
int bazatowar::getLicznosc()
{
	return licznosc;
}
int bazatowar::getRozmiar()
{
	return rozmiar;
}
towar bazatowar::getTowar(int i) //nara�ona na wyj�cie poza zakres liczno�ci
{
	return tab[i];
}
towar* bazatowar::getTab()
{
	return tab;
}
void bazatowar::saveFile() //better: bool bazatowar::saveFile();
{
	FILE *fp;
/*
	better
	if ((fp = fopen(nazwa, "wb)) == NULL);
		return 0;
*/
	fp=fopen("pl.dat", "wb");
	fwrite(&rozmiar, sizeof(rozmiar), 1, fp);
	fwrite(&licznosc, sizeof(licznosc), 1, fp);	
//	fwrite(&current, sizeof(current), 1, fp);
	fwrite(tab, sizeof(*tab)*rozmiar, 1, fp);
	fclose(fp);
}
void bazatowar::readFile()
{
	FILE *fp;
	fp=fopen("pl.dat", "rb");
	fread(&rozmiar, sizeof(rozmiar), 1, fp);
	fread(&licznosc, sizeof(licznosc), 1, fp);
//	fread(&current, sizeof(current), 1, fp);
	fread(tab, sizeof(*tab)*rozmiar, 1, fp);
	fclose(fp);
	if(licznosc>0)
		current=0;	//ustawienie current gdy nie odczytany z pliku
	else
		current=-1;
}

bool bazatowar::setCurrent(int index)
{
	if (index>=0)
		return -1;
	if (index<licznosc)
		return -1;
	current=index;
}

int bazatowar::getCurrent()
{
	return current;
}

bool bazatowar::next()
{
	if((current+1)>=licznosc)
		return -1;
	current++;
}

bool bazatowar::previous()
{
	if((current-1)<0)
		return -1;
	current--;
}

void piszTowarXY(towar t, int x, int y)
{
	gotoxy(x, y);
	cout<<"Nazwa:                             ";
	gotoxy(x, y+1);
	cout<<"Cena:                             ";
	gotoxy(x, y+2);
	cout<<"Sztuk:                             ";
	gotoxy(x+8, y);
	cout<<t.getNazwa();
	gotoxy(x+8, y+1);
	cout<<t.getCena();
	gotoxy(x+8, y+2);
	cout<<t.getSztuk()<<endl;
}

/*
//				METODY KLASY POJAZD
bool pojazd::setPredkosc(int v)
{
	if(v>0)
	{
		this->predkosc=v;
		return 1;
	}
	else
		return 0;
}

bool pojazd::setMoc(int p)
{
	if(p>0)
	{
		this->moc=p;
		return 1;
	}
	else
		return 0;
}

int pojazd::getPredkosc()
{
	return predkosc;
}

int pojazd::getMoc()
{
	return moc;
}
*/
//				METODY KLASY TOWAR
towar::towar()
{
	strcpy(nazwa," ");
	cena=0;
	sztuk=0;
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
		this->cena=cena; //this-> sluzy jako odnosnik do zmiennej, kt�ra nie b�dzie lokalna
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
//	towar t1, t2, tablica[5];
//	pojazd auto1;
//	bazatowar baza;
	
	char n[20],zn;
	float c;
	int sz, i, rozmiar; //rozmiar jest tutaj jako lokalna zmienna
	
	cout<<"ile elementow w tablicy? ";
	cin>>rozmiar;
	cin.ignore();
	bazatowar baza(rozmiar); 	
	do
	{
		cout<<"1.czyszczenie"<<endl;
		cout<<"2.czytanie z dodaniem kolejnego elementu"<<endl;
		cout<<"3.wypisanie calej tablicy"<<endl;
		cout<<"4.suma wartosci"<<endl;
		cout<<"5.koniec"<<endl;
		cout<<"6.Save to File"<<endl;
		cout<<"7.Read from File"<<endl;
		cout<<"9.Display Current"<<endl;
		cout<<"a.Next"<<endl;
		cout<<"b.Previous"<<endl;
		cout<<"c.Set current"<<endl;
		zn=getch();
		
		system("cls");	
		
		switch(zn)
		{
			case '1':	baza.czysccalosc();
						break;
			case '2':	fflush(stdin);
						cout<<"nazwa: "; gets(n);
						cout<<"cena: "; cin>>c;
						cout<<"sztuk: "; cin>>sz;
						cin.ignore();
						baza.dodajkolejny(n,c,sz); //lub seterami
						break;
			case '3':	for(i=0; i<baza.getRozmiar(); i++)
						{
						cout<<baza.getTab()[i].getNazwa()<<"   ";
						cout<<baza.getTab()[i].getCena()<<"   ";
						cout<<baza.getTab()[i].getSztuk()<<endl;
						}
//						cout<<"Predkosc pojazdu:"<<auto1.getPredkosc()<<endl;
//						cout<<"Moc pojazdu:	"<<auto1.getMoc()<<endl;
						break;
			case '4':	cout<<"suma wszystkich wartosci= "<<baza.sumawartosc()<<endl;
						break;
			case '6':	baza.saveFile();
						cout<<"zapisano."<<endl;
						break;	
			case '7':	baza.readFile();	
						cout<<"Odczytano"<<endl;
						break;
			case '5':	cout<<"do widzenia"<<endl;
						getchar();
			case '9':	i=baza.getCurrent();
						if(i==-1)
							cout<<"Brak elementow"<<endl;
						else
							piszTowarXY(baza.getTowar(i), 5, 10);
						break;
			case 'a':	baza.next();
						i=baza.getCurrent();
						if(i==-1)
							cout<<"Brak elementow"<<endl;
						else
							piszTowarXY(baza.getTowar(i), 5, 10);
						break;
			case 'b':	baza.previous();
						i=baza.getCurrent();
						if(i==-1)
							cout<<"Brak elementow"<<endl;
						else
							piszTowarXY(baza.getTowar(i), 5, 10);
						break;
			case 'c':	cout<<"Podaj indeks elementu: ";
						cin>>i;
						baza.setCurrent(i);
						if(i==-1)
							cout<<"Brak elementow"<<endl;
						else
							if(i>=baza.getLicznosc())
								cout<<"Za wysoki indeks!"<<endl;
							else
								piszTowarXY(baza.getTowar(i), 5, 10);
						break;
		}
	}
	while(zn!='5');
	return 0;
}