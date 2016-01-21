/*****************************************
 ***Problema: Flowers Flourish from France
 ***ID: 4810
 ***Juez: ICPC
 ***Tipo: Ad hoc
 ******************************************/

//Usando Librerias de C++
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string line;

bool isUpper( char c ){
    return c >= 'A' && c <= 'Z';
}
char toLowerCase( char c ){
    return ( isUpper( c ) )? ( c - 'A' + 'a' ) :c ;
}

bool correct(){
    char ini;
    stringstream ss( line );
    ss>>line;
    ini = toLowerCase( line[ 0 ] );
    while( ss>>line ){
        if( toLowerCase( line[ 0 ] ) != ini ) return false;
    }
    return true;
}

int main(){
    while( getline( cin , line ) , line[ 0 ] != '*' ){
        if( correct() ) cout<<"Y"<<endl;
        else cout<<"N"<<endl;
    }
    return 0;
}
/*
//Usando C
#include <stdio.h>
#include <cstring>
#define MAX 1005
char line[ MAX ];

bool isUpper( char c ){
    return c >= 'A' && c <= 'Z';
}
char toLowerCase( char c ){
    return ( isUpper( c ) )? ( c - 'A' + 'a' ) :c ;
}

bool correct(){
    char ini;
    char *p = strtok( line , " " );
    ini = '*';
    while( p != NULL ){
        if( ini == '*' ) ini = toLowerCase( p[ 0 ] );
        else if( toLowerCase( p[ 0 ] ) != ini ) return false;
        p = strtok( NULL , " " );
    }
    return true;
}

int main(){
    while( gets( line ) , line[ 0 ] != '*' ){
        if( correct() ) puts("Y");
        else puts("N");
    }
    return 0;
}
