/**************************************************
 Cola de prioridad
 **************************************************/

#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    int money;
    char name[20];
    priority_queue< pair<int, string> > pq;             // introduciendo 'pair'
    pair<int, string> result;

    // Supongamos que ingresamos los siguientes pares (dinero,nombre):
    /*
    100 john
    10 billy
    20 andy
    100 steven
    70 felix
    2000 grace
    70 martin
    */
    pq.push(make_pair(100, "john"));          // insertando un pair en O(log(n))
    pq.push(make_pair(10, "billy"));
    pq.push(make_pair(20, "andy"));
    pq.push(make_pair(100, "steven"));
    pq.push(make_pair(70, "felix"));
    pq.push(make_pair(2000, "grace"));
    pq.push(make_pair(70, "martin"));

    // cola de prioridad ordenada los elementos basado en un 'heap'
    // el tope de la cola esta basado en la primera clave que es dinero
    // en caso de empates se considera la segunda clave que es el nombre
    // siempre manteniendo la propiedad de max-heap, es decir, el mayor primero

    // El contenido interno de pq heap puede ser algo como esto:
    // la clave primaria es dinero (entero), clave secundaria nombre (string)!
    //                        (2000,grace)
    //           (100,steven)               (70,martin)
    //     (100,john)   (10,billy)     (20,andy)  (70,felix)

    //Top 3 personas con mas dinero
    result = pq.top();                // O(1) para acceder al top / max element
    pq.pop();          // O(log n) para eliminar el tope y rebalancear la estructura
    printf("%s tiene %d $\n", ((string)result.second).c_str(), result.first);
    result = pq.top(); pq.pop();
    printf("%s tiene %d $\n", ((string)result.second).c_str(), result.first);
    result = pq.top(); pq.pop();
    printf("%s tiene %d $\n", ((string)result.second).c_str(), result.first);

    return 0;
}
