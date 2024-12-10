#include "matriz.h"
#include <iostream>
using namespace std;

int calcularParidad(int* inicio, int longitud) {
    int paridad = 0;
    for (int i = 0; i < longitud; ++i) {
        paridad ^= *(inicio + i); 
    }
    return paridad;
}

void imprimirMatriz(int** matriz, int filas, int columnas) { //alto puntero
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << *(*(matriz + i) + j) << " ";
        }
        cout << endl;
    }
}

int** crearMatriz(int filas, int columnas) {
    int** matriz = new int*[filas];
    for (int i = 0; i < filas; ++i) {
        matriz[i] = new int[columnas];
    }
    return matriz;
}

void liberarMatriz(int** matriz, int filas) {
    for (int i = 0; i < filas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

void copiarMatriz(int** origen, int** destino, int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            *(*(destino + i) + j) = *(*(origen + i) + j);
        }
    }
}
