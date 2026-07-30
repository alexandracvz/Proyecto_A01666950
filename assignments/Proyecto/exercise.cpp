#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

#include "Personaje.hpp"
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"

using namespace std;

// Excepcion personalizada para errores relacionados con los archivos
class ErrorArchivo : public runtime_error {
public:
    ErrorArchivo(const string& mensaje)
        : runtime_error(mensaje) {}
};

// Carga los personajes de un archivo y los agrega al ejercito
void cargarEjercito(vector<Personaje*>& ejercito, const string& nombreArchivo) {

    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        throw ErrorArchivo("No se pudo abrir el archivo: " + nombreArchivo);
    }

    string tipo;
    int vida;
    int ataque;
    int nivel;
    int atributoEspecial;

    while (archivo >> tipo >> vida >> ataque >> nivel >> atributoEspecial) {

        if (tipo == "Guerrero") {

            ejercito.push_back(
                new Guerrero(vida, ataque, nivel, atributoEspecial)
            );

        }
        else if (tipo == "Arquero") {

            ejercito.push_back(
                new Arquero(vida, ataque, nivel, atributoEspecial)
            );

        }
        else if (tipo == "Mago") {

            ejercito.push_back(
                new Mago(vida, ataque, nivel, atributoEspecial)
            );

        }
        else {

            throw ErrorArchivo(
                "Tipo de combatiente desconocido en el archivo: " + tipo
            );
        }
    }

    archivo.close();

    if (ejercito.empty()) {
        throw ErrorArchivo(
            "El archivo " + nombreArchivo +
            " no contiene combatientes."
        );
    }
}

// Muestra todos los integrantes de un ejercito
void mostrarEjercito(const vector<Personaje*>& ejercito,
                     const string& nombreEjercito) {

    cout << "\n========================================\n";
    cout << "             " << nombreEjercito << "\n";
    cout << "========================================\n";

    for (int i = 0; i < ejercito.size(); i++) {

        cout << "\n----- Combatiente " << i + 1 << " -----\n";

        ejercito[i]->imprimir();
    }
}

// Obtiene el tipo de personaje usando polimorfismo
string obtenerTipo(Personaje* personaje) {

    if (dynamic_cast<Guerrero*>(personaje) != nullptr) {
        return "Guerrero";
    }

    if (dynamic_cast<Arquero*>(personaje) != nullptr) {
        return "Arquero";
    }

    if (dynamic_cast<Mago*>(personaje) != nullptr) {
        return "Mago";
    }

    return "Personaje";
}

// Realiza la batalla entre los dos ejercitos
void batalla(vector<Personaje*>& ejercito1,
             vector<Personaje*>& ejercito2) {

    int indice1 = 0;
    int indice2 = 0;

    cout << "\n\n========================================\n";
    cout << "           COMIENZA LA BATALLA\n";
    cout << "========================================\n";

    // Cada combatiente se enfrenta al combatiente actual
    // del ejercito contrario hasta que uno sea derrotado.
    while (indice1 < ejercito1.size() &&
           indice2 < ejercito2.size()) {

        Personaje* combatiente1 = ejercito1[indice1];
        Personaje* combatiente2 = ejercito2[indice2];

        cout << "\n\n***************************************\n";
        cout << "             NUEVO COMBATE\n";
        cout << "***************************************\n";

        cout << "\nEjercito 1: "
             << obtenerTipo(combatiente1) << endl;

        cout << "Ejercito 2: "
             << obtenerTipo(combatiente2) << endl;

        cout << "\n----- ESTADO INICIAL -----\n";

        cout << "\nEjercito 1:\n";
        combatiente1->imprimir();

        cout << "\nEjercito 2:\n";
        combatiente2->imprimir();

        // Los dos personajes se atacan por turnos
        // hasta que uno sea derrotado.
        while (combatiente1->getSalud() > 0 &&
               combatiente2->getSalud() > 0) {

            // Turno del Ejercito 1
            int dano = combatiente1->calculaAtaque(*combatiente2);

            cout << "\n----------------------------------------\n";
            cout << obtenerTipo(combatiente1)
                 << " del Ejercito 1 ataca a "
                 << obtenerTipo(combatiente2)
                 << " del Ejercito 2.\n";

            cout << "Daño realizado: "
                 << dano << endl;

            combatiente2->recibeAtaque(dano);

            cout << "Salud actual de "
                 << obtenerTipo(combatiente2)
                 << ": "
                 << combatiente2->getSalud()
                 << endl;

            cout << "\nEstado actual:\n";
            combatiente2->imprimir();

            // Si el combatiente del Ejercito 2 sigue vivo,
            // realiza su ataque.
            if (combatiente2->getSalud() > 0) {

                dano = combatiente2->calculaAtaque(*combatiente1);

                cout << "\n----------------------------------------\n";
                cout << obtenerTipo(combatiente2)
                     << " del Ejercito 2 ataca a "
                     << obtenerTipo(combatiente1)
                     << " del Ejercito 1.\n";

                cout << "Daño realizado: "
                     << dano << endl;

                combatiente1->recibeAtaque(dano);

                cout << "Salud actual de "
                     << obtenerTipo(combatiente1)
                     << ": "
                     << combatiente1->getSalud()
                     << endl;

                cout << "\nEstado actual:\n";
                combatiente1->imprimir();
            }
        }

        // Si el primer combatiente fue derrotado,
        // avanza al siguiente personaje del Ejercito 1.
        if (combatiente1->getSalud() <= 0) {

            cout << "\n"
                 << obtenerTipo(combatiente1)
                 << " del Ejercito 1 ha sido derrotado.\n";

            indice1++;
        }

        // Si el segundo combatiente fue derrotado,
        // avanza al siguiente personaje del Ejercito 2.
        if (combatiente2->getSalud() <= 0) {

            cout << "\n"
                 << obtenerTipo(combatiente2)
                 << " del Ejercito 2 ha sido derrotado.\n";

            indice2++;
        }

        // Se muestra el ganador del combate individual.
        if (combatiente1->getSalud() > 0) {

            cout << "\n"
                 << obtenerTipo(combatiente1)
                 << " del Ejercito 1 gana este combate.\n";

        }
        else if (combatiente2->getSalud() > 0) {

            cout << "\n"
                 << obtenerTipo(combatiente2)
                 << " del Ejercito 2 gana este combate.\n";
        }
    }

    cout << "\n\n========================================\n";
    cout << "           BATALLA TERMINADA\n";
    cout << "========================================\n";

    // Determina cual ejercito se quedo sin combatientes.
    if (indice1 >= ejercito1.size()) {

        cout << "\nEL EJERCITO 2 ES EL GANADOR.\n";

        cout << "\nEl Ejercito 1 ha sido derrotado.\n";

        cout << "\nCombatientes sobrevivientes del Ejercito 2:\n";

        for (int i = indice2; i < ejercito2.size(); i++) {

            cout << "\n----- Sobreviviente -----\n";

            ejercito2[i]->imprimir();
        }

    }
    else {

        cout << "\nEL EJERCITO 1 ES EL GANADOR.\n";

        cout << "\nEl Ejercito 2 ha sido derrotado.\n";

        cout << "\nCombatientes sobrevivientes del Ejercito 1:\n";

        for (int i = indice1; i < ejercito1.size(); i++) {

            cout << "\n----- Sobreviviente -----\n";

            ejercito1[i]->imprimir();
        }
    }
}

// Libera la memoria reservada para los personajes
void liberarEjercito(vector<Personaje*>& ejercito) {

    for (Personaje* personaje : ejercito) {

        delete personaje;
    }

    ejercito.clear();
}


int main() {

    // Inicializa los numeros aleatorios utilizados
    // en los calculos de ataque.
    srand(time(nullptr));

    // Cada vector representa un ejercito.
    vector<Personaje*> ejercito1;
    vector<Personaje*> ejercito2;

    try {

        // Carga los integrantes de cada ejercito
        // desde sus respectivos archivos.
        cargarEjercito(ejercito1, "ejercito1.txt");
        cargarEjercito(ejercito2, "ejercito2.txt");

        // Muestra los ejercitos antes de comenzar
        // la simulacion de la batalla.
        mostrarEjercito(ejercito1, "EJERCITO 1");
        mostrarEjercito(ejercito2, "EJERCITO 2");

        // Inicia la batalla.
        batalla(ejercito1, ejercito2);

    }
    catch (const ErrorArchivo& e) {

        cerr << "\nERROR: "
             << e.what()
             << endl;
    }
    catch (const exception& e) {

        cerr << "\nERROR INESPERADO: "
             << e.what()
             << endl;
    }

    // Libera la memoria utilizada por los dos ejercitos.
    liberarEjercito(ejercito1);
    liberarEjercito(ejercito2);

    return 0;
} 