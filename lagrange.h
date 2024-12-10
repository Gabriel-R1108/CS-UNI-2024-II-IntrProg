#ifndef __LAGRANGE_H__
#define __LAGRANGE_H__

struct Punto {
    double x, y;       
    Punto* siguiente;  
};
//Prototipos
void agregarPunto(Punto*& cabeza, double x, double y);
double calcularLagrange(Punto* cabeza, double x);
void liberarLista(Punto*& cabeza);

#endif
