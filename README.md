# Laberinto C++ Solver:

Este proyecto realizado en C++ es un generador de laberintos aleatorios que además es capaz de encontrar una solución por medio de un algoritmo de búsqueda recursiva. El mismo se encarga de encontrar un camino desde la entrada hasta la salida.

## Funcionalidades

- **Generación Aleatoria de Laberintos:** La función `generarLaberinto()` crea un laberinto aleatorio con dimensiones constantes de 19x19. La entrada y salida están predefinidas, y se utiliza un algoritmo de generación aleatoria con ajustes adicionales.

- **Búsqueda de Camino:** La función `buscarCaminoRecursivo()` utiliza un enfoque recursivo para encontrar el camino desde la entrada hasta la salida del laberinto.

- **Visualización Gráfica:** La función `buscar_camino()` muestra en la consola el laberinto con la solución resaltada.

Algoritmo de Generación del Laberinto:

El proyecto utiliza un algoritmo de generación aleatoria de un laberinto. La matriz que representa el laberinto posee en total 5 valores distintos, valores que van de 0 a 4. 
- El "0" representa un espacio vacio.
- El "1" representa el bloque de una pared.
- El "2" representa la entrada.
- El "3" representa la salida.
- El "4" representa un bloque perteneciente al camino de entrada a la salida (el de la solución).

Inicialmente, el laberinto se encuentra completamente vacio (solo posee paredes a los costados, arriba y abajo, que delimitan el laberinto como tal) . Posterior a ello, el algoritmo se encarga de escoger numeros aleatorios que se encuentran dentro de las paredes principales del  laberinto, y lo transforman a numeros pares, transformándolos luego a bloques ( adquieren un valor 1), luego se escoge una de las 4 opciones posibles alrededor del mismo punto, y si este representa un espacio vacio, lo transforma en un bloque, asi como tambien el punto medio de entre esos dos puntos mencionados anteriormente.
  

Algoritmo de Solución:

El proyecto utiliza un algoritmo de búsqueda recursiva para encontrar un camino desde un punto de entrada hasta un punto de salida en el laberinto. Este algoritmo explora de manera recursiva todas las direcciones posibles desde cualquier punto dado y utiliza la técnica de backtracking para retroceder si se encuentra con un obstáculo o un callejón sin salida.

## Estructura del Proyecto

|-- laberinto.cpp
|-- README.md # Documentación principal del proyecto

## Variables Principales

- `fila_entrada`, `columna_entrada`: Coordenadas de la entrada del laberinto.
- `fila_salida`, `columna_salida`: Coordenadas de la salida del laberinto.
- `filas`, `columnas`: Dimensiones del laberinto.

## Funciones Principales

- **`generarLaberinto()`:** Genera un laberinto aleatorio y retorna la matriz que lo representa.

- **`buscarCaminoRecursivo()`:** Función recursiva que encuentra el camino desde la entrada hasta la salida.

- **`buscar_camino()`:** Llama a `buscarCaminoRecursivo()` y muestra el laberinto con la solución.
## Requisitos del Sistema

- **Compilador C++:** G++ (GNU Compiler Collection)
  - Versión: Ubuntu 13.2.0-4ubuntu3, G++ 13.2.0
  - [Enlace de Descarga de G++](https://gcc.gnu.org/)
  
## Bibliotecas Utilizadas

Este proyecto en C++ hace uso de las siguientes bibliotecas:

### [iostream](https://www.cplusplus.com/reference/iostream/)

La biblioteca `iostream` se utiliza para la entrada y salida estándar. Proporciona funcionalidades para la lectura desde el teclado y la impresión en la consola.

No es necesario instalar esta biblioteca por separado, ya que es parte de la biblioteca estándar de C++.

### [ctime](https://www.cplusplus.com/reference/ctime/)

La biblioteca `ctime` se utiliza para trabajar con funciones relacionadas con el tiempo, como `time()`.

No es necesario instalar esta biblioteca por separado, ya que es parte de la biblioteca estándar de C++.

### [cstdlib](https://www.cplusplus.com/reference/cstdlib/)

La biblioteca `cstdlib` se utiliza para generar números aleatorios con `rand()`.

No es necesario instalar esta biblioteca por separado, ya que es parte de la biblioteca estándar de C++.

### [vector](https://www.cplusplus.com/reference/vector/)

La biblioteca `vector` se utiliza para trabajar con arreglos dinámicos de tamaño variable.

No es necesario instalar esta biblioteca por separado, ya que es parte de la biblioteca estándar de C++.


