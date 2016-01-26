/**************************************************
 Arreglo Dinámico - Vector
 **************************************************/

#include <stdio.h>
#include <vector>
using namespace std;

int main(){
    int n = 5;
    int a[ ] = { 3 , 4 , 5 , 7 , 9  };
    // vector < tipo > variable;
    vector< int > v1;          // Crea un vector vacío
    vector< int > v2( n );     // Crea un vector con n elementos inicializados en 0
    vector< int > v3( n , 10 ); // Crea un vector con n copias de t
    vector< int > v4( v3 );    // Crea un vector con una copia de los elementos de otro vector.
    vector< int > v( a , a + sizeof( a )/sizeof( int ) ); // Crea un vector a partir de un arreglo de enteros
    vector< int > :: iterator it;   //Creamos iterador para un vector
    vector< int > :: reverse_iterator rev_it;   //Creamos iterador para un vector

    printf("Tamanio: %d\n" , (int)v.size() );       //Mostramos el tamaño del vector

    //Agregamos algunos elementos
    v.push_back( 1 );
    v.push_back( 2 );
    v.push_back( 3 );
    printf("%d\n", *(v.begin() + 20));
    //Iteramos con for
    printf("Elementos de vector\n");
    for( int i = 0 ; i < v.size() ; ++i ) printf("%d " , v[ i ] );
    printf("\n");

    //Iteramos con iterador
    for( it = v.begin() ; it != v.end() ; ++it )printf("%d " , *it );

    printf("\n\nElementos en reversa\n");
    //Iteramos con iterador en reversa
    for( rev_it = v.rbegin() ; rev_it != v.rend() ; ++rev_it )printf("%d " , *rev_it );

    printf("\n\nEliminamos ultimo elemento de vector\n");
    v.pop_back();   //Eliminamos el ultimo elemento del vector;
    for( it = v.begin() ; it != v.end() ; ++it )printf("%d " , *it );

    printf("\n\nInsertamos elemento 10 en posicion 4\n");
    v.insert( v.begin() + 4 , 10 );  //Insertamos el elemento 10 en la posición 4
    for( it = v.begin() ; it != v.end() ; ++it )printf("%d " , *it );

    printf("\n\nEliminamos elemento en posicion 6\n");
    v.erase( v.begin() + 6 );                 //Eliminamos el elemento de la posición 6
    for( it = v.begin() ; it != v.end() ; ++it )printf("%d " , *it );

    printf("\n\nEliminamos elementos en el rango [ 2 , 4 >\n");
    v.erase( v.begin() + 2 , v.begin() + 5 );
    for( it = v.begin() ; it != v.end() ; ++it )printf("%d " , *it );

    printf("\n\nAumentamos el tamanio del vector insertando el elemento 100\n");
    v.resize( 15 , 100 );
    for( it = v.begin() ; it != v.end() ; ++it )printf("%d " , *it );

    printf("\n\nReducimos el tamanio del vector a 2\n");
    v.resize( 2 );
    for( it = v.begin() ; it != v.end() ; ++it )printf("%d " , *it );

    printf("\n\nLimpiamos vector\n");
    v.clear();
    printf("Tamanio: %d\n" , (int)v.size() );

    return 0;
}
