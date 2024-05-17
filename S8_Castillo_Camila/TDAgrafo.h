#include <stdio.h>
#include <stdlib.h>


/*------------- estructura de datos -------------*/
// TDA grafo de números enteros

typedef struct{
	int cvertices;
	int **adyacencias;
	}grafo;
// TDA GRAFO ponderado


/*----------------- operaciones -----------------*/

// crea_grafo_vacio() retorna un grafo vacío representado como matriz de adyacencia
// orden de complejidad: O(n^2)
grafo* crea_grafo_vacio(int vertices);


// imprime_matriz_grafo() imprime matriz de adyacencia
// orden de complejidad: O(n^2)
void imprime_matriz_grafo(grafo *g);


// lee_grafo_nodirigido(archivo) lee desde un archivo un grafo no dirigido
// el formato del archivo registra las aristas
// orden de complejidad: O(|E|)
grafo* lee_grafo_nodirigido(char *nombre_archivo);


/*------------- Actividad 1 -------------*/

int obtiene_grado(grafo *g, int vertice);


/*------------- Actividad 2 -------------*/
//Usar como base la implementación para grafo no dirigido 

grafo* lee_grafo_dirigido_ponderado(char *nombre_archivo);


/*------------- Actividad 3 -------------*/

int grado_salida(grafo *g, int vertice);

int grado_entrada(grafo *g, int vertice);

/*------------- Actividad 4 -------------*/

grafo* Harary(grafo* g1, grafo* g2);

