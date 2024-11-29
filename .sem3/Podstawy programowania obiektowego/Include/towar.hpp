#ifndef ClassTowar
	#define ClassTowar
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
	#include "towar.cpp"
#endif