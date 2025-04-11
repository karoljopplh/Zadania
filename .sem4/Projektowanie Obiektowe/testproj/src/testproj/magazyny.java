package testproj;

public class magazyny extends magazyn
{
	protected magazyn tablicaMagazynow[];
	protected int liczbaMagazynow;
	protected int licznoscMagazynow;
	
	public magazyny(int n)
	{
		liczbaMagazynow=n;
		tablicaMagazynow=new magazyn[liczbaMagazynow];
		for(int i=0; i<liczbaMagazynow; i++)
			tablicaMagazynow[i]=new magazyn(5);
		licznoscMagazynow=0;
	}
}
