#include <stdlib.h>
#include <stdio.h>
#include "TDAconjunto.h"


/*------------- operaciones -------------*/


conjunto* crea_conjunto(int max_elementos){
    conjunto* c = malloc(sizeof(conjunto));
    c->cardinalidad = 0;
    c->max_elementos = max_elementos;
    c->elementos = (int*)malloc(c->max_elementos * sizeof(int));
    return c;
    }


void destruye_conjunto(conjunto *c){
    free(c->elementos);
    free(c);
    }


int pertenece(conjunto *c, int e){
    int i = 0;
    while (i < c->cardinalidad){
        if (c->elementos[i] == e){
	        return 1;
	        }
	    i = i + 1;
        }
    return 0;
    }  


void imprime_conjunto(conjunto *c) {
    printf("\n Elementos: ");
    if (c->cardinalidad > 0){
        for (int i = 0; i < c->cardinalidad; i++){
            printf("%d ", c->elementos[i]);   
            }
        } 
	else{ 
		printf("%c", 155);
		}
	}


void agregar_elemento(conjunto *c, int e){
    if ((c->cardinalidad < c->max_elementos) && (!pertenece(c, e))){
	    c->elementos[c->cardinalidad] = e;
	    c->cardinalidad++;
        }
    }


void eliminar_elemento(conjunto *c, int e){
    if (pertenece(c, e)){
        int j, i = 0;
        while (i < c->cardinalidad){
            if (c->elementos[i] == e){
		        j = i;
				i = c->cardinalidad;
	            }
	        i = i + 1;
            }

        while (j < (c->cardinalidad - 1)){
            c->elementos[j] = c->elementos[j + 1];
	        j = j + 1;
            }
	    c->cardinalidad--;
        }
    }