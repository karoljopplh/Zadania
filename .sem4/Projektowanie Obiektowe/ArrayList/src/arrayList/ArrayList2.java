package arrayList;

import java.util.ArrayList;

public class ArrayList2
{
    public static void main (String[] args)
    {
        ArrayList lista = new ArrayList<Integer>();
        for(int i =0;i<5;i++)
        {
            lista.add(i*2);
        }
        
        lista.add(111.555);
        lista.add("Bobo");
        lista.add(-3.5e-5);
        
        //int [] tab=new int[5];
        for(int i=0;i<lista.size();i++)
        {
            System.out.print(lista.get(i)+"\t\t");
//            tab[i]=lista.get(i);
//            System.out.println(tab[i]);
        }
        
        System.out.println(lista. toString() );
        lista.add(3, 999);
        System.out.println("Po dodaniu 999 pod indeksem 3" + lista. toString() );
        System.out.println("Liczba elementów: " + lista.size());
        lista.set(3, 888);
        System.out.println("Po ustawieniu 888 pod indeksem 3 " + lista. toString () );
        lista.remove(2);
        System.out.println("Po usunięciu elementu z indeksu 3 " + lista. toString() );
        if( lista.contains(888) )
            System.out.println("Jest 888");
        lista.clear();
        System.out.println("Po usunięciu wszystkich elementów" + lista. toString() );
        System.out.println("Liczba elementów : " + lista.size ());
    }
}
