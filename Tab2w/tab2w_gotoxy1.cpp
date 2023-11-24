#include <iostream>
#include <cstdlib>
#include <windows.h>

#define XX 5
#define YY 4
/**/

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
	int tab[XX][YY], ix, iy;
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
	gotoxy(32,15);
	cout<<"Po nacisnieciu listing kontrolny";
	system("pause>>NULL");
	system("cls");
	gotoxy(32,15);
	cout<<"Ponizej listing kontrolny:"<<endl;
	for(iy=0; iy<YY; iy++)
	{
		for(ix=0; ix<XX; ix++)
		{
			gotoxy((1+ix)*5-4, iy+2);
			cout<<tab[ix][iy];         
		}   
			                 
	} 
	
	gotoxy(22,15);
	cout<<"Po nacisnieciu klawisza koniec programu";
	system("pause>>NULL");
	return 0;
}