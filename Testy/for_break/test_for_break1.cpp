#include <iostream>

/**/
using namespace std;
int main() 
{
	int lewa, prawa;
	cout<<"test for break"<<endl;
	cout<<"podaj lewa"<<endl;
	cin>>lewa;
	cout<<"podaj prawa"<<endl;
	cin>>prawa;
	for(;lewa<= prawa; lewa++,prawa-=2)
	{
		if(lewa==0 || prawa==0)
			break;
		cout<<"lewa="<<lewa<<"   prawa="<<prawa<<endl;
	}
	cout<<"nacisnij ENTER aby zakonczyc";
	getchar();
	return 0;
}