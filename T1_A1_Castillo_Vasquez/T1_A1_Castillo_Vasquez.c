#include <stdio.h>
#include <stdlib.h>

#define MAX_INT 2432902008176640001; // Se define este número ya que es el factorial de 20, para no producir desborde.

typedef struct Carga {
    int peso; 
} Carga;

 // Variable global para almacenar el mínimo número de contenedores utilizados
unsigned long long minContenedores = MAX_INT; 

// Función recursiva
void asignarCargas(Carga cargas[], int nCargas, int capacidadContenedor, int contenedorActual[], int index, int nContenedoresUtilizados) {
    //Verifica si se ha alcanzado el final de las cargas
    if (index == nCargas) {
        if (nContenedoresUtilizados < minContenedores) {//Si nContenedoresUtilizados es menor que minContenedores
            minContenedores = nContenedoresUtilizados;  // Se actualiza minContenedores
        }
    return   ; 
    }
 //Iterar sobre los contenedores utilizados.
for (int i = 0; i < nContenedoresUtilizados; i++) {
    if (contenedorActual[i] + cargas[index].peso <= capacidadContenedor) {
        contenedorActual[i] = contenedorActual[i] + cargas[index].peso; 
        asignarCargas(cargas, nCargas, capacidadContenedor, contenedorActual, index + 1, nContenedoresUtilizados);
        contenedorActual[i] = contenedorActual[i] - cargas[index].peso; 
    }
}
    if (nContenedoresUtilizados < minContenedores) { //Verificar si aún hay espacio para un nuevo contenedor
        contenedorActual[nContenedoresUtilizados] = cargas[index].peso;
        asignarCargas(cargas, nCargas, capacidadContenedor, contenedorActual, index + 1, nContenedoresUtilizados + 1);
    }
}

int main(int argc, char *argv[]) {
    
    // Verificar si se abre el archivo
    FILE *arch = fopen(argv[1], "r");
    if (arch == NULL) {
        printf("Error al abrir archivo %s\n", argv[1]);
        return 1;
    }

    // Leer el número de cargas y la capacidad del contenedor
    int nCargas, capacidadContenedor;
    fscanf(arch, "%d %d", &nCargas, &capacidadContenedor);

    // Verificar si los valores leídos son válidos
    if (nCargas <= 0 || capacidadContenedor <= 0) {
        printf("Datos incorrectos en el archivo %s\n", argv[1]);
        fclose(arch);
        return 1;
    }

    // Leer los pesos de las cargas del archivo
    Carga cargas[nCargas];
    for (int i = 0; i < nCargas; i++) {
        fscanf(arch, "%d", &cargas[i].peso);
        if (cargas[i].peso <= 0 || cargas[i].peso > capacidadContenedor) {
            printf("Error en el peso de la carga %d en el archivo %s\n", i + 1, argv[1]);
            fclose(arch);
            return 1;
        }
    }
    fclose(arch);

    // Inicializar variables para la asignación de cargas
    int contenedorActual[nCargas];
    for (int i = 0; i < nCargas; i++) {
        contenedorActual[i] = 0;
    }

    // Realizar la enumeración exhaustiva para asignar cargas a contenedores
    asignarCargas(cargas, nCargas, capacidadContenedor, contenedorActual, 0, 0);

    // Mostrar el número mínimo de contenedores utilizados
    printf("Número mínimo de contenedores: %lld\n", minContenedores);

    return 0;
}
