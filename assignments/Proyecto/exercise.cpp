#include <iostream>
#include "Guerrero.hpp"
#include "Arquero.hpp"
#include "Mago.hpp"

using namespace std;

int main(){

    Guerrero guerrero(120,25,3,30);

    Arquero arquero(100,22,2,40);

    Mago mago(90,28,3,100);

    cout<<"===== GUERRERO ====="<<endl;
    guerrero.imprimir();

    cout<<"\n===== ARQUERO ====="<<endl;
    arquero.imprimir();

    cout<<"\n===== MAGO ====="<<endl;
    mago.imprimir();

    cout<<"\nMAGO ATACA AL GUERRERO\n";

    mago.atacar(guerrero);

    guerrero.imprimir();

    cout<<"\nGUERRERO ATACA AL ARQUERO\n";

    guerrero.atacar(arquero);

    arquero.imprimir();

    cout<<"\nARQUERO ATACA AL MAGO\n";

    arquero.atacar(mago);

    mago.imprimir();

}