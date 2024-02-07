#include "Doble.h"
Doble::Doble() {
  this->valor = 0;
}

Doble::Doble(double d) : valor(d) { }

Doble::~Doble() { }

string Doble::toString() {
  return to_string(this->valor);
}

Doble& Doble::operator+(Operando& otro ) {
  Doble * doble = dynamic_cast<Doble*>(&otro);
  Doble * result = new Doble(this->valor + doble->valor);
  return *result;

}

Doble& Doble::operator-(Operando& otro ) {
  Doble * doble = dynamic_cast<Doble*>(&otro);
  Doble * result = new Doble(this->valor - doble->valor);
  return *result;
}

Doble& Doble::operator*(Operando& otro) {
  Doble * doble = dynamic_cast<Doble*>(&otro);
  Doble * result = new Doble(this->valor * doble->valor);
  return * result;
}

Doble& Doble::operator/(Operando& otro) {
  Doble * doble = dynamic_cast<Doble*>(&otro);
  Doble * result = new Doble(this->valor / doble->valor);
  return * result;
}

