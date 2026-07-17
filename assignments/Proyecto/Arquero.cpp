#include "Arquero.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

Arquero::Arquero() : Personaje() {

    precision = 30;

}

Arquero::Arquero(int vida, int ataque, int nivel, int precision)
: Personaje(vida, ataque, nivel) {

    this->precision = precision;

}

int Arquero::calculaAtaque(Personaje& objetivo) {

    int dano = Personaje::calculaAtaque(objetivo);

    int probabilidad = rand() % 100;

    if(probabilidad < precision){

        dano = dano + dano / 2;

    }

    return dano;

}

void Arquero::recibeAtaque(int ptosAtaque) {

    Personaje::recibeAtaque(ptosAtaque);

    if (getVida() <=0) {
        setVida(0);
        revive();
    }

}

void Arquero::imprimir() {

    Personaje::imprimir();

    cout << "Precision: " << precision << "%" << endl;

}