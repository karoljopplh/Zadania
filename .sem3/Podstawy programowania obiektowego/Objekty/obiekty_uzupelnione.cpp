#include <iostream>

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
		bool setCena(float cena);
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

void towar::czysc()
{
	strcpy(nazwa, " ");
	cena=0;
	sztuk=0;
}

void towar::setNazwa(char *naz);
{
	strcpy(nazwa,naz);
}

bool towar::setCena(float cena)
{
	if(cena>0)
	{
		this->cena=cena;
		return 1;
	}
	else
	{
		return 0;
	}
}

void towar::setSztuk()
{
	
}

towar::getNazwa()
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
		cout<<"4.wartosc"<<endl;
		cout<<""
	}
	return 0;
}