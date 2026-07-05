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