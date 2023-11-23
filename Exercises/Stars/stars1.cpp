/*
This program asks the user to enter the number of rows they want in the pattern and then uses nested loops to generate a triangular pattern of stars.
*/
#include <iostream>

using namespace std;
int main()
{
	int rows;
	do
	{
		cout<<"Enter the number of rows for the pattern: ";
		cin>>rows;
		if(rows>30 || rows<1)
			cout<<"The number of rows must be between 1 and 30";
	}
	while(rows>30 || rows<1);
	
	for(int i=1; i<=rows; i++)
	{
		for(int j=1; j<=rows-i; j++)
		{
			cout<<"  ";
		}
		
		for(int k=1; k<= 2 * i - 1; k++)
		{
			cout<<"* ";
		}
		
		cout<<"\n";
	}
    return 0;
}
	
	