#include <iostream>
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"
#include <vector>

using namespace std;

int main() {

    // Vector de apuntadores a Personaje
    vector<Personaje*> personajes;

    // Crear los personajes 
    personajes.push_back(new Guerrero(120,25,3,30));
    personajes.push_back(new Arquero(100,22,2,40));
    personajes.push_back(new Mago(90,28,3,100));

    //imprimir los personajes
    cout << "===== PERSONAJES =====" << endl;

    for (Personaje* p : personajes) {

        p->imprimir();
        cout << endl;

    }

    // Peleas
    cout << "\nMAGO ATACA AL GUERRERO\n";

    personajes[2]->atacar(*personajes[0]);

    personajes[0]->imprimir();


    cout << "\nGUERRERO ATACA AL ARQUERO\n";

    personajes[0]->atacar(*personajes[1]);

    personajes[1]->imprimir();


    cout << "\nARQUERO ATACA AL MAGO\n";

    personajes[2]->setSalud(5);   // <--fuerza salud baja para probar revive

    personajes[1]->atacar(*personajes[2]);

    personajes[2]->imprimir();

    //Parte de la prueba
    cout << "\nARQUERO REMATA AL MAGO OTRA VEZ\n";

    personajes[2]->setSalud(5);
    personajes[1]->atacar(*personajes[2]);

    personajes[2]->imprimir();

    cout << "\nGUERRERO REMATA AL MAGO DEFINITIVAMENTE\n";

    personajes[2]->setSalud(5);
    personajes[0]->atacar(*personajes[2]);

    personajes[2]->imprimir();

    //termina la prueba de revive


    cout << "\nGUERRERO ATACA AL MAGO\n";

    personajes[0]->atacar(*personajes[2]);

    personajes[2]->imprimir();


    cout << "\nARQUERO ATACA AL GUERRERO\n";

    personajes[1]->atacar(*personajes[0]);

    personajes[0]->imprimir();


    cout << "\nMAGO ATACA AL ARQUERO\n";

    personajes[2]->atacar(*personajes[1]);

    personajes[1]->imprimir();

    cout << "\n===== PRUEBA DE OPERADOR<< =====\n";
    cout << *personajes[0];

    // Liberar memoria
    for (Personaje* p : personajes) {

        delete p;

    }

    return 0;
}