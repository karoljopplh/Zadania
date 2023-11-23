/*
In this program, the user is prompted to enter a number, and then a for loop is used to display the multiplication table for that number from 1 to 10.
*/
#include <iostream>

using namespace std;

int main()
{
	int x = 0;
	cout<<"Multiplications of a number\n";
	cout<<"Enter a number\n";
	cin>>x;
	for(int i=1;i<=10;i++)
	{
		cout<<x*i<<endl;
	}
	return 0;
}
