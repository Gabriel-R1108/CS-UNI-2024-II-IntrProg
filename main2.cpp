#include "lagrange.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    double x, y, x_eval;

    // Leer el número de puntos
    cout << "Ingrese el número de puntos: ";
    cin >> n;

    if (n < 2) {
        cout << "El número de puntos debe ser al menos 2." << endl;
        return 1;
    }

    // Crear la lista enlazada
    Punto* cabeza = nullptr;

    // Leer los puntos (x, y)
    cout << "Ingrese las coordenadas x, y:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Punto " << i + 1 << " (x y): ";
        cin >> x >> y;
        agregarPunto(cabeza, x, y);
    }

    // Leer el valor de x en el que se desea evaluar
    cout << "Ingrese el valor de x a evaluar: ";
    cin >> x_eval;

    // Calcular el valor del polinomio en x_eval
    double resultado = calcularLagrange(cabeza, x_eval);

    // Imprimir el resultado
    cout << "El valor interpolado en x = " << x_eval << " es: " << resultado << endl;

    // Liberar memoria
    liberarLista(cabeza);

    return 0;
}
