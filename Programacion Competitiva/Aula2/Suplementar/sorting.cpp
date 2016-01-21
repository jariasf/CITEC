/*****************************************
 Ordenamiento Usando Librerias
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1000
int a[ MAX ] , n;


//Funcion comparador para ordenamiento
//Recibe 2 elementos del tipo de dato que se esta ordenando
bool comparador( int a , int b ){
    return a > b;   //Ordenamos de mayor a menor
}

void sortArray(){
    for( int i = 0 ; i < n ; ++i ){
        scanf("%d" , &a[ i ] );
    }
    //Ordenamos un arreglo estatico de acuerdo al comparador
    sort( a , a + n , comparador );
    for( int i = 0 ; i < n ; ++i ) printf("%d " , a[ i ] );
    printf("\n");
}

void sortVector(){
    vector< int > v;
    vector< int > :: iterator it;
    int x;
    for( int i = 0 ; i < n ; ++i ){
        scanf("%d" , &x );
        v.push_back( x );
    }
    //Ordenamos un vector dinamico de acuerdo al comparador
    sort( v.begin() , v.end() , comparador );
    for( it = v.begin() ; it != v.end() ; ++it  ) printf("%d " , *it );
    printf("\n");
}

int main(){
    scanf("%d" , &n );
    sortArray();
    sortVector();
    return 0;
}
