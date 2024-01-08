#include <iostream>
#include <stdio.h>
#include <conio.h>	//biblioteka do getch()
#include <cstdlib>
#include <windows.h>

/*Star game*/
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
	int x=5, y=5, max_x=50, max_y=20;
	
	//Spawning game borders
	for(int i=x-2; i<=max_x+2; i++)
	{
		if(i==x-2 || i==max_x+2)
		{
			for(int j=y; j<=max_y; j++)
			{
				gotoxy(i, j);
				cout<<"|";
			}
		}
		
		for(int j=y-2; j<=max_y+2; j++)
			{
				if(j==y-2 || j==max_y+2)
				{
					gotoxy(i, j);
					cout<<"_";
				}
			}
	}
	
	//target
	int tx=max_x/2, ty=max_y/2, i=1; //targets position, by default in the "middle"
	//bool direction=true;

	//gotoxy(tx,ty);
	//cout<<"X";
	
	do
	{
		//target movement
		do
		{
			gotoxy(tx,ty);
			cout<<" ";
			tx+=i;
			gotoxy(tx,ty);
			cout<<"X";
			Sleep(50);
			if(tx==max_x || tx==5)
				i=-i;
		}
		while(!kbhit());
		input=getch();
		
		//checking key presses, player movement
		//if(key)
		//{
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
				default: break;
			}
		//}
		// teleportation
		if(y>max_y)
		{
			gotoxy(x,y);
			cout<<" ";
			y=5;
			gotoxy(x,y);
			cout<<"*";
		}
		else if(y<5)
		{
			gotoxy(x,y);
			cout<<" ";
			y=max_y;
			gotoxy(x,y);
			cout<<"*";
		}
		else if(x>max_x)
		{
			gotoxy(x,y);
			cout<<" ";
			x=5;
			gotoxy(x,y);
			cout<<"*";
		}
		else if(x<5)
		{
			gotoxy(x,y);
			cout<<" ";
			x=max_x;
			gotoxy(x,y);
			cout<<"*";
		}
	}
	
	while(input!=27);
	return 0;
}