#include "Monstruos.h"  /* Agente / string / typeinfo*/
using namespace std;

int Monstruos::getCurrentID() {
    return this->id;
}

string Monstruos::pertenencia() {
    string tipo = string(typeid(*this).name());
    tipo = tipo.substr(1,tipo.length());
    return tipo;
}