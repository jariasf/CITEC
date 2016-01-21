/*************************************************
***Descripción: Diferentes operaciones sobre bits
*************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;

//#define isPowerOfTwo(x) ((x & (x - 1)) == 0)

//Verificar si el numero x es una potencia de dos
bool isPowerOfTwo(int x){
    return ((x & (x - 1)) == 0);
}

//Setear el bit en la posicion j a 1
int setBit(int x , int j){
    return (x | (1 << j));
}

//Cambiar el valor del bit en la posicion j
int toggleBit(int x, int j){
    return (x ^ (1 << j));
}

//Verificar si el bit en la posicion j es igual a 1
bool isOn(int x, int j){
    return (x & (1 << j));
}

//Contar el numero de 1's en la representacion binaria de x en O(log(n))
int countOneslogN(int x){
    int ones = 0;
    while(x){
        ones += (x & 1);
        x >>= 1;
    }
    return ones;
}

//Contar el numero de 1's en la representacion binaria de x O(numero_unos)
int countOnes( int x ){
    int ones = 0;
    while(x){
        x &= (x - 1);
        ones++;
    }
    return ones;
}

//O(2^n)
void allSubsets(int n){
    //Iterar sobre todos los posibles subsets entre 0 y (2^n - 1)
    for( int i = 0 ; i < 1<<n ; ++i){
        //Iterar sobre las posiciones de los bits
        for( int j = 0 ; j < n ; ++j ){
            //Verificar si el bit en la posicion j esta activado
            if( isOn(i , j) ){
                printf("1");
            }else
                printf("0");
        }
        printf("\n");
    }
}

int main(){
    int A = 32, bit = 1, n = 4;

    printf("Set Bit\n");
    printf("Setear 1 en la posicion %d del numero %d = %d\n\n" , bit, A, setBit(A,bit) );

    printf("Toogle Bit\n");
    bit = 5;
    printf("Cambiar valor del bit en la posicion %d para el numero %d = %d\n\n", bit, A, toggleBit(A,bit) );

    printf("Verificar si numero %d es potencia de 2 = %s\n\n" , A, (isPowerOfTwo(A)?"Yes":"No"));

    printf("Contar numero de 1's en representacion binaria del numero %d = %d\n\n", A, countOnes(A) );

    printf("Todos los subconjuntos de longitud %d\n" , n);
    allSubsets(n);

    return 0;
}
