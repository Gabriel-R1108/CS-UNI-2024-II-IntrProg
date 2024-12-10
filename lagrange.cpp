#include "lagrange.h"
#include <iostream>
using namespace std;

// Función para agregar un punto a la lista enlazada
void agregarPunto(Punto*& cabeza, double x, double y) {
    Punto* nuevo = new Punto; // Crear nuevo nodo
    nuevo->x = x;
    nuevo->y = y;
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

// Función para calcular el valor del polinomio de Lagrange en un punto dado
double calcularLagrange(Punto* cabeza, double x) {
    double resultado = 0.0;
    Punto* i = cabeza;

    while (i != nullptr) {
        // Calcular el término L_i(x)
        double Li = 1.0;
        Punto* j = cabeza;

        while (j != nullptr) {
            if (j != i) {
                Li *= (x - j->x) / (i->x - j->x);
            }
            j = j->siguiente;
        }

        // Sumar el término al resultado
        resultado += i->y * Li;
        i = i->siguiente; //-> por ser puntero 
    }

    return resultado;
}

// Función que libera 
void liberarLista(Punto*& cabeza) {
    while (cabeza != nullptr) {
        Punto* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}
