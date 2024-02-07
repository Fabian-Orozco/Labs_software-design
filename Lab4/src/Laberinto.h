#ifndef LABERINTO_H
#define LABERINTO_H

#include <vector>
#include "Nodo.h"

class Laberinto{
public:
  Laberinto(int size);
  Nodo * siguienteMoviento();

protected:
   std::vector<Nodo *> nodos;

};

#endif // LABERINTO_H
