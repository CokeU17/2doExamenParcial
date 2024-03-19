#pragma once
#include "Preriquisites.h"

// Clase que representa un producto complejo
class BProducto {
public:
    // Método para agregar una parte al producto
    void agregarParte(const string& _parte) {
        partes.push_back(_parte);
    }

    // Método para mostrar las partes del producto
    void mostrar() {
        cout << "Partes del producto: ";
        for (const string& parte : partes) {
            cout << parte << " ";
        }
        cout << endl;
    }

private:
    // Vector para almacenar las partes del producto
    vector<string> partes;
};

// Clase abstracta del constructor (Builder)
class Builder {
public:
    // Métodos virtuales puros para construir partes del producto y obtener el producto
    virtual void construirParteA() = 0;
    virtual void construirParteB() = 0;
    virtual BProducto* obtenerProducto() = 0;
};

// Clase concreta del constructor (Builder Concreto)
class BuilderConcreto : public Builder {
public:
    // Constructor que inicializa un nuevo producto
    BuilderConcreto() {
        producto = new BProducto();
    }

    // Implementación de los métodos para construir partes del producto
    void construirParteA() override {
        producto->agregarParte("Parte A");
    }

    void construirParteB() override {
        producto->agregarParte("Parte B");
    }

    // Método para obtener el producto construido
    BProducto* obtenerProducto() override {
        return producto;
    }

private:
    // Puntero al producto que se está construyendo
    BProducto* producto;
};

// Clase Director
class Director {
public:
    // Constructor que inicializa el constructor a utilizar
    Director(Builder* _builder) : builder(_builder) {}

    // Método para dirigir la construcción del producto
    void construir() {
        builder->construirParteA();
        builder->construirParteB();
    }

private:
    // Puntero al constructor que se está utilizando
    Builder* builder;
};

