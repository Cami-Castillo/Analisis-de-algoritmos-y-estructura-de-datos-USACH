#include <stdio.h>
#include <stdlib.h>
#include "TDAlista_implementacion.c"

int main(){
	
	
    lista *l = nueva_lista();
    inserta_inicio(l, 5);
    inserta_inicio(l, 7);
    inserta_inicio(l, 4);
    inserta_inicio(l, 2);
    imprime_lista(l);
    
    elimina_inicio(l);
    imprime_lista(l);
    
    elimina_inicio(l);
    imprime_lista(l);
    
    inserta_inicio(l, 3);
    imprime_lista(l);
    
    int cont=cuenta_nodos(l);
    printf("%d\n", cont);
    
    int busca=busca_dato(l, 2);
    // si es 0 el dato no existe
	printf("%d\n", busca);
    
    
    invierte(l);
    return 0;
}
