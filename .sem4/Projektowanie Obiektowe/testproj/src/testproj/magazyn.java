package testproj;
import java.io.*;

public class magazyn extends towar 
{
	protected towar towary[];
	protected int rozmiar;
	protected int licznosc;
	
	public magazyn()
	{
		rozmiar=0;
		licznosc=0;
	}
	
	public magazyn(int n)
	{
		rozmiar = n;
		towary=new towar[rozmiar];
		for(int i=0; i<rozmiar; i++)
			towary[i]=new towar();
		licznosc=0;
	}
	
	public String dajNazwe(int i)
	{
		return towary[i].dajNazwe();
	}
	
	public double dajCene(int i)
	{
		return towary[i].dajCene();
	}
	
	public int dajSztuki(int i)
	{
		return towary[i].dajSztuki();
	}
	
	public int dajLicznosc()
	{
		return licznosc;
	}
	
	public void dopisz(String naz, double cen, int szt)
	{
		towary[licznosc].ustaw(naz, cen, szt);
	}
	
	public void czyscTowary()
	{
		for (int i=0; i<licznosc; i++)
			towary[i].czysc();
		licznosc=0;
	}
	
	public void zapiszDoPliku()
	{
		FileOutputStream strumienZapisu=null;
		File plik=new File("dane.dat");
		
		try
		{
			strumienZapisu= new FileOutputStream(plik);
		}
		catch (FileNotFoundException e)
		{
			System.err.println("NIE MA TAKIEGO PLIKU " + e);	//powinno byc do klasy obslugujacej
			System.exit(-1);
		}
		
		DataOutputStream sd=new DataOutputStream(strumienZapisu);
		try
		{
			sd.writeInt(licznosc);
		}
		catch(IOException e)
		{
			System.err.println("NIEUDANY ZAPIS LICZNOSCI ELEMENTOW" + e);
			System.exit(-1);
		}
		
		for (int i=0; i<licznosc; i++)
		{
			try
			{
				sd.writeUTF(towary[i].nazwa);
				sd.writeDouble(towary[i].cena);
				sd.writeInt(towary[i].sztuk);
			}
			catch (IOException e)
			{
				System.err.println("NIEUDANY ZAPIS ELEMENTY NR " + i + "Exception " + e);
				System.exit(-1);
			}
		}
		
		try
		{
			sd.close();
		}
		catch(IOException e)
		{
			System.err.println("NIEUDANE ZAMKNIECIE STRUMIENIA DANYCH" + e);
			System.exit(-1);
		}
		
		try
		{
			strumienZapisu.close();
		}
		catch(IOException e)
		{
			System.err.println("NIEUDANE ZAMKNIECIE STRUMIENIA DANYCH" + e);
			System.exit(-1);
		}
	}
	
	public void czytajZPliku()
	{
		FileInputStream strumienOdczytu=null;
		File plik=new File("dane.dat");
		
		try
		{
			strumienOdczytu= new FileInputStream(plik);
		}
		catch (FileNotFoundException e)
		{
			System.err.println("NIE MA TAKIEGO PLIKU " + e);	//powinno byc do klasy obslugujacej
			System.exit(-1);
		}
		
		DataInputStream sd=new DataInputStream(strumienOdczytu);
		try
		{
			licznosc=sd.readInt();
		}
		catch(IOException e)
		{
			System.err.println("NIEUDANY ZAPIS LICZNOSCI ELEMENTOW" + e);
			System.exit(-1);
		}
		
		for (int i=0; i<licznosc; i++)
		{
			try
			{
				towary[i].nazwa=sd.readUTF();
				towary[i].cena=sd.readDouble();
				towary[i].sztuk=sd.readInt();
			}
			catch (IOException e)
			{
				System.err.println("NIEUDANY ODCZYT ELEMENTY NR " + i + "Exception " + e);
				System.exit(-1);
			}
		}
		
		try
		{
			sd.close();
		}
		catch(IOException e)
		{
			System.err.println("NIEUDANE ODCZYT STRUMIENIA DANYCH" + e);
			System.exit(-1);
		}
		
		try
		{
			strumienOdczytu.close();
		}
		catch(IOException e)
		{
			System.err.println("NIEUDANE ZAMKNIECIE STRUMIENIA DANYCH" + e);
			System.exit(-1);
		}
	}
}
