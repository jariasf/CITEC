import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;


public class stack {
	
	/*
	S.push( x ); //Inserta x en la pila
	S.pop();     //Elimina el elemento del tope y lo retorna
	S.peek();    //Retorna el elemento del tope pero no lo elimina
	S.empty();   //Retorna true si la pila no esta vacia, de otro modo retorna false
	S.size();    //Retorna el numero de elementos de la pila
	*/
	
	public static void main(String[] args) {
		
	    //Stack< Clase > nombre = new Stack< Clase >();
	    Stack< Integer > S = new Stack< Integer >();     //Creamos una pila vacía

	    // insertamos tres elementos
	    S.push( 1 ); S.push( 2 ); S.push( 3 );

	    // el ultimo elemento insertado debe salir primero (LIFO): 3, 2, 1
	    while( !S.empty() ) {
	        System.out.printf("%d " , S.pop() );
	    }
	    System.out.printf("\n");
	    
	}

}
