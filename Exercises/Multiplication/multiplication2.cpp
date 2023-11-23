/*
In this program, the user is prompted to enter a number, and then a for loop is used to display the multiplication table for that number from 1 to 10.
v2 - asks how many times to multiply
*/
#include <iostream>

using namespace std;

int main()
{
	int x = 0, y = 0;
	cout<<"Multiplications of a number\n";
	cout<<"Enter a number\n";
	cin>>x;
	cout<<"How many times do you want to multiply it?";
	cin>>y;
	for(int i=1;i<=y;i++)
	{
		cout<<x*i<<endl;
	}
	return 0;
}
