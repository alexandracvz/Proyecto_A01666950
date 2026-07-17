#include "Personaje.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

Personaje::Personaje() {

    vida = 100;
    salud = 100;
    ataque = 20;
    nivel = 1;

}
Personaje::Personaje(int vida, int ataque, int nivel) {

    this->vida = vida;
    salud = vida;
    this->ataque = ataque;
    this->nivel = nivel;

}


int Personaje::getVida() {
    return vida;
}

int Personaje::getSalud() {
    return salud;
}

int Personaje::getAtaque() {
    return ataque;
}

int Personaje::getNivel() {
    return nivel;
}
void Personaje::setVida(int vida) {
    this->vida = vida;
}

void Personaje::setSalud(int salud) {
    this->salud = salud;
}

void Personaje::setAtaque(int ataque) {
    this->ataque = ataque;
}

void Personaje::setNivel(int nivel) {
    this->nivel = nivel;
}

int Personaje::porcentajeSalud() {

    return (salud * 100) / vida;

}

//barras

void Personaje::imprimeBarra() {

    int porcentaje = porcentajeSalud();

    int llenos = porcentaje / 5;

    for(int i = 0; i < llenos; i++) {

        cout << "#";

    }

    for(int i = llenos; i < 20; i++) {

        cout << "-";

    }

}

// ataque 

void Personaje::recibeAtaque(int ptosAtaque) {

    salud = salud - ptosAtaque;

    if(salud < 0) {

        salud = 0;

    }

}

//calcular atque

int Personaje::calculaAtaque(Personaje& objetivo) {

    int mitad = ataque / 2;

    if(objetivo.getNivel() > nivel) {

        return 1 + rand() % mitad;

    }

    return mitad + rand() % (ataque - mitad + 1);

}
//ataque a otro personaje

void Personaje::atacar(Personaje& objetivo) {

    int dano = calculaAtaque(objetivo);

    objetivo.recibeAtaque(dano);

}

void Personaje::imprimir() {

    cout << "Vida maxima: " << vida << endl;
    cout << "Salud actual: " << salud << endl;
    cout << "Ataque: " << ataque << endl;
    cout << "Nivel: " << nivel << endl;

    cout << "Salud: ";
    imprimeBarra();
    cout << " (" << porcentajeSalud() << "%)" << endl;

}

ostream& operator<<(ostream& os, Personaje& p) {
    p.imprimir();
    return os;
}