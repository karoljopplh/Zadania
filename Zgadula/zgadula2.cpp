/*
Projekt losuje liczbę całkowitą, a użytkownik ma ją odgadnąć.
Gdy poda liczbę za małą lub za dużą otrzyma odpowiedni komunikat
i "zawróci" do ponownego odgadywania.
Gdy już odgadnie to "Gratulacje".

ZADANIE
Użytkownik wpisuje do jakiej wartości ma się losować
Od jakiej wartości do jakiej wartości, należy zabezpieczyć przed niepoprawnym przedziałem
*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;


int main()
{
	int losowana, typowana, from, to;
	cout<<"Zgadywanka"<<endl;
	
	cout<<"Od jakiej liczby chcesz zaczac"<<endl;
	cin>>from;
	
	cout<<"Do jakiej liczby chcesz zgadywac"<<endl;
	cin>>to;
	
	if(from>=to)
	{
		cout<<"Liczba \"od\" jest wieksza od liczby \"do\" (niepoprawne dane)"<<endl;
		return 0;
	}
	srand(time(NULL));
	losowana = from + (rand() % ( to - from + 1 ));
	//losowana = rand() % 101;
	//cout<<losowana<<endl;
	do
	{
		cout<<"Co typujesz? "<<endl;
		cin>>typowana;
		
		if(typowana>losowana)
			cout<<"Za duzo"<<endl;
		else
			if(typowana<losowana) 
				cout<<"Za malo"<<endl;
	}
	while(typowana!=losowana);
	//równe losowanej
	cout<<"Gratulacje! To ta liczba"<<endl;
	system("pause");
	return 0;
}
