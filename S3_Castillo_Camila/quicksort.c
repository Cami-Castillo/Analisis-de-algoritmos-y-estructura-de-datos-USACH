//Por Camila Castillo
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void imprime(int *numeros, int n){
	int i = 0;
	while(i < n){
		printf("%i\n", numeros[i]);
		i++;			
		}
	}

void lee_archivo(int *numeros, int n, char nombre[]){
	FILE *fp;
    fp = fopen(nombre, "r");
    if(fp == NULL){
    	printf("Error al abrir archivo %s\n", nombre);
        return;
		}

	int i = 0;
	while(i < n){
		fscanf(fp, "%i ", &numeros[i]);
		i++;			
		}
    fclose(fp);
	}

void intercambia(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
	}


void seleccion(int *numeros, int n){
    int i, j, indice;		
    for (i = 0; i < (n - 1); i++){
        indice = i;
        for (j = i + 1; j < n; j++){
            if (numeros[j] < numeros[indice])
                indice = j;
			}
        if(indice != i)
            intercambia(&numeros[indice], &numeros[i]);
		}
	}
// Quicksort1 pivote = ultimo elemento
int particiona1 (int *num, int p, int r ){
	int x, j, i;
	i= p-1;
	x= num[r];
	//PARA VER LA ELECCION DEL PIVOTE: 
	//printf("pivote" "%d\n",x );
	for (j=p; (j<r); j++){
		if (num[j] <= x){
			i=i+1;
			intercambia(&num[i], &num[j]);
			}	
	}
	intercambia(&num[i+1], &num[r]);
	return (i+1);
};

//Quicksort2 = elemento del medio
int particiona2 (int *num, int p, int r ){
	int x, j, i,y;
	i= p-1;
	y=(p + r) / 2;

	intercambia(&num[y], &num[r]);
	x= num[r];
	//PARA VER LA ELECCION DEL PIVOTE:
	//printf("pivote" "%d\n",x );
	for (j=p; (j<r); j++){
		if (num[j] <= x){
			i=i+1;
			intercambia(&num[i], &num[j]);
			}	
	}
	intercambia(&num[i+1], &num[r]);
	return (i+1);
};
	
 void quicksort1(int *num,int p, int r){

	if (p < r) {
		int q;
		q= particiona1(num,p,r);
		quicksort1(num,p,q-1);
		quicksort1(num,q+1,r);
		}
}

void quicksort2(int *num,int p, int r){

	if (p < r) {
		int q;
		q= particiona2(num,p,r);
		quicksort2(num,p,q-1);
		quicksort2(num,q+1,r);
		}
}


int main(int argc, char *argv[]){

	int i, n = atoi(argv[2]);
	int numeros[n];
	float tiempo_algoritmo = 0;
	clock_t clock_ini, clock_fin;
	
	lee_archivo(numeros, n, argv[1]);
	printf("Arreglo de entrada: \n");
	//imprime(numeros, n);
	
	//Ordenamiento Quicksort pivote = ultimo elemento
	clock_ini = clock();
	quicksort1(numeros,0,n-1);
	clock_fin = clock();
	tiempo_algoritmo = (float)((clock_fin - clock_ini) / CLOCKS_PER_SEC);
	
	printf("quicksort ultimo elemento: \n");
	//printf("Arreglo ordenado: \n");
	//imprime (numeros, n);
	printf("\nTiempo del algoritmo en segundos: %.2f  \n", tiempo_algoritmo);
	

	//Ordenamiento Quicksort pivote = elemento del medio
	printf("quicksort medio: \n");
	clock_ini = clock();
	quicksort2(numeros,0,n-1);
	clock_fin = clock();
	tiempo_algoritmo = (float)((clock_fin - clock_ini) / CLOCKS_PER_SEC);
	
	//printf("Arreglo ordenado: \n");
	//imprime (numeros, n);
	printf("\nTiempo del algoritmo en segundos: %.2f  \n", tiempo_algoritmo); 


	
    return 0;
}
