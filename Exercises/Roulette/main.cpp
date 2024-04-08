#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>

using namespace std;

void reload(bool t[], int n);
void display(bool t[], int n);
void displayRounds(bool t[], int n);
bool yesOrno();
/**/

int main() 
{
	bool *round, response;
	int p_lives=3, e_lives=3, n=8;
	int ready;
	cout<<"How many bullets?\n";
	cin>>n;
	round=new bool[n];
	srand(time(NULL));
	
	reload(round, n);
	display(round, n);
	displayRounds(round, n);
	do
	{
		cin.sync();
		cout<<"ARE YOU READY?\n";
		response=yesOrno();
		if(!response)
			break;
		
		//shooting
		cin.sync();
		fflush(stdin);
		cout<<"M-Aim at yourself, E-Aim at the enemy\n";
		
		
		
	}
	while(p_lives>0);
	
	return 0;
}

bool yesOrno()	//Does not work
{
	int response;
	cout<<"Y-yes N-no\n";
	cin.sync();
	fflush(stdin);
	response = getchar();
	if(response==89 || response==121)
		return 1;
	if(response==78 || response==110)
		return 0;
	yesOrno();
}

void displayRounds(bool t[], int n)
{
	int live=0, blank=0;
	for(int i=0; i<n; i++)
	{
		if(t[i]==1)
			live++;
		else
			blank++;
	}
	cout<<"Live rounds: "<<live<<" \nBlank rounds: "<<blank<<"\n";
}

void display(bool t[], int n)
{
	for(int i=0; i<n; i++)
		cout<<t[i]<<" ";
	cout<<endl;
}

void reload(bool t[], int n)
{
	for(int i=0; i<n; i++)
		t[i]= rand() % 2;
}