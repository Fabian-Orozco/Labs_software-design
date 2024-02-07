#include "Agente.h"

Agente::Agente(int vida, Nodo * nodo){
  this->vida = vida;
  this->nodoActual = nodo;
}

void Agente::moverse(Nodo * nuevaPosicion){
  this->nodoActual = nuevaPosicion;
}

int Agente::getVida(){
  return vida;
}

void Agente::setVida(int vida){
  this->vida = vida;
}
