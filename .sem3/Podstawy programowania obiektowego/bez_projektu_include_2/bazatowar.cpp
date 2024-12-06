#include "bazatowar.hpp"
#ifndef ClassTowar
	#include <string.h>
#endif
using namespace std;

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x-1;
	c.Y = y-1;
	SetConsoleCursorPosition(GetStdHandle (STD_OUTPUT_HANDLE), c);
}

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
towar bazatowar::getTowar(int i) //nara?ona na wyj?cie poza zakres liczno?ci
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