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

    void revive() override;

    void imprimir() override;

};

void Arquero::revive(){

    if(getVida() <= 0){

        if(precision >= 40){

            setVida(40);
            precision -= 40;

            cout << "El arquero revivio gracias a su precisión.\n";

        }
        else{

            cout << "El aruqero ha muerto.\n";

        }

    }

}

#endif