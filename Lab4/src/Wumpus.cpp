#include "Wumpus.h"

Wumpus::Wumpus(int id, MM * manada) {
    this->id = id;
    this->manada = manada;
    this->danyo = 15;
}

int Wumpus::atacar(Agente * agente) {
    agente->setVida(agente->getVida() - this->danyo);
    return this->danyo;
}


string Wumpus::toString(){
    // id + tipo
    string respuesta = "Wumpus {" + std::to_string(this->getCurrentID()) + "}"; 
    // atrapado
    respuesta += (this->atrapado) ? " ya fue atrapado" : " sigue libre";
    // manada
    respuesta += (this->manada) ? 
    " y pertenece a la manada " + std::to_string(this->manada->getCurrentID())
    : " y no tiene manada";

    return respuesta;
}