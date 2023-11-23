#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() 
{
	int a, b;
	for(a=-10,b=20; a<=b; a++,b-=3)
	{
		cout<<a<<"   "<<b<<endl;
	}
	system("pause");
	return 0;
}