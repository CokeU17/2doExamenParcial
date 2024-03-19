#pragma once
#include "Preriquisites.h"

// Clase base del manejador (Handler). Esta clase define la interfaz que deben implementar los manejadores.
class Manejador {
public:
    // Constructor que recibe el siguiente manejador en la cadena. Este constructor permite establecer el siguiente manejador en la cadena de responsabilidad.
    Manejador(Manejador* siguiente) : m_siguienteManejador(siguiente) {}

    // Método virtual para manejar solicitudes. Cada manejador concreto debe implementar este método.
    virtual void manejarSolicitud(int solicitud) {
        // Si hay un siguiente manejador, pasa la solicitud a él
        if (m_siguienteManejador != nullptr) {
            m_siguienteManejador->manejarSolicitud(solicitud);
        }
    }

private:
    Manejador* m_siguienteManejador; // Almacena el siguiente manejador en la cadena de responsabilidad.
};

// Manejador Concreto A. Esta clase representa un manejador concreto en la cadena de responsabilidad.
class ManejadorConcretoA : public Manejador {
public:
    // Constructor que recibe el siguiente manejador en la cadena. Este constructor permite establecer el siguiente manejador en la cadena de responsabilidad.
    ManejadorConcretoA(Manejador* siguiente) : Manejador(siguiente) {}

    // Implementación específica para el Manejador A. Este método define cómo este manejador concreto maneja las solicitudes.
    void manejarSolicitud(int solicitud) override {
        // Maneja solicitudes si el valor es menor o igual a 10
        if (solicitud <= 10) {
            cout << "Manejador A ejecuta la solicitud." << endl;
        }
        else {
            // De lo contrario, pasa la solicitud al siguiente manejador
            Manejador::manejarSolicitud(solicitud);
        }
    }
};

// Manejador Concreto B. Esta clase representa otro manejador concreto en la cadena de responsabilidad.
class ManejadorConcretoB : public Manejador {
public:
    // Constructor que recibe el siguiente manejador en la cadena. Este constructor permite establecer el siguiente manejador en la cadena de responsabilidad.
    ManejadorConcretoB(Manejador* siguiente) : Manejador(siguiente) {}

    // Implementación específica para el Manejador B. Este método define cómo este manejador concreto maneja las solicitudes.
    void manejarSolicitud(int solicitud) override {
        // Maneja solicitudes en el rango de 11 a 20
        if (solicitud <= 20) {
            cout << "Manejador B ejecuta la solicitud." << endl;
        }
        else {
            // Pasa la solicitud al siguiente manejador si no la maneja
            Manejador::manejarSolicitud(solicitud);
        }
    }
};

// Manejador Concreto C. Esta clase representa otro manejador concreto en la cadena de responsabilidad.
class ManejadorConcretoC : public Manejador {
public:
    // Constructor que recibe el siguiente manejador en la cadena. Este constructor permite establecer el siguiente manejador en la cadena de responsabilidad.
    ManejadorConcretoC(Manejador* siguiente) : Manejador(siguiente) {}

    // Implementación específica para el Manejador C. Este método define cómo este manejador concreto maneja las solicitudes.
    void manejarSolicitud(int solicitud) override {
        // Maneja la solicitud sin verificar el valor
        cout << "Manejador C ejecuta la solicitud." << endl;
    }
};

