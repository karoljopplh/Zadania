#include <stdio.h>
#include <windows.h>
#include <iostream>
using namespace std;
/*
1. Zrobic funkcje zliczania typu int z parametrami pierwszy parametr (nazwa pliku) drugi parametr(szukany znak).
Funkcja ma zliczyc liczbe wystapien znakow w pliku.

2. Funkcja typu void odwroc plik pierwszy parametr plik zrodlowy a drugi docelowy.
Funkcja ma utworzyc nowy plik (docelowy) zawierajacy odwrocony tekst z pierwszego.
*/

void odwrocplik(char zrodlowy, char docelowy);

int main()
{
	char c;
	char text2[20];
	FILE *fp;
	fp=fopen("pliktekstowy.txt","w");
	for (int i=1;i<=10;i++)
	{
		cout<<"podaj znak: ";
		cin>>c;
		putc(c, fp);
	}
	fprintf(fp, "\nTekst przykladowy z koncem linii\n");
	cout<<"Tekst do dodania: ";
	cin>>text2;
	fprintf(fp, text2);
	fclose(fp);
	cout<<"****zapisane****"<<endl;
	
	getchar();
	fp=fopen("pliktekstowy.txt","r");
	do
	{
		c=getc(fp);
		
		Sleep(30);
		if (c!=EOF)
		cout<<c;
	}
	while (c!=EOF);
	fclose(fp);
	cout<<endl<<"gotowe!!!!";
	
	//dopisanie na koniec pliku
	fp=fopen("pliktekstowy.txt","a");
	cout<<"Tekst do dodania: ";
	cin>>text2;
	fprintf(fp,"\n\n");
	fprintf(fp, text2);
	fclose(fp);
	//wydruk kontrolny
	fp=fopen("pliktekstowy.txt","r");
	//fseek(fp, -30, 2); //0 - wzg. poczatku, 1 - wzg. aktualnej poz, 2 - wzg
	do
	{
		Sleep(7);
		//fseek(fp, 1, 1);
		c=getc(fp);
		cout<<"NR: "<<ftell(fp)<<"   ";
		if(c==EOF)
			cout<<c;
	}
	while(c!=EOF);
	fclose(fp);
	cout<<endl<<"GOTOWE PO DODANIU TEKSTU";
	
	system("pause");
}

void odwrocplik(char zrodlowy, char docelowy)
{
	
}