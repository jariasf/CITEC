/*************************************************
***Descripción: Diferentes operaciones sobre bits
*************************************************/

public class bitwise {

    // Verificar si el numero x es una potencia de dos
    static boolean isPowerOfTwo(int x) {
        return ((x & (x - 1)) == 0);
    }

    // Setear el bit en la posicion j a 1
    static int setBit(int x, int j) {
        return (x | (1 << j));
    }

    // Cambiar el valor del bit en la posicion j
    static int toggleBit(int x, int j) {
        return (x ^ (1 << j));
    }

    // Verificar si el bit en la posicion j es igual a 1
    static boolean isOn(int x, int j) {
        return (x & (1 << j)) != 0;
    }

    // Contar el numero de 1's en la representacion binaria de x en O(log(n))
    static int countOneslogN(int x) {
        int ones = 0;
        while (x > 0) {
            ones += (x & 1);
            x >>= 1;
        }
        return ones;
    }

    // Contar el numero de 1's en la representacion binaria de x O(numero_unos)
    static int countOnes(int x) {
        int ones = 0;
        while (x > 0) {
            x &= (x - 1);
            ones++;
        }
        return ones;
    }

    // O(2^n)
    static void allSubsets(int n) {
        // Iterar sobre todos los posibles subsets entre 0 y (2^n - 1)
        for (int i = 0; i < 1 << n; ++i) {
            // Iterar sobre las posiciones de los bits
            for (int j = 0; j < n; ++j) {
                // Verificar si el bit en la posicion j esta activado
                if (isOn(i, j)) {
                    System.out.printf("1");
                } else
                    System.out.printf("0");
            }
            System.out.printf("\n");
        }
    }

    public static void main(String args[]) {
        int A = 32, bit = 1, n = 4;

        System.out.printf("Set Bit\n");
        System.out.printf("Setear 1 en la posicion %d del numero %d = %d\n\n", bit, A, setBit(A, bit));

        System.out.printf("Toogle Bit\n");
        bit = 5;
        System.out.printf("Cambiar valor del bit en la posicion %d para el numero %d = %d\n\n", bit, A,
                toggleBit(A, bit));

        System.out.printf("Verificar si numero %d es potencia de 2 = %s\n\n", A, (isPowerOfTwo(A) ? "Yes" : "No"));

        System.out.printf("Contar numero de 1's en representacion binaria del numero %d = %d\n\n", A, countOnes(A));

        System.out.printf("Todos los subconjuntos de longitud %d\n", n);
        allSubsets(n);

    }
}
