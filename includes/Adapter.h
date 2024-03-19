#pragma once
#include "Preriquisites.h"

// Clase que representa una interfaz vieja. Esta clase define la interfaz que se quiere adaptar.
class InterfazVieja {
public:
    // Método de la interfaz vieja. Este método representa una operación que se quiere adaptar a la nueva interfaz.
    virtual void MetodoViejo() {
        cout << "Metodo Viejo llamado." << endl;
    }
};

// Clase que representa una interfaz nueva (objetivo). Esta clase define la interfaz a la que se quiere adaptar la interfaz vieja.
class InterfazNueva {
public:
    // Método de la interfaz nueva. Este método representa la operación a la que se quiere adaptar el método de la interfaz vieja.
    virtual void MetodoNuevo() {
        cout << "Metodo Nuevo llamado." << endl;
    }
};

// Adaptador que conecta la interfaz vieja con la nueva. Esta clase implementa la interfaz nueva y adapta la interfaz vieja a ella.
class Adapter : public InterfazNueva {
public:
    // Constructor que toma una interfaz vieja como parámetro. Este constructor permite adaptar una instancia de la interfaz vieja a la interfaz nueva.
    Adapter(InterfazVieja* vieja) : m_interfazVieja(vieja) {}

    // Implementación del método de la interfaz nueva. Este método adapta el método de la interfaz vieja a la interfaz nueva.
    void MetodoNuevo() override {
        cout << "Adaptador llamado al metodo nuevo" << endl;
        m_interfazVieja->MetodoViejo();
    }

private:
    InterfazVieja* m_interfazVieja; // Almacena una instancia de la interfaz vieja que se quiere adaptar.
};
