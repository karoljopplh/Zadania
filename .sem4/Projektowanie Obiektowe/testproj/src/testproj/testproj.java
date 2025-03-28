package testproj;

public class testproj {

	public static void main(String[] args) 
	{
		towar t1, t2;
		t1=new towar("Dysk", 199, 10);
		t2=new towar();
		System.out.println("Wartość towaru t1=" + t1.wartosc());
		
		auto a1;
		a1=new auto("Ford", 44000, 5, 1600, 95);
		System.out.println("Wartość auta" + a1.dajNazwe() + " = " + a1.wartosc());
		a1.czysc();
		System.out.println("Po wyczyszczeniu: Wartość auta " + a1.dajNazwe() + " = " + a1.wartosc());
		
		magazyn m1;
		m1 = new magazyn(10);
		m1.dopisz("Dysk", 250.5, 15);
		m1.dopisz("Kabel USB", 7.59, 200);
		m1.dopisz("Monitor", 390, 5);
		for(int i=0; i<m1.dajLicznosc(); i++)
		{
			System.out.println("Towar nr "+i+": " + m1.dajNazwe(i)+" "+m1.dajCene(i)+" "+m1.dajSztuki(i));
		}
		
		m1.zapiszDoPliku();
		m1.czyscTowary();
		System.out.println("Wydruk po wyczyszczeniu TABLICY");
		for(int i=0; i<m1.dajLicznosc(); i++)
		{
			System.out.println("Towar nr "+i+": " + m1.dajNazwe(i) + " " + m1.dajCene(i) + " " + m1.dajSztuki(i));
		}
		m1.czytajZPliku();
		System.out.println("Wydruk po odczycie TABLICY z pliku");
		for(int i=0; i<m1.dajLicznosc(); i++)
		{
			System.out.println("Towar nr "+i+": " + m1.dajNazwe(i) + " " + m1.dajCene(i) + " " + m1.dajSztuki(i));
		}
	}

}
