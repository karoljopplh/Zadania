#include <iostream>
#include <stdio.h>
#include <conio.h>	//biblioteka do getch()
#include <string.h>
#include <cstdlib>
#include <windows.h>

/**/
using namespace std;

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x-1;
	c.Y = y-1;
	SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), c);
}

int main() 
{
	char input;
	int x=6,y=6;
	
	do
	{
		input=getch();
	
		switch(input)
		{
			case 119:	gotoxy(x,y);
						cout<<" ";	//pressed w
						y--;
						gotoxy(x,y);
						cout<<"*";
					break;
						
			case 87:	gotoxy(x,y);
						cout<<" ";	//pressed W
						y--;
						gotoxy(x,y);
						cout<<"*";
					break;
			case 115:	gotoxy(x,y);
						cout<<" ";	//pressed s
						y++;
						gotoxy(x,y);
						cout<<"*";
					break;
			case 83:	gotoxy(x,y);
						cout<<" ";	//pressed S
						y++;
						gotoxy(x,y);
						cout<<"*";
					break;
			case 65:	gotoxy(x,y);
						cout<<" ";	//pressed a
						x--;
						gotoxy(x,y);
						cout<<"*";
					break;
			case 97:	gotoxy(x,y);
						cout<<" ";	//pressed A
						x--;
						gotoxy(x,y);
						cout<<"*";
					break;
			case 100:	gotoxy(x,y);
						cout<<" ";	//pressed d
						x++;
						gotoxy(x,y);
						cout<<"*";
					break;
			case 68:	gotoxy(x,y);
						cout<<" ";	//pressed D
						x++;
						gotoxy(x,y);
						cout<<"*";
					break;
		}
	}
	while(input!=27);
	return 0;
}