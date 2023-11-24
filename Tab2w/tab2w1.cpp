#include <iostream>
#include <cstdlib>
#include <windows.h>

#define XX 4
#define YY 3
/**/

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x-1;
	c.Y = y-1;
	SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), c)
}

using namespace std;
int main()
{
	int tab[XX][YY], ix, iy;
	goto()
	cout<<"Testowanie tablic 2W";
	for(iy=0; iy<YY; iy++)
	{
		for(ix=0; ix<XX; ix++)
		{
			cout<<"tab["<<ix<<"]["<<iy<<"] = ";
			cin>>tab[ix][iy];
		}
	}
	
	cout<<"Ponizej listing kontrolny:"<<endl;
	for(iy=0; iy<YY; iy++)
	{
		for(ix=0; ix<YY; ix++)
		{
			cout<<"tab["<<ix<<"]["<<iy<<"] = "<<tab[ix][iy]<<endl;
		}
	}
	
	system("pause");
	return 0;
}