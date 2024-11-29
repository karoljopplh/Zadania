#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <vector>

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

class bazatowar
{
	protected:
		int rozmiar;
		int licznosc;
		int licznoscFound;
		int current;	//-1 = brak
		int currentFound;
		vector<towar> tab;
		vector<towar> found;
	private:
		int i;	//bardziej uniwersalnym orzwiazaniem jest deklarowanie lokalnego "i" w metodach - bruh then why are we doing this
	public:
		bazatowar();
		void dodajkolejny(char *naz, float cen, int szt);
		void czysccalosc();
		towar getTowar(int i);
		towar getTab();
		int getLicznosc();
	//	int getRozmiar();
		float sumawartosc();
		void saveFile();
		void readFile();
		bool	setCurrent(int index);
		bool	next();
		bool	previous();
		int		getCurrent();
	//	void	deleteCurrent();
		void	delete2Current();
		void	sortCena();
		void	sortNazwa();
		bool	searchCena(float min, float max);	//int is better, since we can respond to specific errors and not done or not
		bool	searchNazwa(char szukanaNazwa[]);
		int		getLicznoscFound();
		int		getCurrentFound();
		towar	getTowarFound(int i);
		towar	getFound();
		bool	nextFound();
		bool	previousFound();
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
/*bazatowar::bazatowar(int rozmiar) //konstrukt zyska� parametr
{
	this->rozmiar=rozmiar;
	tab=new towar[rozmiar];
	for (i=0;i<rozmiar;i++)
		tab[i].czysc();
	licznosc=0;
	current=-1;
}
*/
bazatowar::bazatowar()
{
	licznosc=0;
	current=-1;
	licznoscFound=0;
	currentFound=-1;
}

void bazatowar::czysccalosc()
{
	tab.erase(tab.begin(), tab.end());
	licznosc=0;
	current=-1;
}

void bazatowar::dodajkolejny(char *naz, float cen, int szt)
{
	towar t;
	t.pobierz(naz, cen, szt);
	tab.push_back(t);
	licznosc++;
	current=licznosc-1;
}
float bazatowar::sumawartosc()
{
	float suma_wart=0;
	for(i=0;i<licznosc;i++)
		suma_wart+=tab[i].wartosc();
	return suma_wart;
}
int bazatowar::getLicznosc()
{
	return licznosc;
}
/*
int bazatowar::getRozmiar()
{
	return rozmiar;
}
*/
towar bazatowar::getTowar(int i) //nara�ona na wyj�cie poza zakres liczno�ci
{
	return tab[i];
}

towar bazatowar::getTowarFound(int i)
{
	return found[i];
}

towar bazatowar::getTab()
{
	return tab.at(current);
}

towar bazatowar::getFound()
{
	return found.at(current);
}

void bazatowar::saveFile() //better: bool bazatowar::saveFile();
{
	FILE *fp;
	fp=fopen("datavector.dat", "wb");
	licznosc=tab.size();
//	fwrite(&rozmiar, sizeof(rozmiar), 1, fp);
	fwrite(&licznosc, sizeof(licznosc), 1, fp);	
	for(int i=0; i<tab.size(); i++)
		fwrite(&tab[i], sizeof(tab[i]), 1, fp);
	fclose(fp);
}
void bazatowar::readFile()
{
	FILE *fp;
	tab.erase(tab.begin(), tab.end());
	towar t;
	licznosc=0;
	current=-1;
	fp=fopen("datavector.dat", "rb");
//	fread(&rozmiar, sizeof(rozmiar), 1, fp);
	fread(&licznosc, sizeof(licznosc), 1, fp);
	for(int i=0; i<tab.size(); i++)
	{
		fread(&t, sizeof(t), 1, fp);
		tab.push_back(t);
	}
	fclose(fp);
	if(licznosc>0)
		current=0;	//ustawienie current gdy nie odczytany z pliku
	else
		current=-1;
}

bool bazatowar::setCurrent(int index)
{
	if(index>=0 && index<licznosc)
	{
		current=index;
		return true;
	}
	return false;
}

int bazatowar::getCurrent()
{
	return current;
}

bool bazatowar::next()
{
	if((current+1)>=licznosc)
		return 0;
	current++;
	return 1;
}

bool bazatowar::previous()
{
	if((current-1)<0)
		return 0;
	current--;
	return 1;
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
void bazatowar::deleteCurrent()
{
	for(int i=current; i<licznosc; i++)
		tab[i]=tab[i+1];
	licznosc--;
}
*/
void bazatowar::delete2Current()
{
	if(licznosc>=1)
	{
		tab.erase(tab.begin() + current);
		if(current==licznosc-1)
			current--;
		licznosc--;
	}
}

void	bazatowar::sortCena()
{
	for (int i = 1; i < licznosc; ++i) 
	{
        float key = tab[i].getCena();
        int j = i - 1;

        while (j >= 0 && tab[j].getCena() > key) 
		{
            tab[j + 1].setCena(tab[j].getCena());
            j = j - 1;
        }
        tab[j + 1].setCena(key);
    }
}

void	bazatowar::sortNazwa()
{
	for (int i = 1; i < licznosc; ++i) 
	{
        char key[20];
        strcpy(key, tab[i].getNazwa());
        int j = i - 1;
        
        while (j >= 0 && (strcmp(key, tab[j].getNazwa())) < 0) 
		{
            tab[j + 1].setNazwa(tab[j].getNazwa());
            j = j - 1;
        }
        tab[j+1].setNazwa(key);
    }
}

bool	bazatowar::searchCena(float min, float max)
{
	licznoscFound = 0;
	currentFound=-1;
	found.erase(found.begin(), found.end());
	for(int i=0; i<licznosc; i++)
	{
		if(tab[i].getCena() >= min && tab[i].getCena() <= max)
		{
			found.push_back(tab[i]);
			licznoscFound++;
		}
	}
	if(licznoscFound)
	{
		currentFound=0;
		return 1;
	}
	else
		return 0;
}

bool	bazatowar::searchNazwa(char szukanaNazwa[])
{
	licznoscFound = 0;
	currentFound = -1;
	found.erase(found.begin(), found.end());
	for(int i=0; i<licznosc; i++)
	{
		if(strcmp(szukanaNazwa, tab[i].getNazwa())==0)
		{
			found.push_back(tab[i]);
			licznoscFound++;
		}
	}
	if(licznoscFound)
	{
		currentFound=0;
		return 1;
	}
	else
		return 0;
}

int		bazatowar::getLicznoscFound()
{
	return licznoscFound;
}

int		bazatowar::getCurrentFound()
{
	return currentFound;
}

bool	bazatowar::nextFound()
{
	if((currentFound+1)>=licznoscFound)
		return 0;
	currentFound++;
	return 1;
}

bool	bazatowar::previousFound()
{
	if((currentFound-1)<0)
		return 0;
	currentFound--;
	return 1;
}

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
	
	char n[20],zn, szukanaNazwa[20];
	float c, min, max;
	int sz, i, rozmiar; //rozmiar jest tutaj jako lokalna zmienna
/*	
	cout<<"ile elementow w tablicy? ";
	cin>>rozmiar;
	cin.ignore();
*/
	bazatowar baza; 	
	do
	{
		cout<<"1.czyszczenie"<<endl;
		cout<<"2.czytanie z dodaniem kolejnego elementu"<<endl;
		cout<<"3.wypisanie calej tablicy"<<endl;
		cout<<"4.suma wartosci"<<endl;
		cout<<"6.Save to File"<<endl;
		cout<<"7.Read from File"<<endl;
	//	cout<<"8.Delete Current"<<endl;
		cout<<"u.Delete Current v2"<<endl;
		cout<<"9.Display Current"<<endl;
		cout<<"a.Next"<<endl;
		cout<<"b.Previous"<<endl;
		cout<<"c.Set current"<<endl;
		cout<<"s.Sort cena asc"<<endl;
		cout<<"n.Sort name asc"<<endl;
		cout<<"S. Search Cena"<<endl;
		cout<<"N. Search Nazwa"<<endl;
		cout<<"A. Next Found"<<endl;
		cout<<"B. Previous Found"<<endl;
		cout<<"5.koniec"<<endl;
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
			case '3':	for(i=0; i<baza.getLicznosc(); i++)
						{
						cout<<baza.getTowar(i).getNazwa()<<"   ";
						cout<<baza.getTowar(i).getCena()<<"   ";
						cout<<baza.getTowar(i).getSztuk()<<endl;
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
						break;
/*			case '8':	cout<<"Czy na pewno chcesz usunac ten index:"<<endl;
						cout<<"T-tak, N-nie"<<endl;
						piszTowarXY(baza.getTowar(i), 5, 10);
						zn=getch();
						switch(zn)
						{
							case 'T':	cout<<"usunieto"<<endl;
										baza.deleteCurrent();
										break;
							case 'N':	cout<<"anulowano"<<endl;
										break;
							case 't':	cout<<"usunieto"<<endl;
										baza.deleteCurrent();
										break;
							case 'n':	cout<<"anulowano"<<endl;
										break;
						}
					//	przed usunieciem wypisac/upewnic
						break;
						*/
			case 'u':	baza.delete2Current();
					//	przed usunieciem wypisac/upewnic
						break;
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
			case 's':	baza.sortCena();
						cout<<"Posortowano"<<endl;
						break;
			case 'n':	baza.sortNazwa();
						cout<<"Posortowano"<<endl;
						break;
			case 'S':	cout<<"min: ";
						cin>>min;
						cout<<"max: ";
						cin>>max;
						if(!baza.searchCena(min, max))
							cout<<"nic nie znaleziono"<<endl;
						else
						{
							i=baza.getCurrent();
							piszTowarXY(baza.getTowar(i), 5, 10);	
						}
						break;
			case 'N':	cout<<"Podaj szukana nazwe: ";
						fflush(stdin);
						gets(n);
						if(baza.searchNazwa(szukanaNazwa))
							cout<<"Nic nie znaleziono"<<endl;
						else
							piszTowarXY(baza.getTowarFound(i), 5, 10);
						break;
			case 'A':	baza.nextFound();
						i=baza.getCurrentFound();
						if(i==-1)
							cout<<"Brak znalezionych elementow."<<endl;
						else
							piszTowarXY(baza.getTowarFound(i), 5, 10);
						break;
			case 'B':	baza.previousFound();
						i=baza.getCurrentFound();
						if(i==-1)
							cout<<"Brak znalezionych elementow."<<endl;
						else
							piszTowarXY(baza.getTowarFound(i), 5, 10);
						break;
		}
	}
	while(zn!='5');
	return 0;
}