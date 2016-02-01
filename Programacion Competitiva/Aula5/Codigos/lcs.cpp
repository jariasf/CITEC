/**************************************************
 Longest Common Subsequence - LCS
 **************************************************/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//O(2^n)
int recursive_lcs(string S, string T, int n, int m){
    if( n == 0 || m == 0 )
        return 0;

    int lcs = 0;
    if( S[n-1] == T[m-1]){
        lcs = 1 + recursive_lcs( S, T, n-1, m-1 );
    }else{
        lcs = max( recursive_lcs( S, T, n-1, m ),
                   recursive_lcs( S, T, n, m-1 ) );
    }
    return lcs;
}
///////////////////////////////////////////////////////
#define MAX 1005
int memo[MAX][MAX];
//O(n*m)
int topdown_lcs(string S, string T, int n, int m){
    if( n == 0 || m == 0 )
        return 0;

    //Subproblema resuelto con anterioridad
    if( memo[n][m] != -1 )
        return memo[n][m];

    int lcs = 0;
    if( S[n-1] == T[m-1]){
        lcs = 1 + recursive_lcs( S, T, n-1, m-1 );
    }else{
        lcs = max( topdown_lcs( S, T, n-1, m ),
                   topdown_lcs( S, T, n, m-1 ) );
    }
    return memo[n][m] = lcs;
}
////////////////////////////////////////////////////

int lcs[MAX][MAX];
//O(n*m)
int bottom_up_lcs(string S, string T, int n, int m){
    //Inicializacion
    for( int i = 0 ; i <= n ; ++i ) lcs[0][i] = 0;
    for( int i = 0 ; i <= m ; ++i ) lcs[i][0] = 0;

    for( int i = 1; i <= n ; ++i ){
        for( int j = 1 ; j <= m ; ++j ){
            if( S[i - 1] == T[j - 1] ){ //Caso 1
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
            }else{ //Caso 2
                lcs[i][j] = max( lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }
    return lcs[n][m];
}


////////////// LCS con Impresion /////////////////
#define MATCH 0
#define INSERT 1
#define DELETE 2
int prev[ MAX ][ MAX ];
//O(n*m)
int LCS(string S, string T, int n, int m){
    //Inicializacion
    for( int i = 0 ; i <= n ; ++i ) lcs[0][i] = 0;
    for( int i = 0 ; i <= m ; ++i ) lcs[i][0] = 0;
    prev[0][0] = -1;
    for( int i = 1; i <= n ; ++i ){
        for( int j = 1 ; j <= m ; ++j ){
            if( S[i - 1] == T[j - 1] ){ //Caso 1
                lcs[i][j] = 1 + lcs[i - 1][j - 1];
                prev[i][j] = MATCH;
            }else{ //Caso 2
                if( lcs[i - 1][j] > lcs[i][j - 1]){
                    lcs[i][j] = lcs[i - 1][j];
                    prev[i][j] = DELETE;
                }else{
                    lcs[i][j] = lcs[i][j - 1];
                    prev[i][j] = INSERT;
                }
            }
        }
    }
    return lcs[n][m];
}

void printLCS(int n, int m, string S){
    if( n == 0 || m == 0 || prev[n][m] == -1 ) return;
    if( prev[n][m] == DELETE ){
        printLCS(n - 1, m, S);
    }else if( prev[n][m] == INSERT ){
        printLCS(n , m - 1, S);
    }else{
        printLCS(n - 1, m - 1, S);
        cout<<S[ n - 1 ];
    }
}

int main(){

    string S = "ACGTCGTGT", T = "CTAGTGGAG";
    int n = S.length(), m = T.length();

    cout<<"LCS recursivo"<<endl;
    cout<<"La longitud de la subsecuencia comun mas larga es: "<<recursive_lcs(S, T, n, m)<<endl;

    cout<<endl<<"LCS Top-Down"<<endl;
    memset( memo, -1, sizeof( memo ) );
    cout<<"La longitud de la subsecuencia comun mas larga es: "<<topdown_lcs(S, T, n, m)<<endl;

    cout<<endl<<"LCS Bottom-Up"<<endl;
    cout<<"La longitud de la subsecuencia comun mas larga es: "<<bottom_up_lcs(S, T, n, m)<<endl;

    cout<<endl<<"Impresion de LCS"<<endl;
    LCS(S, T, n, m );
    printLCS(n, m, S );
    cout<<endl;
    return 0;
}
