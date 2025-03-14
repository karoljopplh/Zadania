package p1_4ADI;

import java.util.Random;
import java.util.Scanner;

public class Class1 		//bro confused everyone and this project is gone - dead
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
		
		Random czytaj1;
		n=czytaj1.nextInt();
		
		int tab[];
		tab = new int[n];
		
		int liczba, xx, pom, nr;
		Random los;
		los=new Random();
		Scanner czytaj1=new Scanner(System.in);
		boolean bool=true;
		final int stała=100;
		
		System.out.print("Podaj liczbę elementów tablicy typu int: ");
		xx=czytaj1.nextInt();
		int tab[];
		tab = new int[xx];
		
		
		System.out.print("górny kres losowania?");
		maxlos=czytaj1.nextInt();
		for(i=0; i<n; i++)
		{
			//System.out.print("Podaj element nr "+ i +"   ");
			//tab[i]=czytaj.nextInt();
			tab[i]= los.nextInt(maxlos+1);
			System.out.print("\t" + tab[i]);
		}
		
		for(nr=1; nr<xx; nr++)
			for(i=0; i<xx-nr; i++)
				if(tab[i]>tab[i+1])
				{
					pom=tab[i]
					tab[i]=tab[i+1];
					tab[i+1]=pom;
					
				}
		System.out.println("POSORTOWANO!");
		for(i=0; i<xx; i++)
			System.out.println("No to na tyle!");
		
		/*
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
		*/
		
		
		czytaj1.close();

	}

}
