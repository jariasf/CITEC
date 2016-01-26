/*****************************************
 Pila Dinamica usando STL
 ******************************************/

#include <stdio.h>
#include <stack>

using namespace std;

int main(){
    //stack< tipo > nombre
    stack< int > S;     //Creamos una pila vacía

    // insertamos tres elementos
    S.push( 1 ); S.push( 2 ); S.push( 3 );

    // el ultimo elemento insertado debe salir primero (LIFO): 3, 2, 1
    while( !S.empty() ) {
        printf("%d " , S.top() );
        S.pop();
    }
    printf("\n");

    return 0;
}
