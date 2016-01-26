/*****************************************
 Cola Dinamica usando STL
 ******************************************/

#include <stdio.h>
#include <queue>

using namespace std;

int main(){
    //queue< tipo > nombre
    queue< int > Q;   //Creamos una cola vacía

    // insertamos tres elementos
    Q.push( 1 ); Q.push( 2 ); Q.push( 3 );

    // El elemento insertado primero debe salir primero (FIFO): 1, 2, 3
    while( !Q.empty() ) {
        printf("%d " , Q.front() );
        Q.pop();
    }
    printf("\n");

    return 0;
}
