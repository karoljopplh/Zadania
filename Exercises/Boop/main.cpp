#include <iostream>
#include "stuff.h"
/*
Stuff to do
-Create basic class with private variables and public functions that return the variables
-Add constructor
-Add destructor

-Create class that inherits from previous class
-Override a function from the base class
*/

/*
class boop
{
	int a=1, b=2, c=3;
	public:
		int do_a()
		{
			return a;
		}
		int do_b()
		{
			return b;
		}
		int do_c()
		{
			return c;
		}
		boop()
		{
			std::cout<<"bob the builder \n";
		}
		boop(int d)
		{
			a=d;
		}
		
};*/


int main() {
	square flat(1.5,2);
	std::cout<<flat.width<<" ";
	std::cout<<flat.height<<"\n";
	flat.width = 6.9;
	flat.height = 420;
	std::cout<<flat.width<<" ";
	std::cout<<flat.height<<"\n";
	std::cout<<flat.area()<<"\n";
	box xbox;
	xbox.height=1;
	xbox.width=2;
	xbox.depth=3;
	std::cout<<xbox.width<<" ";
	std::cout<<xbox.height<<" ";
	std::cout<<xbox.depth<<"\n";
	std::cout<<xbox.area()<<"\n";
	std::cout<<xbox.square::area()<<"\n";
	/*
	boop x;
	std::cout<<x.do_a()<<"\n";
	std::cout<<x.do_b()<<"\n";
	std::cout<<x.do_c()<<"\n";
	*/
	return 0;
}