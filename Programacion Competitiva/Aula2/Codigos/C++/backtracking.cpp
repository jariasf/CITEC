/*************************************************
***Técnica: Backtracking
***Descripción: Subconjuntos de tamanho n
*************************************************/

#include <cstdio>

using namespace std;
#define MAX 105
int n;
bool pick[MAX];

//Obtener todos los subconjuntos de tamanho n usando backtracking
void generate(int at) {
    if (at == n) {
        for (int i = 0; i < n; ++i) {
            if (pick[i]) {
                printf("%d ", i+1);
            }
        }
        printf("\n");
    } else {
        // Considerar el elemento
        pick[at] = true;
        generate(at + 1);
        // No considerar el elemento
        pick[at] = false;
        generate(at + 1);
    }
}

int main(){
    scanf("%d", &n );
    generate(0);
    return 0;
}
