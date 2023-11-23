/*
In this program, the user is prompted to enter a number, and then a for loop is used to display the multiplication table for that number from 1 to 10.
v2 - asks how many times to multiply
v3 - asks if user wants to repeat the calculations
*/
#include <iostream>

using namespace std;

int main()
{
	int x = 0, y = 0, answer;
	cout<<"Multiplications of a number\n";
	do
	{
		answer = 0;
		cout<<"Enter a number\n";
		cin>>x;
		cout<<"How many times do you want to multiply it?\n";
		cin>>y;
		for(int i=1; i<=y; ++i)
		{
			cout<<x*i<<endl;
		}
		cout<<"Do you want to calculate another? yes-1 no-0\n";
		cin>>answer;
	}while(answer==1);
	return 0;
}
