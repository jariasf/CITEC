/**************************************************
 Arbol de busqueda binaria - Map y Set
 **************************************************/

#include <cstdio>
#include <map>
#include <set>
#include <string>
using namespace std;

int main() {
    char name[20];
    int value;

    set<int> used_values;
    map<string, int> mapper;

    // Supongamos que insertamos los siguientes pares nombre,score
    /*
    john 78
    billy 69
    andy 80
    steven 77
    felix 82
    grace 75
    martin 81
    */

    //Ingreso estatico
    mapper["john"] = 78;   used_values.insert(78);
    mapper["billy"] = 69;  used_values.insert(69);
    mapper["andy"] = 80;   used_values.insert(80);
    mapper["steven"] = 77; used_values.insert(77);
    mapper["felix"] = 82;  used_values.insert(82);
    mapper["grace"] = 75;  used_values.insert(75);
    mapper["martin"] = 81; used_values.insert(81);

    /*
    //Ingreso dinamico
    for (int i = 0; i < 7; i++) {
        scanf("%s %d", name, &value);
        mapper[name] = value;                      // ejemplo asignacion en map
        used_values.insert(value);                 // ejemplo asignacion en set
    }
    */
    // El contenido interno de mapper puede ser algo como esto:
    // las claves son los nombres (string)!
    //                        (grace,75)
    //           (billy,69)               (martin,81)
    //     (andy,80)   (felix,82)    (john,78)  (steven,77)


    //iterar sobre el contenido del mapper dara una salida ordenada
    //basado en claves(nombres)
    for(map<string, int>::iterator it = mapper.begin(); it != mapper.end(); ++it)
        printf("%s %d\n", ((string)it->first).c_str(), it->second);

    //Map tambien puede ser usado de esta forma
    printf("Score de steven es %d, score de grace es %d\n", mapper["steven"], mapper["grace"]);
    printf("==================\n");

    // el contenido interno del set puede ser algo como esto
    // las claves son valores (enteros)!
    //                 (78)
    //         (75)            (81)
    //     (69)    (77)    (80)    (82)

    // busqueda O(log n), encontrado
    printf("%d\n", *used_values.find(77));

    // busqueda O(log n), no encontrado
    if (used_values.find(79) == used_values.end())
        printf("79 no encontrado\n");

    return 0;
}
