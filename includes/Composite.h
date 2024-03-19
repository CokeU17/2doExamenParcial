#pragma once
#include "Preriquisites.h"
#include <vector>

// Clase base de Componente. Esta clase define la interfaz que deben implementar las hojas y nodos compuestos.
class CComponent {
public:
    // Método virtual puro para realizar una operación. Cada hoja y nodo compuesto debe implementar este método.
    virtual void operacion() = 0;
};

// Clase Hoja (Leaf). Esta clase representa una hoja en la estructura del árbol.
class Leaf : public CComponent {
public:
    // Implementación concreta del método de operación. Este método define la operación específica que realiza esta hoja.
    void operacion() override {
        cout << "Operacion en la hoja." << endl;
    }
};

// Clase Nodo Compuesto. Esta clase representa un nodo compuesto en la estructura del árbol.
class Compuesto : public CComponent {
public:
    // Implementación del método de operación que realiza la operación en todas las hojas. Este método define cómo se realiza la operación en este nodo compuesto.
    void operacion() override {
        cout << "Operacion en el compuesto. Contiene " << Leafs.size() << " hojas." << endl;
        for (CComponent* Leaf : Leafs) {
            Leaf->operacion();
        }
    }

    // Método para agregar una hoja al nodo compuesto. Este método permite agregar nuevas hojas a este nodo compuesto.
    void agregarLeaf(CComponent* _Leaf) {
        Leafs.push_back(_Leaf);
    }

private:
    vector<CComponent*> Leafs; // Almacena las hojas que pertenecen a este nodo compuesto.
};

