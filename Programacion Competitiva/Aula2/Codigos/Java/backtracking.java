/*************************************************
***Técnica: Backtracking
***Descripción: Subconjuntos de tamanho n
*************************************************/

import java.util.Scanner;

public class backtracking {
    static final int MAX = 105;
    static int n;
    static boolean pick[] = new boolean[MAX];

    //Obtener todos los subconjuntos de tamanho n usando backtracking
    static void generate(int at) {
        if (at == n) {
            for (int i = 0; i < n; ++i) {
                if (pick[i]) {
                    System.out.printf("%d ", i+1);
                }
            }
            System.out.printf("\n");
        } else {
            // Considerar el elemento
            pick[at] = true;
            generate(at + 1);
            // No considerar el elemento
            pick[at] = false;
            generate(at + 1);
        }
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        generate(0);
    }

}
