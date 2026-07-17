#include "Mago.hpp"
#include <iostream>

using namespace std;

Mago::Mago() : Personaje() {

    mana = 100;

}

Mago::Mago(int vida, int ataque, int nivel, int mana)
: Personaje(vida, ataque, nivel) {

    this->mana = mana;

}

int Mago::calculaAtaque(Personaje& objetivo) {

    int dano = Personaje::calculaAtaque(objetivo);

    if(mana >= 20){

        dano = dano + 10;
        mana = mana - 20;

    }

    return dano;

}

void Mago::recibeAtaque(int ptosAtaque) {

    if(mana >= 80){

        ptosAtaque = ptosAtaque / 2;

    }
    else if(mana >= 50){

        ptosAtaque = ptosAtaque * 3 / 4;

    }

    Personaje::recibeAtaque(ptosAtaque);

    if (getSalud() <=0) {
        
        revive();
    }

}

void Mago::imprimir() {

    Personaje::imprimir();

    cout << "Mana: " << mana << endl;

}

void Mago::revive(){

    if(getVida() <= 0){

        if(mana >= 40){

            setVida(40);
            mana -= 40;

            cout << "Mago revivio usando su mana.\n";

        }
        else{

            cout << "Mago ha muerto.\n";

        }

    }

}