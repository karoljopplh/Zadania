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
				break;
		case 2: cout<<"Wczytano 2"<<endl;
				break;
		case 3: cout<<"Wczytano 3"<<endl;
				break;
		case 4: cout<<"Wczytano 4"<<endl;
				break;
		default: cout<<"Wczytano cos innego"<<endl;
	}
	cout<<"nacisnij ENTER aby zakonczyc";
	getchar();
	return 0;
}