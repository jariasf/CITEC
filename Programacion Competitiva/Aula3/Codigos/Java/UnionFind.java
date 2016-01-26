/***************************************************
 ***Estructura de Datos: Union-Find ( Disjoint-Sets)
 ***Implementaci�n: Disjoint-Sets Forests
 ***Autor: Jhosimar George Arias Figueroa
 ***************************************************/

/*
INPUT
9 7
2 0
7 0
3 1
1 0
6 4
8 5
4 5
*/
import java.util.*;

public class UnionFind {

	static final int MAX = 10005;  //maximo numero de v�rtices
	static int padre[] = new int[ MAX ];   //Este arreglo contiene el padre del i-esimo nodo
	static int rango[] = new int[ MAX ];   //profundidad de cada v�rtice

	//M�todo de inicializaci�n
	static void MakeSet( int n ){
	    for( int i = 0 ; i < n ; ++i ){
	        padre[ i ] = i;      //Inicialmente el padre de cada v�rtice es el mismo v�rtice
	        rango[ i ] = 0;      //Altura o rango de cada v�rtice es 0
	    }
	}

	//M�todo para encontrar la raiz del v�rtice actual X
	static int Find( int x ){
	    if( x == padre[ x ] ){          //Si estoy en la raiz
	        return x;                   //Retorno la raiz
	    }
	    //else return Find( padre[ x ] ); //De otro modo busco el padre del v�rtice actual, hasta llegar a la raiz.
	    else return padre[ x ] = Find( padre[ x ] ); //Compresion de caminos
	}

	//M�todo para unir 2 componentes conexas
	static void Union( int x , int y ){
	    int xRoot = Find( x );    //Obtengo la raiz de la componente del v�rtice X
	    int yRoot = Find( y );    //Obtengo la raiz de la componente del v�rtice Y
	    padre[ xRoot ] = yRoot;   //Mezclo ambos arboles o conjuntos, actualizando su padre de alguno de ellos como la raiz de otro
	}

	//M�todo para unir 2 componentes conexas usando sus alturas (rangos)
	static void UnionbyRank( int x , int y ){
	    int xRoot = Find( x );    //Obtengo la raiz de la componente del v�rtice X
	    int yRoot = Find( y );    //Obtengo la raiz de la componente del v�rtice Y
	    if( rango[ xRoot ] > rango[ yRoot ] ){ //en este caso la altura de la componente del v�rtice X es
	                                           //mayor que la altura de la componente del v�rtice Y.
	        padre[ yRoot ] = xRoot;            //el padre de ambas componentes ser� el de mayor altura
	    }
	    else{                    //en este caso la altura de la componente del v�rtice Y es mayor o igual que la de X
	        padre[ xRoot ] = yRoot;            //el padre de ambas componentes ser� el de mayor altura
	        if( rango[ xRoot ] == rango[ yRoot ] ){ //si poseen la misma altura
	            rango[ yRoot ]++;              //incremento el rango de la nueva ra�z
	        }
	    }
	}

	static int root[] = new int[ MAX ]; //tendra las raices de las componentes conexas luego de aplicar el m�todo
	static int numComponentes; //variable para el numero total de componentes conexas
	//M�todo para obtener el numero de componentes conexas luego de realizar las conexiones respectivas
	static int getNumberConnectedComponents( int n ){
	    numComponentes = 0;
	    for( int i = 0 ; i < n ; ++i ){
	        if( padre[ i ] == i ){    //Si el padre del v�rtice i es el mismo v�rtice entonces es ra�z
	        //if( Find( i ) == i ){   //podemos usamos find para el mismo proposito y
	                                  //para que se realice compresion de caminos
	            root[ numComponentes++ ] = i;  //almaceno la raiz de cada nueva componente
	           // numComponentes++;
	        }
	    }
	    return numComponentes;
	}

	static int numVertices[] = new int[ MAX ];   //almacenara la cantidad de v�rtices para la i-esima raiz.
	//M�todo para obtener la raiz y el numero de v�rtices de cada componente conexa
	//ser� necesario primero tener la cantidad de componentes conexas
	//podemos llamar 1ero al metodo getNumberConnectedComponents o incluir porcion de su codigo en este
	static void getNumberNodes( int n ){
	    Arrays.fill( numVertices, 0 );     //inicializo mi contador de v�rtices
	    for( int i = 0 ; i < n ; ++i ){
	        numVertices[ Find( i ) ]++;    //incremento la ra�z del v�rtice i
	    }
	    for( int i = 0 ; i < numComponentes ; ++i ){
	        System.out.printf("Componente %d: Raiz = %d , Nro nodos = %d.\n" , i + 1 , root[ i ] , numVertices[ root[ i ] ] );
	    }
	}

	//M�todo que me determina si 2 v�rtices estan o no en la misma componente conexa
	static boolean sameComponent( int x , int y ){
	    if( Find( x ) == Find( y ) ) return true;   //si poseen la misma ra�z
	    return false;
	}

	public static void main(String[] args) {
	    int V , E , origen , destino;

	    Scanner sc = new Scanner( System.in );  
	    V = sc.nextInt(); E = sc.nextInt();    //tengamos numero de vertices y aristas
	    MakeSet( V );                          //inicializamos los conjuntos
	    for( int i = 0 ; i < E ; ++i ){
	        origen = sc.nextInt(); destino = sc.nextInt();
	        UnionbyRank( origen , destino );  //union de elementos
	    }

	    System.out.printf("El numero de componentes conexas es: %d\n" , getNumberConnectedComponents( V ) );
	    getNumberNodes( V );

	}

}
