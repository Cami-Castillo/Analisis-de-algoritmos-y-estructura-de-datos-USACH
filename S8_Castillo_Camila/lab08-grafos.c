#include <stdio.h>
#include <stdlib.h>
#include "TDAgrafo_implementacion.c"

int main(int argc, char *argv[]) {

	//PARA LA UNION DE HARARY SE NECESITA 2 ARCHIVOS grafoNoDirigido.in y grafoNoDirigido2.in
	grafo *G, *G2, *G3;
	
	//grafo *P;
	G = lee_grafo_nodirigido(argv[1]);
	G2 = lee_grafo_nodirigido(argv[2]);
	//P = lee_grafo_dirigido_ponderado (argv[2]);
	
	int grado;
	if (G != NULL){
		printf("\n");
		printf("Matriz de adyacencia N1: \n\n");
		imprime_matriz_grafo(G);
		printf("\n============\n");
		}
	if (G2 != NULL){
		printf("Matriz de adyacencia N2: \n\n");
		imprime_matriz_grafo(G2);
		printf("\n============\n");
		}
	//grado = obtiene_grado(G, 0);		
	/*
	printf("Grado de vértice 0:  \n");
		if (P != NULL){
		printf("Matriz de adyacencia: \n\n");
		imprime_matriz_grafo(P);
		printf("\n============\n");
		}
	*/


	
	G3= Harary(G,G2);
	if (G3 != NULL){
		printf("Union de Harary : \n\n");
		imprime_matriz_grafo(G3);
		printf("\n============\n");
		}
	return 0;
	}




