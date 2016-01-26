import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Vector;


public class DynamicArray {

	public static void main(String[] args) {
		
		/*
		//Lista< Tipo > nombre = new Implementacion< Tipo >(); 
		List< Integer > v = new ArrayList< Integer >();		//Crea una lista vacia
		//List< Integer > v = new LinkedList< Integer >();	//Crea una lista vacia
		//Crea una lista con una copia de los elementos de otra lista o colección
		List< Integer > v2 = new ArrayList< Integer >( v ); 
		//for( int i = 0 ; i < 10 ; ++i ) v.add( i );

		v.add( x );        //Inserta un elemento al final de la lista        O( 1 )
		v.contains( x );   //Retorna true si el elemento existe en la lista  O( n )
		v.clear();         //Elimina todos los elementos de la lista         O( n )
		v.size();          //Retorna el número de elementos de la lista      O( 1 )
		v.remove( i );     //Remueve el elemento en el indice i              O( n )
		
		v.get( i )		   //Accedemos al elemento en indice i		  O( 1 )
		
		//Java       //C++  
		v.get( i ) = v[ i ]*/
		List< Integer > v = new ArrayList< Integer >();		//Crea una lista vacia  
		//Agregamos elementos a la lista
		v.add( 1 );
		v.add( 2 );
		v.add( 3 );
		for( int i = 0 ; i < v.size() ; ++i ){ 
			System.out.println( v.get( i ) );
			//Mostrará 1 2 3
		}
		System.out.println();
		
		List< Integer > v = new ArrayList< Integer >();		//Crea una lista vacia      
		//Agregamos elementos a la lista
		v.add( 1 );
		v.add( 2 );
		v.add( 3 );
		Iterator< Integer > it = v.iterator();		//Creamos un iterador para una lista
		while( it.hasNext() ){
			System.out.print( it.next() + " " );
			//Mostrará 1 2 3
		}
		System.out.println();
		
	}

}
