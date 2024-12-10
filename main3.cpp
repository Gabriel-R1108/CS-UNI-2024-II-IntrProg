#include <iostream>
#include <string>
using namespace std;

// Función draw externa a todas las clases
void draw() {
    cout << "draw externa" << endl;
}

// Clase Figure
class Figure {
private: // (A)
    string m_name;

public:
    Figure(const string &_name = "") : m_name(_name) {}
    virtual ~Figure() {}

    virtual void draw() { // Método virtual
        cout << "Figure draw: " << m_name << endl;
    }

    virtual void info() = 0; // (1) Método virtual puro

    void SetName(const string _name) { m_name = _name; }
    string GetName() const { return m_name; }
};

// Clase derivada de Figure
class Rectangle : public Figure {
public:
    float a, b;

    // Constructor de RectangLe
    Rectangle(string _name) : Figure(_name), a(0), b(0) {
        cout << "Rectangle: " << GetName() << " Construido ..." << endl;
    }
    // Destructor de Rectangle
    virtual ~Rectangle() {
        cout << "Rectangle: " << GetName() << " Destruido ..." << endl;
    }

    virtual void draw() override {
        cout << "Rectangle draw" << endl;
        Figure::draw(); // (2) Llamada al método draw de la clase padre
        ::draw();       // (3) Llamada a la función draw() externa
    }

    virtual void info() override {
        cout << "Información del rectángulo: " << GetName() << endl;
    }
};

// Función principal
int main() {
    // (7) Uso de puntero clásico con delete manual
    Rectangle *pObj1 = new Rectangle("Rectángulo de prueba");

    // Objeto estático
    Rectangle Obj("Objeto estático");

    // (4) Declaración de un puntero pAtt para apuntar al atributo float `a`
    float *pAtt = nullptr;

    // (5) Usar pAtt para modificar el valor de `a` en el objeto apuntado por `pObj1`
    pAtt = &pObj1->a;
    *pAtt = 50;
    // (6) Usar pAtt para modificar el valor de `a` en el objeto estático `Obj`
    pAtt = &Obj.a;
    *pAtt = 25;

    // Mostrar los valores asignados
    cout << "Valor de a en pObj1: " << pObj1->a << endl;
    cout << "Valor de a en Obj: " << Obj.a << endl;

    // Llamar al método draw() en ambos objetos
    pObj1->draw();
    Obj.draw();
    delete pObj1;

    return 0; // (B) `Obj` se destruye 
}
