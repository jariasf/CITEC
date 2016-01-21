/*************************************************
 ***Técnica: Incrementos en coordenadas
 ***Descripción: Revisar adyacentes en un tablero
 *************************************************/

#include <stdio.h>

#define MAX 105
int tabla[ MAX ][ MAX ];          //tablero a recorrer
//Movimientos cardinales
int dx[ 4 ] = { 0 ,  0 , 1 , -1 };  //incremento en coordenada x
int dy[ 4 ] = { 1 , -1 , 0 ,  0 };  //incremento en coordenada y
/*
//Movimientos cardinales + diagonales
int dx[ 8 ] = { 1 , -1 , 0 ,  0 , 1 , 1 , -1 , -1 }; //incremento en coordenada x
int dy[ 8 ] = { 0 ,  0 , 1 , -1 , 1 , -1 , 1 , -1 }; //incremento en coordenada y

//Movimientos de caballo en un tablero de ajedrez
int dx[ 8 ]={ -2 , -2 , -1 , -1 ,  1 , 1 ,  2 , 2 }; //incremento en coordenada x
int dy[ 8 ]={ -1 ,  1 , -2 ,  2 , -2 , 2 , -1 , 1 }; //incremento en coordenada y
*/
int filas,  columnas;             //número de filas y columnas

//Verificamos si estamos en una posicion valida o no
bool valid( int nx , int ny ){
    //Posiblemente algun adyacente se sale del tablero por ello comprobamos
    //que este dentro del tablero
    return ( nx >= 0 && ny >= 0 && nx < filas && ny < columnas );

    //Comprobación de coordenadas y verificacion en tablero
    //return ( nx >= 0 && ny >= 0 && nx < filas && ny < columnas  && tabla[ nx ][ ny ] == );
}
//Revisar adyacentes para cada posicion de un tablero
void check(){
    int nx , ny;    //incrementos en x e y
    for( int x = 0 ; x < filas ; ++x ){
        for( int y = 0 ; y < columnas ; ++y ){
            printf("\nCoordenada (%d,%d) tiene las siguientes coordenadas adyacentes:\n" , x , y );
            //En cada posición del tablero evaluo los adyacentes de dicha posición
            for( int i = 0 ; i < 4 ; ++i ){
                nx = dx[ i ] + x;   //Incremento en x
                ny = dy[ i ] + y;   //Incremento en y
                if( valid( nx , ny ) ){ //Si estamos en una posicion valida
                    printf("(%d,%d) " , nx , ny );
                }
            }
            printf("\n");
        }
    }
}

int main(){
    scanf("%d %d" , &filas , &columnas );
    /*for( int i = 0 ; i < filas ; ++i ){
        for( int j = 0 ; j < columnas ; ++j ){
            scanf("%d" , &tabla[ i ][ j ] );
        }
    }*/
    check();
    return 0;
}
