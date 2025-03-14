package testproj;

public class auto extends towar
{
	private int pojemnosc;
	private int moc;
	
	public auto()
	{
		super();
		pojemnosc=1000;
		moc=50;
	}
	
	public auto(String naz, double cen, int szt, int poj, int moc)
	{
		super(naz, cen, szt);
		pojemnosc=poj;
		this.moc=moc;
	}
	
	public void czysc()
	{
		super.czysc();
		pojemnosc=0;
		moc=0;
	}
	
	public void ustaw (String naz, double cen, int szt, int poj, int m)
	{	//zamiast void lepiej int - kod błędu
		nazwa=naz;	//better super.ustaw(....);
		sztuk=szt;
		cena=cen;
		pojemnosc=poj;
		moc=m;
	}
	
	public void ustawPojemnosc(int poj)
	{
		pojemnosc=poj;
	}
	
	public void ustawMoc(int m)
	{
		moc=m;
	}
	
	public int dajPojemnosc()
	{
		return pojemnosc;
	}
	
	public int dajMoc()
	{
		return moc;
	}
	
}