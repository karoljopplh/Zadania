class osoba
{
	protected:
		imie[10],nazwisko[25];
		int PESEL;
	public:
		osoba();
		void setImie(char i);
		char getImie();
		void setNazwisko(char n);				
		char getNazwisko();
		void setPESEL(int P);
		int getPESEL;
		void dodajosobe(char i,char n,int P);	
}
class pracownik:public osoba
{
	protected:
			int liczbagodzin=0;
			char stawka=0;
	public:
		pracownik();
		bool setLiczbagodzin(int l);
		bool setStawka(float s);
		int getLiczbagodzin();
		char getStawka();
		void dodaj(char i,char n,int P);
		float wyplata();
		
}
class kadra:public pracownik
{
	protected:
		int zespol [];
		int liczbapracownikow,maxwielkosckadry;
		public:
			kadra();
			~kadra();
			void dodajpracownika(int l,float s,char i,char n,int P);
}
	osoba::osoba();
	{
		strcpy(imie,"")
		strcpy(nazwisko,"")
		PESEL=0;
	}

	void osoba::setImie(char i)
	{
		imie= i;
	}
	void osoba::setNazwisko(char n)
	{
		nazwisko=n;
	}	
	void osoba::setPesel(char P)
	{
		PESEL= P;
	}	
	char osoba::getImie()
	{
		return imie;
	}
	char osoba::getNazwisko()
	{
		return nazwisko;
	}	
	char osoba::getPESEL()
	{
		return PESEL;
	}
		void osoba::dodajosobe(char i,char n,char P)
	{
		strcpy(imie,i)
		strcpy(nazwisko,n)
		PESEL=P;	
	}
	pracownik::pracownik()
	{
		liczbagodzin=0;
		stawka=0;
	}
	void pracownik::dodaj(int l,float s,char i,char n,int P)
	{
		liczbagodzin=l;
		stawka=s;
		osoba.dodajosobe(i,n,P);
	}
	bool pracownik::setLiczbagodzin(int v)
	{
		if(v<0)
			return false
		else
		{
			liczbagodzin=v;
			return true;
		}
	}
	bool pracownik::setStawka(int s)
	{
		if(s<0)
			return false
		else
		{
			stawka=s;
			return true;
		}
	}
	int pracownik::getLiczbagodzin()
	{
		return liczbagodzin;
	}
	float pracownik::getStawka()
	{
		return stawka;
	}
	kadra::kadra()
	{
	new tab= int zespol;
	liczbapracownikow=0;
	amxwielkosckadry=0
	}
	kadra::~kadra();
	{
		delete[] zespol;
	}
	void kadra::dodajpracownika(int l,float s,char i,char n,int P)
	{
	
		if(liczbapracownikow<maxwielkosckadry)
		{
			liczbapracownikow++;
			pracownik.dodaj(l,s,i,n,P);
		}
	}
	float pracownik::wyplata(){
		return liczbagodzin*stawka;
	}

		
	

	
	
