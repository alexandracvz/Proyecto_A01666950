#include <iostream>
#include "Personaje.hpp"

using namespace std;

int main() {

    Personaje personaje1(100, 20, 2);
    Personaje personaje2(120, 25, 3);

    cout << "===== PERSONAJE 1 =====" << endl;
    personaje1.imprimir();

    cout << endl;

    cout << "===== PERSONAJE 2 =====" << endl;
    personaje2.imprimir();

    cout << endl;

    cout << "El personaje 1 ataca al personaje 2." << endl;
    personaje1.atacar(personaje2);

    cout << endl;

    cout << "===== PERSONAJE 2 DESPUES DEL ATAQUE =====" << endl;
    personaje2.imprimir();

    return 0;
}