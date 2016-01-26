import java.util.LinkedList;
import java.util.Queue;


public class queue {

	/*
	Q.add( x );  //Inserta x en la cola
	Q.element(); //Retorna el primer elemento de la cola pero no lo elimina
	Q.remove();  //Elimina el primer elemento de la cola y lo retorna
	Q.isEmpty(); //Retorna true si la cola no esta vacia, de otro modo retorna false
	Q.size();    //Retorna el numero de elementos de la cola
	*/
	public static void main(String[] args) {
	    //Queue< Clase > nombre = new LinkedList< Clase >();
	    Queue< Integer > Q = new LinkedList<Integer>();
	   
	    // insertamos tres elementos
	    Q.add( 1 ); Q.add( 2 ); Q.add( 3 );

	    // El elemento insertado primero debe salir primero (FIFO): 1, 2, 3
	    while( !Q.isEmpty() ) {
	        System.out.printf("%d " , Q.remove() );
	    }
	    System.out.printf("\n");
	}

}
