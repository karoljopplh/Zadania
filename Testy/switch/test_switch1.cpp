#include <iostream>

/**/
using namespace std;
int main() 
{
	int cyfra;
	cout<<"Podaj cyfre (1-4)";
	cin>>cyfra;
	switch(cyfra)
	{
		case 1: cout<<"Wczytano 1"<<endl;
		case 2: cout<<"Wczytano 2"<<endl;
		case 3: cout<<"Wczytano 3"<<endl;
		case 4: cout<<"Wczytano 4"<<endl;
		default: cout<<"Wczytano cos innego"<<endl;
	}
	cout<<"nacisnij ENTER aby zakonczyc";
	getchar();
	return 0;
}