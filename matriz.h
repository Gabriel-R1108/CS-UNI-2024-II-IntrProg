#ifndef __MATRIZ_H__
#define __MATRIZ_H__

int calcularParidad(int* inicio, int longitud);

void imprimirMatriz(int** matriz, int filas, int columnas);

int** crearMatriz(int filas, int columnas);

void liberarMatriz(int** matriz, int filas);

void copiarMatriz(int** origen, int** destino, int filas, int columnas);

#endif
