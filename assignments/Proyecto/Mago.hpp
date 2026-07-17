#ifndef MAGO_HPP
#define MAGO_HPP

#include "Personaje.hpp"

class Mago : public Personaje {

private:
    int mana;

public:

    Mago();
    Mago(int vida, int ataque, int nivel, int mana);

    int calculaAtaque(Personaje& objetivo) override;

    void recibeAtaque(int ptosAtaque);

    void revive() override;

    void imprimir() override;

};

#endif