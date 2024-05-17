#include <stdio.h>
#include <stdlib.h>
#include "TDApila_implementacion.c"

int main()
{
	pila *p;
	p = nueva_pila();
	
	pila *p2;
	p2 =nueva_pila ();

	pila*aux;
	aux=nueva_pila();

	printf("Apilar 5,4,3,2,1 : \n");
	apilar(p,1);
	apilar(p,2);
	apilar(p,3);
	apilar(p,4);
	apilar(p,5);
	printf("Tope: %i\n" "Siguiente: %i\n", p->tope->dato, p->tope->siguiente->dato);

	while (!es_pila_vacia(p)){
		if(!es_pila_vacia(p2) || (tope(aux->tope->dato) || tope(p->tope->dato) <= tope(p->tope->dato))){
			desapilar(p2);
			apilar(aux, tope(p2->tope->dato));
			while (!es_pila_vacia(aux))
			{
				desapilar(p2);
				apilar(aux,tope(p2->tope->dato));
			
			}	
		}
		else{
			desapilar(p2);
			apilar(aux, tope(p->tope->dato));
		}
	}
	
	imprime_pila(p);
	imprime_pila(p2);
	imprime_pila(aux);


	/*printf("Desapilar %i: \n", p->tope->dato);
	desapilar(p);
	printf("Tope: %i\n" "Siguiente: %i\n", p->tope->dato, p->tope->siguiente->dato);
	printf("Pila actual: ");
	imprime_pila(p);
	printf("\n¿Dato 3 esta en la pila? \n");
	int resultado= busca_dato_pila(p, 3);
	if (resultado ==1){
		printf("El dato 3 si está en la pila\n");
	}*/

	return 0;



}
