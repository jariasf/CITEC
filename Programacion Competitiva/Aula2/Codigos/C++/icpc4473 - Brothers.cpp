/*****************************************
 ***Problema: Brothers
 ***ID: 4473
 ***Juez: ICPC
 ***Tipo: Simulation
 ******************************************/

#include <stdio.h>
#include <cstring>
#define MAX 105
int tabla[ MAX ][ MAX ], aux[ MAX ][ MAX ];
int n , r , c , k;

int dx[ 4 ] = { 0 ,  0 , 1 , -1 };  //incremento en coordenada x
int dy[ 4 ] = { 1 , -1 , 0 ,  0 };  //incremento en coordenada y

//Validamos cada posicion
bool valid( int x , int y , int nx , int ny ){
    return ( nx >= 0 && ny >= 0 && nx < r && ny < c && ( tabla[ x ][ y ] + 1 ) % n == tabla[ nx ][ ny ] );
}

//Simulamos el proceso evaluando cada posicion
void simulate(){
    int nx , ny;
    while( k-- ){
        for( int x = 0 ; x < r ; ++x ){
            for( int y = 0 ; y < c ; ++y ){
                for( int i = 0 ; i < 4 ; ++i ){
                    nx = dx[ i ] + x;
                    ny = dy[ i ] + y;
                    if( valid( x , y , nx , ny ) ){
                        aux[ nx ][ ny ] = tabla[ x ][ y ];
                    }
                }
            }
        }
        memcpy( tabla , aux , sizeof( tabla ) );
    }
}

int main(){
    while( scanf("%d %d %d %d" , &n ,&r , &c , &k ) , n  | r  | c  | k ){
        for( int i = 0 ; i < r ; ++i ){
            for( int j = 0 ; j < c ; ++j ){
                scanf("%d" , &tabla[ i ][ j ] );
                aux[ i ][ j ] = tabla[ i ][ j ];
            }
        }
        simulate();
        for( int i = 0 ; i < r ; ++i ){
            printf("%d" , tabla[ i ][ 0 ] );
            for( int j = 1 ; j < c ; ++j ){
                printf(" %d" , tabla[ i ][ j ] );
            }
            printf("\n" );
        }
    }
    return 0;
}
