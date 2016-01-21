/*****************************************
 ***Problema: Flowers Flourish from France
 ***ID: 4810
 ***Juez: ICPC
 ***Tipo: Ad hoc
 ******************************************/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

//Renombrar clase a Main antes de subirlo al juez
public class icpc4810 {

	public static boolean correct( String line ){
		StringTokenizer tokens = new StringTokenizer( line , " " );
		char ini = Character.toLowerCase( tokens.nextToken().charAt( 0 ) );
		while( tokens.hasMoreTokens() ){
			if( Character.toLowerCase( tokens.nextToken().charAt( 0 ) ) != ini ) return false;
		}
		return true;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader reader = new BufferedReader( new InputStreamReader( System.in ) );
		String line;
		while( true ){
			line = reader.readLine();
			if( line.charAt( 0 ) == '*' ) break;
			if( correct( line ) ) System.out.println( "Y" );
			else System.out.println( "N" );
		}
	}
}
