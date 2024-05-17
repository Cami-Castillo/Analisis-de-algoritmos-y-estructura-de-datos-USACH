
/*------------- estructura de datos -------------*/
// TDA conjunto de números enteros

typedef struct{
  int cardinalidad;
  int max_elementos;
  int *elementos;
}conjunto;


/*------------- operaciones -------------*/


// crea_conjunto(max_elementos) retorna un nuevo conjunto vacío para un máximo de elementos 
// orden de complejidad: O(1)
conjunto* crea_conjunto(int max_elementos);


// destruye_conjunto(max_elementos) libera la memoria asignada al conjunto c
// orden de complejidad: O(1)
void destruye_conjunto(conjunto *c);


// pertenece(c, e) determina si el elemento e pertenece al conjunto c
// orden de complejidad: O(n)
int pertenece(conjunto *c, int e);


// imprime_conjunto(c) imprime por consola los elementos del conjunto c
// orden de complejidad: O(n)
void imprime_conjunto(conjunto *c);


// agregar_elemento(c, e) si el elemento e no pertenece al conjunto c lo agrega 
// orden de complejidad: O(n)
void agregar_elemento(conjunto *c, int e);


// eliminar_elemento(c, e) elimina el elemento e desde el conjunto c 
// orden de complejidad: O(n)
void eliminar_elemento(conjunto *c, int e);
