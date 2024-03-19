#pragma once
#include "Preriquisites.h"

// Clase Singleton. Esta clase garantiza que solo exista una instancia de sí misma durante la ejecución del programa.
class Singleton {
private:
    int value; // Valor almacenado en la instancia.

    // Constructor privado para evitar instanciación directa. Al ser privado, ningún otro objeto puede crear una instancia de Singleton.
    Singleton() : value(0) {}

public:
    // Destructor.
    ~Singleton();

    // Método estático para obtener la instancia. Este método garantiza que solo exista una instancia de Singleton. Si la instancia ya existe, la devuelve. Si no existe, la crea y luego la devuelve.
    static Singleton* getInstance() {
        if (instance != nullptr) {
            return instance;
        }
        else {
            instance = new Singleton;
            return instance;
        }
    }

    // Método para establecer el valor. Este método permite modificar el valor almacenado en la instancia.
    void setValue(int _value) {
        value = _value;
    }

    // Método para obtener el valor. Este método permite acceder al valor almacenado en la instancia.
    int getValue() {
        return value;
    }

private:
    static Singleton* instance; // Puntero a la instancia. Este puntero almacena la única instancia de Singleton.
};

