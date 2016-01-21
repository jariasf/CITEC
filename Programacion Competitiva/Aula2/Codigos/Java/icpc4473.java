/*****************************************
 ***Problema: Brothers
 ***ID: 4473
 ***Juez: ICPC
 ***Tipo: Simulation
 ******************************************/

import java.util.Scanner;

//Renombrar clase a Main antes de subirlo al juez
public class icpc4473 {
    static final int MAX = 105;
    static int tabla[][] = new int[ MAX ][ MAX ];
    static int aux[][] = new int[ MAX ][ MAX ];

    static int n , r , c , k;

    static int dx[] = { 0 ,  0 , 1 , -1 };  //incremento en coordenada x
    static int dy[] = { 1 , -1 , 0 ,  0 };  //incremento en coordenada y

    //Validamos cada posicion
    static boolean valid( int x , int y , int nx , int ny ){
        return ( nx >= 0 && ny >= 0 && nx < r && ny < c && ( tabla[ x ][ y ] + 1 ) % n == tabla[ nx ][ ny ] );
    }

    //Simulamos el proceso evaluando cada posicion
    static void simulate(){
        int nx , ny;
        while( k-- > 0 ){
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
         
            for( int i = 0 ; i < r ; ++i )
                for( int j = 0 ; j < c ; ++j )
                    tabla[i][j] = aux[i][j];
        }
    }
    
    public static void main(String[] args){
        
        Scanner sc = new Scanner( System.in );
        while( true ){
            n = sc.nextInt();
            r = sc.nextInt();
            c = sc.nextInt();
            k = sc.nextInt();
            if( ( n | r | c | k ) == 0 ) break;

            for( int i = 0 ; i < r ; ++i ){
                for( int j = 0 ; j < c ; ++j ){
                    tabla[i][j] = sc.nextInt();
                    aux[ i ][ j ] = tabla[ i ][ j ];
                }
            }
            
            simulate();
            
            for( int i = 0 ; i < r ; ++i ){
                System.out.printf("%d" , tabla[ i ][ 0 ] );
                for( int j = 1 ; j < c ; ++j ){
                    System.out.printf(" %d" , tabla[ i ][ j ] );
                }
                System.out.printf("\n" );
            }
        }
    }
}

