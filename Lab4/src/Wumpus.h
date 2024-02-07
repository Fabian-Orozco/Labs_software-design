#ifndef WUMPUS_H
#define WUMPUS_H

#include <iostream>
#include "Monstruo.h"

using namespace std;

class Wumpus: public Monstruo {

    public:
        Wumpus(int id = 0, MM * manada = nullptr);
        int atacar(Agente * agente);
        string toString();
};
#endif  // WUMPUS_H