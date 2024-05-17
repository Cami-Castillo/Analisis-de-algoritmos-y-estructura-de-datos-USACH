#include <stdio.h>
#include <stdlib.h>
#include "TDApila.h"


pila* nueva_pila(void){
    pila *p = (pila*)malloc(sizeof(pila));
	p->size = 0;
	p->tope = NULL;
	return p;
    }


int es_pila_vacia(pila *p){
	if(p->size == 0){
		return 1;
	    }
	else{
		return 0;
	    }
    }

void apilar(pila *p, int d){
	nodo*nodo_aux=(nodo*)malloc(sizeof(nodo));
	nodo_aux->dato=d;
	nodo_aux->siguiente=p->	tope;
	p->tope=nodo_aux;
	p->size=p->	size+1; 
	}

nodo* tope(pila *p){
	return p->tope;
}

void desapilar(pila *p){
	if(!es_pila_vacia(p)){
		nodo*nodo_aux;
		nodo_aux=p->tope;
		p->tope=p->tope->siguiente;
		p->size--;
		free(nodo_aux);
		}
	}
void imprime_pila(pila *p){
	pila*p_aux;
	p_aux=nueva_pila();
	while (!es_pila_vacia(p)){
		printf("%d ", p->tope->dato);
		apilar(p_aux,p->tope->dato);
		desapilar(p);
		}
	while(!es_pila_vacia(p_aux)){
		apilar(p,p_aux->tope->dato);
		desapilar(p_aux);
	}
}

int busca_dato_pila(pila* p, int dato){
	nodo*aux =p->tope;
	while(aux!=NULL){
		if(aux->dato==dato)
			return 1;
		aux=aux->siguiente;
	}
	return 0;
}






