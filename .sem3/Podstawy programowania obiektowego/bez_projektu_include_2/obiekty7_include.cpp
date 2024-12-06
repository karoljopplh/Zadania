#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <windows.h>

#include "towar.cpp"
#include "bazatowar.cpp"

using namespace std;

void piszTowarXY(towar t, int x, int y);

int main(int argc, char** argv) 
{
	
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