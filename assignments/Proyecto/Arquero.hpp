#ifndef ARQUERO_HPP
#define ARQUERO_HPP

#include "Personaje.hpp"

class Arquero : public Personaje {

private:
    int precision;

public:

    Arquero();
    Arquero(int vida, int ataque, int nivel, int precision);

    int calculaAtaque(Personaje& objetivo) override;

    void recibeAtaque(int ptosAtaque);

    void imprimir() override;

};

#endif