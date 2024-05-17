#include <stdio.h>
#include <stdlib.h>
#include "TDAgrafo.h"



/*----------------- implementación operaciones -----------------*/

grafo* crea_grafo_vacio(int vertices){
	grafo *g = (grafo*)malloc(sizeof(grafo));
	g->cvertices = vertices;
	g->adyacencias = (int**)malloc(vertices * sizeof(int*));
	int i, j;
	for (i = 0; i < vertices; i++){
		g->adyacencias[i] = (int*)malloc(vertices * sizeof(int));
		//Inicializa en cero
		for(j = 0; j < vertices; j++){
			g->adyacencias[i][j] = 0;
			}	
		}
	return g;
	}

grafo* crea_grafo_vacio2(int vertices){
	grafo *g = (grafo*)malloc(sizeof(grafo));
	g->cvertices = vertices;
	g->adyacencias = (int**)malloc(vertices * sizeof(int*));
	int i, j;
	for (i = 0; i < vertices; i++){
		g->adyacencias[i] = (int*)malloc(vertices * sizeof(int));
		//Inicializa en cero
		for(j = 0; j < vertices; j++){
			g->adyacencias[i][j] = 1;
			}	
		}
	return g;
	}




void imprime_matriz_grafo(grafo *g){
	int i, j;	
	for (i = 0; i < g->cvertices; i++){
		for (j = 0; j < g->cvertices; j++){
			printf("%d ", g->adyacencias[i][j]);
			}
		printf("\n");
		}
	}
	


grafo* lee_grafo_nodirigido(char *nombre_archivo){
	FILE *pf;
	pf = fopen(nombre_archivo, "r");
	int n_vertices, m_aristas;
	int i,j,k;
	if (pf == NULL){
		printf("Error de archivo\n");
		return NULL;
		}
	else{
		fscanf(pf, "%d %d", &n_vertices,&m_aristas); 		
		grafo *P = crea_grafo_vacio(n_vertices);	
		for(k = 0; k < m_aristas; k++){
			fscanf(pf,"%d %d",&i, &j);
			P->adyacencias[i - 1][j - 1] = 1;
			P->adyacencias[j - 1][i - 1] = 1;
			}
		fclose(pf);
		return  P;	
		}
	}


int obtiene_grado(grafo *g, int vertice){
	int i, cont=0;
	for (i = 0; i < g->cvertices; i++){
		if (g->adyacencias[vertice][i]==1){
			cont=cont+1;
		}
	}
	return cont;		
}

grafo* lee_grafo_dirigido_ponderado(char *nombre_archivo){
	FILE *pf;
	pf = fopen(nombre_archivo, "r");
	int n_vertices, m_aristas, peso;
	int i,j,k;
	if (pf == NULL){
		printf("Error de archivo\n");
		return NULL;
		}
	else{
		fscanf(pf, "%d %d", &n_vertices,&m_aristas); 		
		grafo *G = crea_grafo_vacio(n_vertices);	
		for(k = 0; k < m_aristas; k++){
			fscanf(pf,"%d %d %d",&i, &j, &peso);
			G->adyacencias[i - 1][j - 1] = peso;
			G->adyacencias[j - 1][i - 1] = 0;
			}
		fclose(pf);
		return  G;	
		}
	}

int grado_salida(grafo *g, int vertice){
	int cant=0;
	for (int i = 0; i < g->cvertices; ++i)
	{
		if (g->adyacencias[vertice-1][i]!=0)
		{
			cant=cant+1;
		}
	}
	return cant;
}

int grado_entrada(grafo *g, int vertice){
	int cant=0;
	for (int i = 0; i < g->cvertices; ++i)
	{
		if (g->adyacencias[i][vertice-1]!=0)
		{
			cant=cant+1;
		}
	}
	return cant;
}

grafo* Harary(grafo* g1, grafo* g2) {
    int vertices = g1->cvertices + g2->cvertices;
    int i, j;
    grafo *g3 = crea_grafo_vacio(vertices);

    for (i = 0; i < g1->cvertices; i++) {
        for (j = 0; j < g1->cvertices; j++) {
            g3->adyacencias[i][j] = g1->adyacencias[i][j];
        }
    }

    
    for (i = 0; i < g2->cvertices; i++) {
        for (j = 0; j < g2->cvertices; j++) {
            g3->adyacencias[i + g1->cvertices][j + g1->cvertices] = g2->adyacencias[i][j];
        }
    }

    for (i = 0; i < g1->cvertices; i++) {
        for (j = 0; j < g2->cvertices; j++) {
            g3->adyacencias[i][j + g1->cvertices] = 1;
            g3->adyacencias[j + g1->cvertices][i] = 1;
        }
    }

    return g3;
}

