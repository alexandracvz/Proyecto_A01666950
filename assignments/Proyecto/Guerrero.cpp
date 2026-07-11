#include "Guerrero.hpp"
#include <iostream>

using namespace std;

// Constructor por defecto
Guerrero::Guerrero() : Personaje() {
    fuerza = 20;
}

// Constructor con parámetros
Guerrero::Guerrero(int vida, int ataque, int nivel, int fuerza)
    : Personaje(vida, ataque, nivel) {
    this->fuerza = fuerza;
}

// Calcula el ataque
int Guerrero::calculaAtaque(Personaje& objetivo) {

    int dano = Personaje::calculaAtaque(objetivo);

    dano = dano + fuerza / 5;

    return dano;
}

// Recibe ataque
void Guerrero::recibeAtaque(int ptosAtaque) {

    ptosAtaque = ptosAtaque - fuerza / 10;

    if (ptosAtaque < 1) {
        ptosAtaque = 1;
    }

    Personaje::recibeAtaque(ptosAtaque);
}

// Imprime la información
void Guerrero::imprimir() {

    Personaje::imprimir();

    cout << "Fuerza: " << fuerza << endl;
}