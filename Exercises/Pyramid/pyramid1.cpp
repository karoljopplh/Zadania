#include <iostream>

/*
This program asks the user to enter the height of the pyramid 
and then uses nested loops and conditional statements to print a pyramid pattern with ascending and descending numbers.
*/

using namespace std;

int main() 
{
	int height;
	
	cout<<"Enter the height of the pyramid: ";
	cin>>height;
	
	for(int i=1; i<=height; ++i)
	{
		for(int j=1; j<=height - i; ++j)
		{
			cout<<"    ";
		}
		
		for(int k=1; k<=i; ++k)
		{
			cout<<"  "<<k<<" ";
		}
		
		for(int l=i-1; l>=1; --l)
		{
			cout<<"  "<<l<<" ";
		}
		cout<<"\n";
	}
	return 0;
}