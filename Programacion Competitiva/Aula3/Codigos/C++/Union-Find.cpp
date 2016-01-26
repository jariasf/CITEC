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
#include <stdio.h>
#include <cstring>

#define MAX 10005
int padre[ MAX ];   //Este arreglo contiene el padre del i-esimo nodo
int rango[ MAX ];   //profundidad de cada v�rtice

//M�todo de inicializaci�n
void MakeSet( int n ){
    for( int i = 0 ; i < n ; ++i ){
        padre[ i ] = i;      //Inicialmente el padre de cada v�rtice es el mismo v�rtice
        rango[ i ] = 0;      //Altura o rango de cada v�rtice es 0
    }
}

//M�todo para encontrar la raiz del v�rtice actual X
int Find( int x ){
    if( x == padre[ x ] ){          //Si estoy en la raiz
        return x;                   //Retorno la raiz
    }
    //else return Find( padre[ x ] ); //De otro modo busco el padre del v�rtice actual, hasta llegar a la raiz.
    else return padre[ x ] = Find( padre[ x ] ); //Compresion de caminos
}

//M�todo para unir 2 componentes conexas
void Union( int x , int y ){
    int xRoot = Find( x );    //Obtengo la raiz de la componente del v�rtice X
    int yRoot = Find( y );    //Obtengo la raiz de la componente del v�rtice Y
    padre[ xRoot ] = yRoot;   //Mezclo ambos arboles o conjuntos, actualizando su padre de alguno de ellos como la raiz de otro
}

//M�todo para unir 2 componentes conexas usando sus alturas (rangos)
void UnionbyRank( int x , int y ){
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

int root[ MAX ]; //tendra las raices de las componentes conexas luego de aplicar el m�todo
int numComponentes; //variable para el numero total de componentes conexas
//M�todo para obtener el numero de componentes conexas luego de realizar las conexiones respectivas
int getNumberConnectedComponents( int n ){
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

int numVertices[ MAX ];   //almacenara la cantidad de v�rtices para la i-esima raiz.
//M�todo para obtener la raiz y el numero de v�rtices de cada componente conexa
//ser� necesario primero tener la cantidad de componentes conexas
//podemos llamar 1ero al metodo getNumberConnectedComponents o incluir porcion de su codigo en este
void getNumberNodes( int n ){
    memset( numVertices , 0 , sizeof( numVertices ) );    //inicializo mi contador de v�rtices
    for( int i = 0 ; i < n ; ++i ){
        numVertices[ Find( i ) ]++;                    //incremento la ra�z del v�rtice i
    }
    for( int i = 0 ; i < numComponentes ; ++i ){
        printf("Componente %d: Raiz = %d , Nro nodos = %d.\n" , i + 1 , root[ i ] , numVertices[ root[ i ] ] );
    }
}

//M�todo que me determina si 2 v�rtices estan o no en la misma componente conexa
bool sameComponent( int x , int y ){
    if( Find( x ) == Find( y ) ) return true;   //si poseen la misma ra�z
    return false;
}

int main(){

    int V , E , origen , destino;

    scanf("%d %d" , &V , &E );  //tengamos numero de vertices y aristas
    MakeSet( V );               //inicializamos los conjuntos
    while( E-- ){
        scanf("%d %d" , &origen , &destino );
        UnionbyRank( origen , destino );  //union de elementos
    }

    printf("El numero de componentes conexas es: %d\n" , getNumberConnectedComponents( V ) );
    getNumberNodes( V );

    return 0;
}
