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

    // ===== PELEAS =====
    cout << "\n===== PELEAS =====\n";

    for (int i = 0; i < (int)personajes.size(); i++) {

        int objetivo = (i + 1) % personajes.size();

        cout << "\nPersonaje " << i << " ataca a personaje " << objetivo << "\n";

        personajes[i]->atacar(*personajes[objetivo]);

        personajes[objetivo]->imprimir();

    }

    // ===== prueba de revive() =====
    cout << "\n===== PRUEBA DE REVIVE (MAGO) =====\n";

    cout << "\nARQUERO ATACA AL MAGO\n";

    personajes[2]->setSalud(5);
    personajes[1]->atacar(*personajes[2]);

    personajes[2]->imprimir();

    cout << "\nARQUERO REMATA AL MAGO OTRA VEZ\n";

    personajes[2]->setSalud(5);
    personajes[1]->atacar(*personajes[2]);

    personajes[2]->imprimir();

    cout << "\nGUERRERO REMATA AL MAGO DEFINITIVAMENTE\n";

    personajes[2]->setSalud(5);
    personajes[0]->atacar(*personajes[2]);

    personajes[2]->imprimir();

    cout << "\nGUERRERO LE DA EL GOLPE FINAL AL MAGO\n";

    personajes[2]->setSalud(5);
    personajes[0]->atacar(*personajes[2]);

    personajes[2]->imprimir();

    // ===== PRUEBA DE OPERADOR<< =====
    cout << "\n===== PRUEBA DE OPERADOR<< =====\n";
    cout << *personajes[0];

    // Liberar memoria
    for (Personaje* p : personajes) {

        delete p;

    }

    return 0;
}