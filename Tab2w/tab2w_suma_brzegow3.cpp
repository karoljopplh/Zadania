#include <iostream>
#include <cstdlib>
#include <windows.h>

#define XX 5
#define YY 5
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
	
	for(ix=0; ix<XX; ix++)
		suma+=tab[ix][ix]+tab[XX-1-ix][ix];
	if(XX%2 == 1)
		suma-=tab[XX/2][YY/2];
	
	cout<<"suma = "<<suma<<endl;
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
	
	gotoxy(22,15);
	cout<<"Po nacisnieciu klawisza koniec programu";
	system("pause>>NULL");
	return 0;
}