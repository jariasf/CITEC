/*************************************************
***Técnica: Incrementos en coordenadas
***Descripción: Revisar adyacentes en un tablero
*************************************************/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class RevisionAdyacentes {
    

    static final int MAX = 105;
    static int tabla[][] = new int[ MAX ][ MAX ];          //tablero a recorrer
    //Movimientos cardinales
    static int dx[] = { 0 ,  0 , 1 , -1 };  //incremento en coordenada x
    static int dy[] = { 1 , -1 , 0 ,  0 };  //incremento en coordenada y
    /*
    //Movimientos cardinales + diagonales
    static int dx[] = { 1 , -1 , 0 ,  0 , 1 , 1 , -1 , -1 }; //incremento en coordenada x
    static int dy[] = { 0 ,  0 , 1 , -1 , 1 , -1 , 1 , -1 }; //incremento en coordenada y

    //Movimientos de caballo en un tablero de ajedrez
    static int dx[]={ -2 , -2 , -1 , -1 ,  1 , 1 ,  2 , 2 }; //incremento en coordenada x
    static int dy[]={ -1 ,  1 , -2 ,  2 , -2 , 2 , -1 , 1 }; //incremento en coordenada y
    */
    static int filas,  columnas;             //número de filas y columnas

    //Verificamos si estamos en una posicion valida o no
    static boolean valid( int nx , int ny ){
        //Posiblemente algun adyacente se sale del tablero por ello comprobamos
        //que este dentro del tablero
        return ( nx >= 0 && ny >= 0 && nx < filas && ny < columnas );

        //Comprobación de coordenadas y verificacion en tablero
        //return ( nx >= 0 && ny >= 0 && nx < filas && ny < columnas  && tabla[ nx ][ ny ] == );
    }
    //Revisar adyacentes para cada posicion de un tablero
    static void check(){
        int nx , ny;    //incrementos en x e y
        for( int x = 0 ; x < filas ; ++x ){
            for( int y = 0 ; y < columnas ; ++y ){
                System.out.printf("\nCoordenada (%d,%d) tiene las siguientes coordenadas adyacentes:\n" , x , y );
                //En cada posición del tablero evaluo los adyacentes de dicha posición
                for( int i = 0 ; i < 4 ; ++i ){
                    nx = dx[ i ] + x;   //Incremento en x
                    ny = dy[ i ] + y;   //Incremento en y
                    if( valid( nx , ny ) ){ //Si estamos en una posicion valida
                        System.out.printf("(%d,%d) " , nx , ny );
                    }
                }
                System.out.printf("\n");
            }
        }
    }

    public static void main(String args[]) throws IOException{
        BufferedReader reader = new BufferedReader( new InputStreamReader( System.in ) );
        StringTokenizer tokens = new StringTokenizer( reader.readLine() );
        filas = Integer.parseInt( tokens.nextToken() );
        columnas = Integer.parseInt( tokens.nextToken() );
        /*for( int i = 0 ; i < filas ; ++i ){
            tokens = new StringTokenizer( reader.readLine() );
            for( int j = 0 ; j < columnas ; ++j ){
                tabla[ i ][ j ] = Integer.parseInt(tokens.nextToken());
            }
        }*/
        check();
    }

}
