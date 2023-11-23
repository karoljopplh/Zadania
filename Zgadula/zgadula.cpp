/*
Projekt losuje liczbê ca³kowit¹, a u¿ytkownik ma j¹ odgadn¹æ.
Gdy poda liczbê za ma³¹ lub za du¿¹ otrzyma odpowiedni komunikat
i "zawróci" do ponownego odgadywania.
Gdy ju¿ odgadnie to "Gratulacje".

ZADANIE
U¿ytkownik wpisuje do jakiej wartoœci ma siê losowaæ
Od jakiej wartoœci do jakiej wartoœci, nale¿y zabezpieczyæ przed niepoprawnym przedzia³em
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
	//równe losowanej
	cout<<"Gratulacje! To ta liczba";
	system("pause");
	return 0;
}
