#include <iostream>
#include <cstdlib>
#include <windows.h>

#define XX 5
#define YY 5
/*
Po wprowadzeniu danych (wylosowaniu)
obliczyć sumę elementów: dodatnich, drugi ujemnych oraz zliczyć luczbę elementów: dodatnich, ujemnych, zer
*/

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x-1;
	c.Y = y-1;
	SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), c);
}

using namespace std;
int main()
{
	int tab[XX][YY], ix, iy, suma=0;
	gotoxy(28, 1);
	cout<<"Testowanie tablic 2W";
	//gotoxy(1,2);
	for(iy=0; iy<YY; iy++)
	{
		for(ix=0; ix<XX; ix++)
		{
			gotoxy((1+ix)*5-4, iy+2);
			cin>>tab[ix][iy];         
		}   
			                 
	}
	
	// Obliczanie ilości x>0, x<0 i x == 0
	int x,ile_d = 0, ile_u = 0, ile_z = 0; // ile_d (dodatnich), ile_u (ujemnych) ile_z (zer)
	int suma_d=0, suma_u=0; // suma_d (suma dodatnich), suma_u (suma ujemnych)
	float srednia_u = 0 , srednia_d = 0;
	for(int i=0; i<XX; i++)
		for(int j=0; j<YY; j++)
		{
			x=tab[i][j];
			
			if(x==0)
				ile_z+=1;
			else if(x<0)
			{
				ile_u+=1;
				suma_u+=tab[i][j];
			}
			else //x>0
			{
				ile_d+=1;
				suma_d+=tab[i][j];
			}
		}
	
	srednia_d = suma_d/ile_d;
	srednia_u = suma_u/ile_u;
	cout<<endl<<"Ilosc dodatnich: "<<ile_d<<endl;
	cout<<"Suma dodatnich: "<<suma_d<<endl;
	cout<<"Srednia dodatnich: "<<srednia_d<<endl;
	cout<<"Ilosc ujemnych: "<<ile_u<<endl;
	cout<<"Suma ujemnych: "<<suma_u<<endl;
	cout<<"Srednia ujemnych: "<<srednia_u<<endl;
	cout<<"Ilosc zer: "<<ile_z<<endl;
	
	
	/*
	for(ix=0; ix<XX; ix++)
		suma+=tab[ix][0]+tab[ix][YY-1];
	for(iy=1; iy<YY-1; iy++)
		suma+=tab[0][iy]+tab[XX-1][iy];
	*/
	/*for(int i=0; i<=YY;i++)
	{
		if(i==0 || i==YY-1)
		{
			for(int j=0; j<XX;j++)
			{
				suma+=tab[i][j];
				cout<<"Debug "<<"tab["<<i<<"]["<<j<<"] = "<<tab[i][j]<<" suma ="<<suma<<endl;
			}
		}
		else
		{
			for(int j=0; j<XX;j+=XX-1)
			{
				suma+=tab[i][j];
				cout<<"Debug "<<"tab["<<i<<"]["<<j<<"] suma ="<<suma<<endl;
			}
		}
	}*/
	/*
	for(ix=0; ix<XX; ix++)
		suma+=tab[ix][ix]+tab[XX-1-ix][ix];
	if(XX%2 == 1)
		suma-=tab[XX/2][YY/2];
	*/
	
	for(ix=0; ix<XX; ix++)
	{
		for(iy=ix; iy>=0; iy--)
		{
			suma+=tab[ix][iy];
			//cout<<"Debug "<<"tab["<<ix<<"]["<<iy<<"] suma ="<<suma<<endl;
		}
	}
	
	cout<<"suma wszystkich = "<<suma<<endl;
	cout<<"Po nacisnieciu listing kontrolny";
	system("pause>>NULL");
	system("cls");gotoxy(32,15);
	cout<<"Ponizej listing kontrolny:"<<endl;
	for(iy=0; iy<YY; iy++)
	{
		for(ix=0; ix<XX; ix++)
		{
			gotoxy((1+ix)*5-4, iy+2);
			cout<<tab[ix][iy];         
		}   
			                 
	}
	cout<<endl<<"Ilosc dodatnich: "<<ile_d<<endl;
	cout<<"Suma dodatnich: "<<suma_d<<endl;
	cout<<"Ilosc ujemnych: "<<ile_u<<endl;
	cout<<"Suma ujemnych: "<<suma_u<<endl;
	cout<<"Ilosc zer: "<<ile_z<<endl;
	
	gotoxy(22,15);
	cout<<"Po nacisnieciu klawisza koniec programu";
	system("pause>>NULL");
	return 0;
}