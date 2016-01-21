/*********************************************
 Hallar todas las permutaciones de un arreglo
 *********************************************/

#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
    int n;
    scanf("%d" , &n );
    int a[ n + 5 ];
    for( int i = 0 ; i < n ; ++i ){
        scanf("%d" , &a[ i ] );
    }

    printf("\nNext_Permutation\n");
    //Ordenamos el arreglo en orden ascendente para hallar todas las posibles
    //permutaciones usando next_permutation
    sort( a , a + n );
    do{
        //Realizamos cualquier tipo de operacion en la
        //permutación actual
        for( int i = 0 ; i < n ; ++i ){
            printf("%d " , a[ i ] );
        }
        printf("\n");

    }while( next_permutation( a , a + n ) );

    printf("\nPrev_Permutation\n");
    //Revertimos orden de arreglo ordenado para hallar todas las posibles
    //permutaciones usando prev_permutation
    reverse( a , a + n );
    do{
        //Realizamos cualquier tipo de operacion en la
        //permutación actual
        for( int i = 0 ; i < n ; ++i ){
            printf("%d " , a[ i ] );
        }
        printf("\n");
    }while( prev_permutation( a , a + n ) );

    return 0;
}
