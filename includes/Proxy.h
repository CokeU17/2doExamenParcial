#pragma once
#include "Preriquisites.h"

// Interfaz del sujeto
class Sujeto {
public:
    // Metodo virtual puro para realizar una operacion.
    // Este método debe ser implementado por todas las clases derivadas
    virtual void operacion() = 0;
};

// Implementacion del sujeto real
class SujetoReal : public Sujeto {
public:
    // Implementacion concreta del metodo de operacion.
    // Imprime un mensaje en la consola indicando que la operación se está realizando en el sujeto real
    void operacion() override {
        cout << "Operacion en el sujeto real." << endl;
    }
};

// Proxy
class Proxy : public Sujeto {
public:
    // Constructor del proxy
    // Inicializa el puntero al sujeto real como nulo
    Proxy() : m_sujetoReal(nullptr) {}

    // Implementacion del metodo de operacion del proxy
    // Si el sujeto real no ha sido creado, lo crea y luego llama a su metodo de operacion
    void operacion() override {
        // Se crea el sujeto real solo si no existe
        if (m_sujetoReal == nullptr) {
            m_sujetoReal = new SujetoReal();
        }
        cout << "Operacion en el proxy. Redirigiendo a sujeto real." << endl;
        // Se llama al metodo de operacion del sujeto real.
        m_sujetoReal->operacion();
    }

private:
    SujetoReal* m_sujetoReal; // Almacena una instancia del sujeto real.
};

