#ifndef ClassBazaTowar
	#define ClassBazaTowar
	#include <vector>
//	#include <string.h>
	#include "towar.hpp"
	using namespace std;
	
	class bazatowar
	{
		protected:
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
			float sumawartosc();
			void saveFile();
			void readFile();
			bool	setCurrent(int index);
			bool	next();
			bool	previous();
			int		getCurrent();
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
	#include "bazatowar.cpp"
#endif