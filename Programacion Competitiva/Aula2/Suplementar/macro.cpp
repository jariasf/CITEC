/*****************************************
 ***Macros para concursos
 ******************************************/

#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
typedef long long         			 ll;
typedef long double 	  			 ld;
typedef vector< int >     			 vi;
typedef vector< vi >      			 vvi;
typedef pair< int , int > 			 pii;
typedef set< int > 		  			 si;
typedef pair< string , string >		 pss;
typedef vector< pair< int , int > >  vpii;

#define REP(i, a, b) for (int i = int(a); i <= int(b); ++i )
#define REPN(i, n) REP (i, 1, int(n))
#define REPD(i, a, b) for (int i = int(a); i >= int(b); --i )
#define TR(c, it) for (vpii::iterator it = (c).begin(); it != (c).end(); ++it )
//#define TR(c, it) for (typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it ) // solo en UNIX
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define present ( c , x ) ( ( c ).find( x ) != ( c ).end() )
#define show(x)  cerr<<#x<<" "<<x<<endl;

int main(){
    ll a[ 5 ] = { 1 , 2 , 3 , 4 , 5000000000LL };
    int i;

    //Iteramos desde indice 2 a 3
    REP( i , 2 , 3 ) printf( "%lld " , a[ i ] );
    printf("\n");

    //Iteramos en orden decreciente desde indice 4 a 1
    REPD( i , 4 , 1 ) printf("%lld " , a[ i ] );
    printf("\n");


    vpii v;
    vpii :: iterator it;
    v.pb( mp( 2 , 5 ) ); v.pb( mp( 5 , 8 ) );

    //Iteramos y mostramos cada pair
    TR( v , it ) printf("%d -> %d\n" , (*it).first , (*it).second );

    show( sz( v ) );

    return 0;
}
