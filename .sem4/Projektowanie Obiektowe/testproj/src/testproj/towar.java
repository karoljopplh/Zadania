package testproj;

public class towar 
{
	protected String nazwa;
	protected double cena;
	protected int sztuk;
	
	public towar()
	{
		nazwa="";
		sztuk=0;
		cena=0;
	}
	
	public towar(String naz, double cen, int szt)
	{
		nazwa=naz;
		sztuk=szt;
		cena=cen;
	}
	
	public void czysc()
	{
		nazwa="";
		sztuk=0;
		cena=0;
	}
	
	public void ustaw(String naz, double cen, int szt)
	{	//raczej NIE void
		nazwa=naz;
		sztuk=szt;
		cena=cen;
	}
	
	public void ustawNazwe(String naz)
	{	//NIE void
		nazwa=naz;
	}
	
	public void ustawSztuki(int szt)
	{	//NIE void
		sztuk=szt;
	}
	
	public void ustawCene(double cen)
	{	//NIE void
		cena=cen;
	}
	
	public String dajNazwe()
	{
		return nazwa;
	}
	
	public int dajSztuki()
	{
		return sztuk;
	}
	
	public double dajCene()
	{
		return cena;
	}
	
	public double wartosc()
	{
		return sztuk*cena;
	}
	
}
