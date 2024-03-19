#pragma once
#include "Preriquisites.h"

    // Clase base de productos. Esta clase define la interfaz que deben implementar los productos.
    class FMProducto {
    public:
        // Método virtual puro para realizar una operación. Cada producto concreto debe implementar este método.
        virtual void operacion() = 0;
    };

    // Clase fábrica. Esta clase define la interfaz que deben implementar las fábricas.
    class FMFabrica {
    public:
        // Métodos virtuales puros para crear productos. Cada fábrica concreta debe implementar estos métodos.
        virtual FMProducto* crearProducto() = 0;
        virtual FMProducto* crearPapas() = 0;
        virtual FMProducto* crearRefresco() = 0;
    };

    // Clase concreta del producto. Esta clase representa un producto específico.
    class FMProductoConcreto : public FMProducto {
    public:
        // Implementación concreta del método de operación. Este método define la operación específica que realiza este producto.
        void operacion() override {
            cout << "Operación en Producto Concreto" << endl;
        }
    };

    // Clase concreta de fábrica. Esta clase representa una fábrica específica.
    class FMFabricaConcreta : public FMFabrica {
    public:
        // Implementación concreta de los métodos para crear productos. Estos métodos definen cómo se crean los productos en esta fábrica.
        FMProducto* crearProducto() override {
            return new FMProductoConcreto();
        }

        FMProducto* crearPapas() override {
            return new FMProductoConcreto();
        }

        FMProducto* crearRefresco() override {
            return new FMPepsiBlack();
        }
    };

    // Clase concreta del producto "Chettos". Esta clase representa un producto específico.
    class FmChettos : public FMProducto {
    public:
        string nombre;
        float peso;
        float precio;

        // Método para registrar los detalles del producto.
        void registrar(string _nombre, float _peso, float _precio) {
            nombre = _nombre;
            peso = _peso;
            precio = _precio;
        }

        // Implementación concreta del método de operación. Este método define la operación específica que realiza este producto.
        void operacion() override {
            cout << "Nombre: " << nombre << ", Peso: " << peso << "g, Precio: $" << precio << endl;
        }
    };

    // Clase concreta del producto "PepsiBlack". Esta clase representa un producto específico.
    class FMPepsiBlack : public FMProducto {
    public:
        string nombre;
        float peso;
        float precio;

        // Método para registrar los detalles del producto.
        void registrar(string _nombre, float _peso, float _precio) {
            nombre = _nombre;
            peso = _peso;
            precio = _precio;
        }

        // Implementación concreta del método de operación. Este método define la operación específica que realiza este producto.
        void operacion() override {
            cout << "Nombre: " << nombre << ", Peso: " << peso << "ml, Precio: $" << precio << endl;
        }
    };

    // Clase concreta de la fábrica "Pepsico". Esta clase representa una fábrica específica.
    class FMPepsico : public FMFabrica {
    public:
        // Implementación concreta de los métodos para crear productos. Estos métodos definen cómo se crean los productos en esta fábrica.
        FMProducto* crearPapas() override {
            return new FmChettos();
        }

        FMProducto* crearRefresco() override {
            return new FMPepsiBlack();
        }
    };

