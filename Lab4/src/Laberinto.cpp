#include "Laberinto.h"
#include <stdlib.h>
#include <time.h>

Laberinto::Laberinto(int size){
  nodos.reserve(10);
  for( int i = 0; i < 10; ++i )
    nodos.push_back(new Nodo());
}

Nodo * Laberinto::siguienteMoviento(){
  srand (time(NULL));
  return nodos[(rand() % nodos.size())];
}
