/*
Projekt losuje liczb� ca�kowit�, a u�ytkownik ma j� odgadn��.
Gdy poda liczb� za ma�� lub za du�� otrzyma odpowiedni komunikat
i "zawr�ci" do ponownego odgadywania.
Gdy ju� odgadnie to "Gratulacje".

ZADANIE
U�ytkownik wpisuje do jakiej warto�ci ma si� losowa�
Od jakiej warto�ci do jakiej warto�ci, nale�y zabezpieczy� przed niepoprawnym przedzia�em
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;


int main()
{
	int losowana, typowana;
	cout<<"Zgadwanka"<<endl;
	srand(time(NULL));
	losowana = rand() % 101;
	//cout<<losowana<<endl;
	do
	{
		cout<<"Co typujesz?"<<endl;
		cin>>typowana;
		
		if(typowana>losowana)
			cout<<"Za duzo"<<endl;
		else
			if(typowana<losowana) 
				cout<<"Za malo"<<endl;
	}
	while(typowana!=losowana);
	//r�wne losowanej
	cout<<"Gratulacje! To ta liczba";
	system("pause");
	return 0;
}
