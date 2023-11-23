/*
This program asks the user to enter the number of rows they want in the pattern and then uses nested loops to generate a triangular pattern of stars.
v2 - protected against "glithy amounts of stars"
v3 - asks if you want to repeat at the end
*/
#include <iostream>

using namespace std;
int main()
{
	int rows;
	char repeat;
	
	do
	{
	
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
		cout<<"Do you want to repeat the code? (y/n): ";
        cin>>repeat;
	}
	while(repeat == 'y' || repeat == 'Y');
    return 0;
}
	
	