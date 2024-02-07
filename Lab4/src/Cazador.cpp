#include "Cazador.h"
#include <stdlib.h>
#include <time.h>

Cazador::Cazador(){
  this->vida = 100;
  this->monstruosCazados = 0;
}
void Cazador::atraparMonstruo(Monstruos * monstruos){
  monstruos->setAtrapado();
  ++this->monstruosCazados;
  cout << "Cazador atrapa al " << monstruos->pertenencia() <<  " {" << monstruos->getCurrentID() << "}" << endl;
}

bool Cazador::estaMuerto(){
  return this->vida < 1;
}

string Cazador::toString() {

  string respuesta = "El cazador esta ";
  respuesta += (this->estaMuerto()) ? "muerto " : "vivo ";
  respuesta += "con " + to_string(this->vida) + " de vida";
  return respuesta;
}

int Cazador::getMonstruosCazados() {
  return this->monstruosCazados;
}