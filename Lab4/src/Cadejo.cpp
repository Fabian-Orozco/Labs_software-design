#include "Cadejo.h"

Cadejo::Cadejo(int id, MM * manada) {
    this->id = id;
    this->manada = manada;
    this->danyo = 10;
}

int Cadejo::atacar(Agente * agente) {
    agente->setVida(agente->getVida() - this->danyo);
    return this->danyo;
}


string Cadejo::toString(){
    // id + tipo
    string respuesta = "Cadejo {" + std::to_string(this->getCurrentID()) + "}"; 
    // atrapado
    respuesta += (this->atrapado) ? " ya fue atrapado" : " sigue libre";
    // manada
    respuesta += (this->manada) ? 
    " y pertenece a la manada " + std::to_string(this->manada->getCurrentID())
    : " y no tiene manada";

    return respuesta;
}