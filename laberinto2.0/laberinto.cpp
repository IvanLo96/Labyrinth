#include <iostream> // Biblioteca utilizada para entradas y salidas.
#include <ctime> // Biblioteca para hacer uso del tiempo de la computadora.
#include <cstdlib> // Biblioteca utilizada para generar numeros aleatorios.
#include <vector> // Biblioteca utilizada para generar arreglos de tamaño variable, util para la solucion al laberinto.

//Tipo de dato struct, el cual sirve para declarar luego el vector que poseera coordenadas x e y.
struct Coordenadas {    
    int x;
    int y;
};

using namespace std; 

// Variables globales:
int fila_entrada;
int columna_entrada;
int fila_salida;
int columna_salida;
int filas = 19;
int columnas = 19;


//FUNCION GENERAR LABERINTO 


int ** generarLaberinto() {   //funcion que genera un laberinto aleatorio, y retorna la matriz que representa ese laberinto.

	int **matriz;
	matriz = new int *[filas];



	for (int i = 0; i < filas; i++) {
		matriz[i] = new int[columnas];
	}


	//PAREDES DEL LABERINTO

	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (i == 0 || j == 0 || i == filas - 1 || j == columnas - 1) {
				matriz[i][j] = 1;  //paredes
            }  
			else {
				matriz[i][j] = 0;  //vacio
                
               
			}
		}
	}
	

	// ALGORITMO PARA GENERAR EL LABERINTO
	srand(time(NULL));
	for (int i = 0; i < filas*columnas; i++) {
		int x = rand() % (columnas - 4)+2; 
		x = (x / 2) * 2; // Los valores aleatorios se convierten a numeros pares, si no se limita el rango de valores que tomara x, el laberinto estara excesivamente cargado de paredes.
       
		int y = rand()% (filas - 4) + 2;
		y = (y / 2) * 2; // Se transforman los valores aleatorios de y a valores pares, simplemente porque se obtienen mejores resultados en el momento de la creacion de paredes del laberinto.
       
		matriz[y][x] = 1;  //Pared  
		int mx[4] = { x, x,  x + 2, x - 2 }; // Array que contiene las filas de los puntos cercanos al punto elegido de forma aleatoria.
		int my[4] = { y + 2,y - 2, y ,  y };  // Array que contiene las columnas de los puntos cercanos al punto elegido de forma aleatoria.

		int r = rand() % 4;	// este valor calculado de manera aleatoria (entre 0 y 3) sera el indice del array m
		
        if (matriz[my[r]][mx[r]] == 0) { // Si el punto cercano al punto elegido de forma aleatoria es un espacio vacio, se convierte a una pared, ademas tambien el punto medio entre ese punto y el elegido de manera aleatoria.
		matriz[my[r]][mx[r]] = 1; 
		matriz[my[r] +( y - my[r])/2][mx[r]+(x- mx[r])/2] = 1; // Punto medio.

        

		}

	}

	


// ENTRADA DEL LABERINTO

    fila_entrada = 0;
    columna_entrada =(columnas/2)-2;
    matriz[fila_entrada][columna_entrada] = 2;

// SALIDA DEL LABERINTO
   
    fila_salida = filas-1;
    columna_salida = (columnas/2) + 2;
    matriz[fila_salida][columna_salida] = 3;



// AGREGAR PAREDES A LOS COSTADOS

	int contador = 0;
    for (int i = 1; i<filas-2; i = i +2)
    { 
    if (i<filas-1){
	if (matriz[i][2]==1 and contador <filas)
        {
		matriz[i][1]=1;
        }

    if (matriz[i][columnas-3]==1)
    {matriz[i][columnas-2] = 1;}

		contador = contador+1;
    }

    }

// AGREGAR PAREDES ARRIBA

contador = 0;
matriz[2][columna_entrada] = 0; // Para evitar posible figura cerrada a la entrada del laberinto.
for (int i = 4; i<columnas-2; i = i+3)
{
   if (matriz[2][i]== 1 and matriz[0][i] == 1 and contador<columnas/2)
   { matriz[1][i] = 1;
   }

contador = contador+1;

}



//  MOSTRAR EN PANTALLA EL LABERINTO 
	for(int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {

			if (matriz[i][j] == 1) {
                cout << "⬛";

			}
			if(matriz[i][j] == 0 ) {
				cout << "  ";
			}
            if(matriz[i][j] == 2) {
				cout << "E ";
			}
            if(matriz[i][j] == 3) {
				cout << "S ";
			}

		}
		cout << "\n"; 
	}


return matriz;  // la funcion retorna la matriz que representa el laberinto.


}





vector<Coordenadas> camino; // se declara el vector llamado camino, el cual poseera las coordenadas de los puntos que seran parte del camino a la salida.


// FUNCION RECURSIVA PARA BUSCAR EL CAMINO

bool buscarCaminoRecursivo(int **matriz, int x, int y) {

    // Verificar si nos encontramos fuera del laberinto
    if (x < 0 || x >= filas || y < 0 || y >= columnas) {
        return false;
    }

    // Verificar si alcanzamos la salida
    if (x == fila_salida && y == columna_salida) {
        camino.push_back({x, y}); //agrega las coordenadas al final del vector camino.
        return true;
    }

    // Verificar si la celda es válida (no es pared ni parte del camino actual)
    if (matriz[x][y] == 0) {
        camino.push_back({x, y});

        // Marcamos la celda actual como parte del camino
        matriz[x][y] = 4; 

        // Intentar moverse en todas las direcciones posibles
        if (buscarCaminoRecursivo(matriz, x + 1, y) ||
            buscarCaminoRecursivo(matriz, x - 1, y) ||
            buscarCaminoRecursivo(matriz, x, y + 1) ||
            buscarCaminoRecursivo(matriz, x, y - 1)) {
            return true;
        }

        // Si ninguna dirección lleva a la solución, retrocedemos
        camino.pop_back();
        matriz[x][y] = 0; // Desmarcamos la celda
    }

    return false;
}



//  FUNCION BUSCAR CAMINO

void buscar_camino(int **matriz) {
    // Llamamos a la función recursiva desde la posición de entrada
    bool encontrado = buscarCaminoRecursivo(matriz, fila_entrada+1, columna_entrada); // se declara la variable encontrado, que por medio de la funcion buscar camino recursivo, se puede saber si tiene o no solucion.

// Si el laberinto encuentra una solucion, imprime la misma en la pantalla, si no, imprime que no se encontro un camino.
    if (encontrado) {


            for(int i = 0; i < filas; i++) {
		        for (int j = 0; j < columnas; j++) {

                    if(matriz[i][j] == 0 ) {cout << "  ";} // Espacios vacios.
		
			        if (matriz[i][j] == 1) {cout << "⬛";} // Paredes.

                    if(matriz[i][j] == 2) {cout << "E ";} //Entrada.

                    if(matriz[i][j] == 3) {cout << "S ";} //Salida.

                    if(matriz[i][j] == 4) {cout << "⬜";} //Camino a la salida.

		}
		cout << "\n"; 
	}
        } 
    
    else {
        cout << "No se encontró un camino.";
    }

    cout << endl;
}

int main() {
    cout<<"LABERINTO:";
    cout<<endl;
    int **mi_laberinto = generarLaberinto(); //Se llama a la funcion generarLaberinto, la misma retorna la matriz que representa el laberinto, la cual guardamos en la variable mi_laberinto.
    cout<<endl;
    
    
    cout<<"LABERINTO CON SU SOLUCION:";
    cout<<endl;
    buscar_camino(mi_laberinto); // Se llama a la funcion que busca la solucion al laberinto, o sea calcula y mustra en la terminal el camino desde la entrada a la salida del laberinto.



    // Liberar memoria de la matriz ¨mi_laberinto¨ después de su uso, para evitar fugas de memoria.
        delete[] mi_laberinto;
    return 0;
}

