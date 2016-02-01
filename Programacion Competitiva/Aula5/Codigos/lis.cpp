/**************************************************
 Longest Increasing Subsequence - LIS
 **************************************************/
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

//O(2^n)
int recursive_lis( vector<int> a, int n, int pos){
    int lis = 1;
    for( int i = pos; i < n ; ++i){
        if(a[i] > a[pos]){
            lis = max( 1 + recursive_lis(a, n, i ), lis );
        }
    }
    return lis;
}

//O(n*2^n)
int solve_recursive_lis(vector<int> a, int n){
    int lis = 0;
    for( int i = 0 ; i < n ; ++i ){
        lis = max(lis, recursive_lis(a, n, i));
    }
    return lis;
}
///////////////////////////////////////////////
#define MAX 1005
int memo[ MAX ];

//O(n)
int topdown_lis( vector<int> a, int n, int pos){

    //Subproblema resuelto con anterioridad
    if( memo[pos] != -1 )
        return memo[pos];

    int lis = 1;
    for( int i = pos; i < n ; ++i){
        if(a[i] > a[pos]){
            lis = max( 1 + topdown_lis(a, n, i ), lis );
        }
    }
    return memo[pos] = lis;
}

//O(n^2)
int solve_topdown_lis(vector<int> a, int n){
    memset( memo, -1, sizeof(memo) );
    int lis = 0;
    for( int i = 0 ; i < n ; ++i ){
        lis = max(lis, topdown_lis(a, n, i));
    }
    return lis;
}

///////////////////////////////////////////////

//dp contiene 1 1 2 2 3 3 4 el proceso del LIS
/*
8
-7 10 9 2 3 8 8 1
*/

int dp[ MAX ];

int bottom_up_lis(vector<int> a, int n){
    for( int i = 0 ; i < n ; ++i ) dp[ i ] = 1;

    for( int i = 0 ; i < n ; ++i ){
        for( int j = i + 1  ; j < n ; ++j ){
            if( a[ i ] < a[ j ] && dp[ j ] < dp[ i ] + 1 ){
                dp[ j ] = dp[ i ] + 1;
            }
        }
    }

    int ans = 0;
    for( int i = 0 ; i < n ; ++i ){
        ans = max( ans , dp[i] );
    }
    return ans;
}

/////////////////// LIS con impresion/////////////////////////
int prev[ MAX];

void printLIS(vector<int> a, int n){
    if( prev[n] == -1 ){
        cout<<a[n];
        return;
    }
    printLIS(a, prev[n]);
    cout<<" "<<a[n];
}

pair<int,int> LIS(vector<int> a, int n){
    for( int i = 0 ; i < n ; ++i ) dp[ i ] = 1, prev[ i ] = -1;

    for( int i = 0 ; i < n ; ++i ){
        for( int j = i + 1  ; j < n ; ++j ){
            if( a[ i ] < a[ j ] && dp[ j ] < dp[ i ] + 1 ){
                dp[ j ] = dp[ i ] + 1;
                prev[ j ] = i;
            }
        }
    }

    int ans = 0, index = 0;
    for( int i = 0 ; i < n ; ++i ){
        cout<<dp[i]<<" ";
        if( dp[i] > ans ){
            ans = dp[i];
            index = i;
        }
    }
    cout<<endl;
    return make_pair(ans,index);
}

/*
12
1 12 7 0 23 11 52 31 61 69 70 2
*/
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for( int i = 0 ; i < n ; ++i ) cin>>a[i];

    cout<<endl<<"LIS Recursivo"<<endl;
    cout<<"La longitud de la subsecuencia creciente mas larga es: "<<solve_recursive_lis(a, n )<<endl;

    cout<<endl<<"LIS Top-Down"<<endl;
    cout<<"La longitud de la subsecuencia creciente mas larga es: "<<solve_topdown_lis(a,n)<<endl;

    cout<<endl<<"LIS Bottom-Up"<<endl;
    cout<<"La longitud de la subsecuencia creciente mas larga es: "<<bottom_up_lis(a, n)<<endl;

    cout<<endl<<"Impresion de LIS"<<endl;
    pair<int,int> p = LIS(a, n);
    printLIS(a, p.second);
    cout<<endl;

    return 0;
}
