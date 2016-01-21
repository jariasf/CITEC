/*****************************************
 ***Libreria Algorithm
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n = 8;
    int a[] = { 1 , 5 , 4 , 2 , 1 , 1 , 10 , 10 };
    vector< int > v( a , a + n );
    vector< int > :: iterator it;

    printf("Arreglo original\n");
    for(int i = 0 ; i < n ; ++i) printf("%d ", a[i]);
    printf("\n\n");
    //Obtenemos el maximo y minimo elemento de un arreglo estatico o dinamico     O( n )
    printf( "Maximo: %d , Minimo: %d\n" , *max_element( a , a + n ) , *min_element( a , a + n ) );
    printf( "Maximo: %d , Minimo: %d\n" , *max_element( v.begin() , v.end() ) , *min_element( v.begin() , v.end() ) ); //Usando arreglo dinamico

    //Contamos el numero de veces que aparece un elemento en el arreglo           O( n )
    printf( "1 aparece %d veces.\n" , count( a , a + n , 1 ) );             //Usando arreglo estatico
    printf( "10 aparece %d veces.\n" , count( v.begin() , v.end() , 10 ) );   //Usando arreglo dinamico

    //Invertimos el orden de un arreglo                                           O( n )
    reverse( a , a + n );           //Usando arreglo estatico
    reverse( v.begin() , v.end() ); //Usando arreglo dinamico
    printf("\nArreglo Invertido\n");
    for( int i = 0 ; i < n ; ++i ) printf("%d " , a[ i ] );
    printf("\n");
    for( it = v.begin() ; it != v.end() ; ++it ) printf("%d " , *it );
    printf("\n");

    //Rotamos el arreglo 4 posiciones hacia adelante
    rotate( a , a + 4 , a + n );                   //Usando arreglo estatico
    rotate( v.begin() , v.begin() + 4 , v.end() ); //Usando arreglo dinamico
    printf("\nArreglo Rotado 4 posiciones\n");
    for( int i = 0 ; i < n ; ++i ) printf("%d " , a[ i ] );
    printf("\n");
    for( it = v.begin() ; it != v.end() ; ++it ) printf("%d " , *it );
    printf("\n");

    //Removemos elementos duplicados consecutivos en el arreglo
    //unique devuelve un puntero a la ultima nueva posicion
    it = unique( v.begin() , v.end() );            //Usando arreglo dinamico
                                                   //2 4 5 1 10 1 1 1
                                                   //           ^
    printf("\nArreglo sin duplicados consecutivos\n");
    v.resize( it - v.begin() );                    //Eliminamos elementos no necesarios
    for( it = v.begin() ; it != v.end() ; ++it ) printf("%d " , *it );
    printf("\n");

    printf("\nArreglo ordenado\n");
    sort( v.begin() , v.end() );                   //Ordenamos arreglo
    for( it = v.begin() ; it != v.end() ; ++it ) printf("%d " , *it );

    printf("\n\nBusqueda Binaria\n");
    if( binary_search( v.begin() , v.end() , 2 ) ) printf("Existe el elemento 2 en el arreglo\n");
    if( !binary_search( v.begin() , v.end() , 3 ) ) printf("No existe el elemento 3 en el arreglo\n");

    return 0;
}
