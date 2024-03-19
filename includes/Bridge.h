#pragma once
#include "Preriquisites.h"

// Interfaz base para las implementaciones
class Implementacion {
public:
    // Método virtual puro para realizar una operación.
    // Este método debe ser implementado por todas las clases derivadas
    virtual void operacion() = 0;
};

// Implementación Concreta A 
class ImplementacionConcretaA : public Implementacion {
public:
    // Implementación concreta del método de operación para la Implementación A.
    void operacion() override {
        cout << "Operación en implementación A" << endl;
    }
};

// Implementación Concreta B
class ImplementacionConcretaB : public Implementacion {
public:
    // Implementación concreta del método de operación para la Implementación B.
    void operacion() override {
        cout << "Operación en implementación B" << endl;
    }
};

// Clase Abstracción
class Abstraccion {
public:
    // Constructor que recibe una implementación.
    // Inicializa la implementación con la proporcionada
    Abstraccion(Implementacion* imp) : m_implementacion(imp) {}

    // Método virtual puro para realizar una operación.
    // Este método debe ser implementado por todas las clases derivadas
    virtual void operacion() = 0;

protected:
    // Puntero a la implementación
    Implementacion* m_implementacion;
};

// Abstracción Refinada 
class AbstraccionRefinada : public Abstraccion {
public:
    // Constructor que recibe una implementación.
    // Inicializa la implementación con la proporcionada
    AbstraccionRefinada(Implementacion* imp) : Abstraccion(imp) {}

    // Implementación del método de operación.
    // Llama al método de operación de la implementación.
    void operacion() override {
        m_implementacion->operacion();
    }
};

