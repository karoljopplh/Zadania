package p1_4ADI;

import java.util.Random;
import java.util.Scanner;

public class Class1 
{

	public Class1() 
	{
		// TODO Auto-generated constructor stub
	}

	public static void main(String[] args) 
	{
		double wynikd, d;
		d=5.75;
		int wynik, i=(int) d, n, maxlos, a, b;
		
		n=czytaj.nextInt();
		
		int tab[];
		tab = new int[n];
		
		int liczba;
		Random los;
		los=new Random();
		Scanner czytaj=new Scanner(System.in);
		boolean bool=true;
		final int stała=100;
		
		
		System.out.print("górny kres losowania?");
		maxlos=czytaj.nextInt();
		for(i=0; i<n; i++)
		{
			//System.out.print("Podaj element nr "+ i +"   ");
			//tab[i]=czytaj.nextInt();
			tab[i]= los.nextInt(maxlos+1);
		}
		
		
		System.out.println("Napis testowy");
		System.out.println("\n\tWartość zmiennej i=" + i);
		System.out.println("sklejone wartości d oraz i =" + d + i);
		System.out.println("suma d + i +" + (d+i));
		wynik= (int) d+i;
		System.out.println("zmienna wynik=" + wynik);
		wynikd=d+i;
		System.out.println("zmienna wynikd=" + wynikd);
		liczba=los.nextInt();
		System.out.println("losowana=" + liczba);
		liczba=los.nextInt(2);
		System.out.println("losowana mała=" + liczba);
		d=los.nextDouble();
		d=d*10000;
		System.out.println("losowana double=" + d);
		System.out.println("Wprowadz liczbę całkowitą       ");
		i=czytaj.nextInt();
		System.out.println("Wprowadziłeś    " + i);
		czytaj.close();

	}

}
