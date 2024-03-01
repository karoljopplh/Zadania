#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <conio.h>
#define N 100
/*A little dive into sorting algorithyms*/
using namespace std;
void makearray(int t[], int n);
void displayarray(int t[], int n);
void shuffle(int* arr, int size);
void swap(int& a, int& b);

int main() 
{
	srand(time(NULL));
	int tab[N];
	makearray(tab, N);
	displayarray(tab, N);
	cout<<endl<<endl;
	shuffle(tab, N);
	displayarray(tab, N);
	return 0;
}

//	Function Definitions
void makearray(int t[], int n)
{
	for(int i=0; i<n; i++)
		t[i]=i+1;
}

void displayarray(int t[], int n)
{
	for(int i=0; i<n; i++)
		cout<<t[i]<<" ";
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void shuffle(int* arr, int n)
{
    srand(time(nullptr));
    
    //Fisher-Yates shuffle
    for (int i = n - 1; i > 0; --i) 
	{
        int j = rand() % (i + 1);
        swap(arr[i], arr[j]);
    }
}

/*
void scramble(int t[], int n)	//failed attempt
{
	int aux[n];
	for(int i=0; i<n; i++)
	{
		t[i]=aux[i];
	}
	for(int i=0, x, y; i<n; i++)
	{
		do
		{
			x=rand() % N;
			y=rand() % N;
		}
		while(aux[y] = 0);
		
		t[x] = aux[y];
		aux[y] = 0;
	}
}*/