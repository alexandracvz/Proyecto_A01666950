#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP
#include <iostream>
using namespace std;

class Personaje {

private:
    int vida;
    int salud;
    int ataque;
    int nivel;

public:
    // Constructores
    Personaje();
    Personaje(int vida, int ataque, int nivel);

    virtual ~Personaje() {}

    // Getters
    int getVida();
    int getSalud();
    int getAtaque();
    int getNivel();

    // Setters
    void setVida(int vida);
    void setSalud(int salud);
    void setAtaque(int ataque);
    void setNivel(int nivel);

    // Métodos
    int porcentajeSalud();
    void imprimeBarra();
    virtual int calculaAtaque(Personaje& objetivo);
    virtual void recibeAtaque(int ptosAtaque);
    void atacar(Personaje& objetivo);
    virtual void revive() = 0;
    virtual void imprimir();

    int operator+(const Personaje& otro);

};

ostream& operator<<(ostream& os, Personaje& p);   

#endif
