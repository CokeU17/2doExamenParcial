#pragma once
#include "Preriquisites.h"

// Clase Juego que define el esqueleto de un juego.
// Esta es una clase abstracta que define los métodos comunes a todos los juegos.
class Juego {
public:
    // Metodo principal que define el flujo general del juego.
    // Este método llama a los métodos inicializar, comenzarJuego y terminarJuego en ese orden.
    void jugar() {
        inicializar();
        comenzarJuego();
        terminarJuego();
    }

protected:
    // Metodo inicializar, proporciona una implementacion predeterminada.
    // Este método se llama al principio del juego.
    virtual void inicializar() {
        cout << "Iniciando Juego." << endl;
    }

    // Metodo comenzarJuego, implementado por las subclases.
    // Este método es abstracto y debe ser implementado por las clases derivadas.
    virtual void comenzarJuego() = 0;

    // Metodo terminarJuego, proporciona una implementacion predeterminada.
    // Este método se llama al final del juego.
    virtual void terminarJuego() {
        cout << "Terminando el Juego." << endl;
    }
};

// Subclase Ajedrez que implementa el metodo comenzarJuego especificamente para el ajedrez.
// Esta clase hereda de la clase Juego y proporciona una implementación específica del método comenzarJuego.
class Ajedrez : public Juego {
protected:
    // Implementación del método comenzarJuego para el juego de Ajedrez.
    void comenzarJuego() override {
        cout << "Comenzar Partida de Ajedrez." << endl;
    }
};

// Subclase Monopoly que implementa el metodo comenzarJuego especificamente para el Monopoly.
// Esta clase hereda de la clase Juego y proporciona una implementación específica del método comenzarJuego.
class Monopoly : public Juego {
protected:
    // Implementación del método comenzarJuego para el juego de Monopoly.
    void comenzarJuego() override {
        cout << "Comenzar partida Monopoly." << endl;
    }
};

