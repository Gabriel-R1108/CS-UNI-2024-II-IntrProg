#include "matriz.h"
#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); 

    int filas, columnas;
    cout << "Ingrese el numero de filas: ";
    cin >> filas;
    cout << "Ingrese el numero de columnas: ";
    cin >> columnas;

    // Crear y llenar la matriz original
    int** matriz = crearMatriz(filas, columnas);
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            *(*(matriz + i) + j) = rand() % 2;
        }
    }

    cout << "Matriz original A:" << endl;
    imprimirMatriz(matriz, filas, columnas);

    // Crea la matriz ampliada
    int** matrizAmpliada = crearMatriz(filas + 1, columnas + 1);

    // Copia la matriz original a la ampliada
    copiarMatriz(matriz, matrizAmpliada, filas, columnas);

    // Calcula las paridades horizontales
    for (int i = 0; i < filas; ++i) {
        *(*(matrizAmpliada + i) + columnas) = calcularParidad(*(matrizAmpliada + i), columnas);
    }

    // Calcula las pridades verticales
    for (int j = 0; j < columnas; ++j) {
        int paridadVertical = 0;
        for (int i = 0; i < filas; ++i) {
            paridadVertical ^= *(*(matrizAmpliada + i) + j);
        }
        *(*(matrizAmpliada + filas) + j) = paridadVertical;
    }

    // pAridad total
    *(*(matrizAmpliada + filas) + columnas) = calcularParidad(*(matrizAmpliada + filas), columnas);

    cout << "Matriz A con paridad (" << filas + 1 << " x " << columnas + 1 << "):" << endl;
    imprimirMatriz(matrizAmpliada, filas + 1, columnas + 1);

    // Liberar 
    liberarMatriz(matriz, filas);
    liberarMatriz(matrizAmpliada, filas + 1);

    return 0;
}
