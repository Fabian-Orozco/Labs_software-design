#ifndef CADEJO_H
#define CADEJO_H
#include <iostream>
#include "Monstruo.h"
using namespace std;


class Cadejo: public Monstruo {
    public:
        Cadejo(int id = 0, MM * manada = nullptr);
        int atacar(Agente * agente);
        string toString();
};
#endif  // CADEJO_H