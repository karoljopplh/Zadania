#include <iostream>
#define XX 4
#define YY 3
/**/

using namespace std;
int main()
{
	int tab[XX][YY], ix, iy;
	
	for(iy=0; iy<YY; iy++)
	{
		for(ix=0; ix<XX; ix++)
		{
			cout<<"tab["<<ix<<"]["<<iy<<"] = ";
			cin>>tab[ix][iy];
		}
	}
	
	cout<<"Ponizej listing kontrolny:"<<endl;
	for(iy=0; iy<YY; iy++)
	{
		for(ix=0; ix<YY; ix++)
		{
			cout<<"tab["<<ix<<"]["<<iy<<"] = "<<tab[ix][iy]<<endl;
		}
	}
	
	system("pause");
	return 0;
}