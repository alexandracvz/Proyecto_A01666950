#ifndef GUERRERO_HPP
#define GUERRERO_HPP

#include "Personaje.hpp"

class Guerrero : public Personaje {

private:
    int fuerza;

public:

    Guerrero();
    Guerrero(int vida,int ataque,int nivel,int fuerza);

    int calculaAtaque(Personaje& objetivo) override;

    void recibeAtaque(int ptosAtaque);

    void imprimir() override;
};

#endif