#pragma once
#include "Preriquisites.h"

// Clase base para los componentes. Esta clase define la interfaz que deben implementar los componentes.
class Componente {
public:
    // Metodo virtual puro para realizar una operacion. Cada componente concreto debe implementar este método.
    virtual void operacion() = 0;
};

// Clase concreta que implementa Componente. Esta clase representa un componente específico.
class ComponenteConcreto : public Componente {
public:
    // Implementacion concreta del metodo de operacion. Este método define la operación específica que realiza este componente.
    void operacion() override {
        cout << "Operacion del componente concreto" << endl;
    }
};

// Clase base para los decoradores. Esta clase define la interfaz que deben implementar los decoradores.
class Decorator : public Componente {
public:
    // Constructor que recibe un componente para decorar. El decorador añade funcionalidad al componente sin cambiar su interfaz.
    Decorator(Componente* componente) : m_componente(componente) {}

    // Implementacion del metodo de operacion que delega al componente original. Esto permite que el decorador ejecute la operación como si fuera el componente real, manteniendo la misma interfaz y comportamiento esperado.
    void operacion() override {
        m_componente->operacion();
    }

private:
    Componente* m_componente; // Almacena una instancia del componente a decorar.
};

// Decorador concreto A. Esta clase añade funcionalidad adicional al componente que decora.
class DecoratorConcretoA : public Decorator {
public:
    // Constructor que recibe un componente para decorar como variable.
    DecoratorConcretoA(Componente* componente) : Decorator(componente) {}

    // Implementacion adicional del metodo de operacion. Este método añade funcionalidad adicional a la operación del componente que decora.
    void operacion() override {
        Decorator::operacion(); // Llama al metodo del componente original.
        cout << "Operacion del Decorator A." << endl;
    }
};

// Otro decorador concreto B. Esta clase también añade funcionalidad adicional al componente que decora.
class DecoratorConcretoB : public Decorator {
public:
    // Constructor que recibe un componente para decorar.
    DecoratorConcretoB(Componente* componente) : Decorator(componente) {}

    // Implementacion adicional del metodo de operacion. Este método añade funcionalidad adicional a la operación del componente que decora.
    void operacion() override {
        Decorator::operacion(); // Llama al metodo del componente original.
        cout << "Operacion del Decorator B." << endl;
    }
};
