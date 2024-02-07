#include "Wall.h"

#if !defined(_ENCHANTEDWALL_H)
#define _ENCHANTEDWALL_H

class EnchantedWall : public Wall {
    public:
    EnchantedWall();
    ~EnchantedWall();
    virtual void getAtributos(vector< pair< string, string > >& vectorValores) override;

    void enter() override;
};

EnchantedWall::EnchantedWall() {
    MapSite::setType("pared encantada");
}

EnchantedWall::~EnchantedWall() {
}

void EnchantedWall::enter()
{
    cout << "agente choca con " << MapSite::getType() << endl;
}

void EnchantedWall::getAtributos(vector< pair< string, string > >& vectorValores) {
    vectorValores.push_back( pair< string, string >("type", this->getType()));
    vectorValores.push_back( pair< string, string >("id", to_string(this->getId())));
}
#endif  //_ENCHANTEDWALL_H
