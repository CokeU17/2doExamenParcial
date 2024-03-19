#pragma once
#include "Preriquisites.h"

// Clase base para los prototipos
class Prototype {
public:
    // Metodo virtual puro para clonar el prototipo
    // Este método debe ser implementado por todas las clases derivadas
    virtual Prototype* clonar() = 0;

    // Metodo virtual puro para configurar el prototipo
    // Este método debe ser implementado por todas las clases derivadas
    virtual void configurar(string _valor) = 0;

    // Metodo virtual puro para mostrar el prototipo
    // Este método debe ser implementado por todas las clases derivadas
    virtual void mostrar() = 0;
};

// Clase concreta del prototipo
class PrototypeConcreto : public Prototype {
public:
    // Implementación del método para clonar el prototipo concreto
    // Crea una copia del objeto actual y devuelve un puntero a la copia
    Prototype* clonar() override {
        PrototypeConcreto* copia = new PrototypeConcreto();
        copia->configurar(valor);
        return copia;
    }

    // Implementación del método para configurar el valor del prototipo concreto
    // Configura el valor del objeto actual con el valor proporcionado
    void configurar(string _valor) override {
        valor = _valor;
    }

    // Implementación del método para mostrar el valor del prototipo concreto
    // Imprime el valor del objeto actual en la consola
    void mostrar() override {
        cout << "Valor: " << valor << endl;
    }

private:
    string valor; // Atributo privado que almacena el valor del prototipo
};

