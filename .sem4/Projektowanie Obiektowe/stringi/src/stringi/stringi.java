package stringi;

import java.util.Scanner;

public class stringi {

	public static void main(String[] args) 
	{
		int i;
		String t1, t2, t3;	//String t1="Alusia";
		//bardziej prawidłowo: String t1 = new String();
		String[] tablica = new String[100];
		
		StringBuilder sb=new StringBuilder();
		
		Scanner czytaj=new Scanner(System.in);
		System.out.print("\nPodaj tekst ");
		t1=czytaj.nextLine();
	//	t1="Janek Kowalski";
		t2=t1.toUpperCase();
		System.out.println("\nOryginał="+t1+"\tWielkimi= "+t2);
		t3=t1.substring(1, t1.length()-2);
		System.out.println("\nWycinek="+t3);
		
		for (i=0; i<t3.length(); i++)
			System.out.print(t3.charAt(i)+"\t");

		//sb
		sb.append("tekst początkowy");
		sb.append(t2);
		sb.insert(0, "wstawiony tekst ");
		sb.deleteCharAt(3);
		sb.replace(5, 7, "******");
		t3=sb.toString();
		System.out.println("\ntekst ze sb="+sb+"\n tekst z t3="+t3);
		char znak=sb.charAt(2);
		sb.setCharAt(0, 'X');
		System.out.println("\nznaczek="+znak);
		sb.reverse();
		System.out.print("\n"+sb);
		czytaj.close();
	}

}
