/*------------- TDA punto -------------*/

/*------------- estructura de datos -------------*/

typedef struct{ 
	float x; 
	float y;} punto;


/*------------- operaciones -------------*/

// crea_punto() retorna un nuevo punto con coordenadas x e y
// complejidad de tiempo: O(1)
punto crea_punto(float x, float y);


// calcula_distancia() retorna la distancia entre los puntos a y b
// complejidad de tiempo: O(1)	
float calcula_distancia(punto a, punto b);


// distancia_origen() retorna la distancia al origen del punto a
// complejidad de tiempo: O(1)	
float distancia_origen(punto a);
