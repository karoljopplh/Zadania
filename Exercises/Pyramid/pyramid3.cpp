#include <iostream>

/*
This program asks the user to enter the height of the pyramid 
and then uses nested loops and conditional statements to print a pyramid pattern with ascending and descending numbers.
v2 - remains a pyramid after 10
v3 - protection against glithy sizes
*/

using namespace std;

int main() 
{
	int height;
	
	do
	{
		cout<<"Enter the height of the pyramid: ";
		cin>>height;
		if(height>15 || height<1)
			cout<<"Height must be between 1 and 15\n";
	}
	while(height>=16 || height<1);
	
	for(int i=1; i<=height; ++i)
	{
		for(int j=1; j<=height - i; ++j)
		{
			cout<<"    ";
		}
		
		for(int k=1; k<=i; ++k)
		{
			if(k<10)
			{
				cout<<"  "<<k<<" ";
			}
			else
			{
				cout<<" "<<k<<" ";
			}
			
		}
		
		for(int l=i-1; l>=1; --l)
		{
			if(l<10)
			{
				cout<<"  "<<l<<" ";
			}
			else
			{
				cout<<" "<<l<<" ";
			}
		}
		cout<<"\n";
	}
	return 0;
}