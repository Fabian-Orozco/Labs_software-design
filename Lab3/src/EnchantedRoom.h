#include "Room.h"

#if !defined(_ENCHANTEDROOM_H)
#define _ENCHANTEDROOM_H

class EnchantedRoom : public Room {
    public:
    EnchantedRoom();
    ~EnchantedRoom();

    void enter() override;
};

EnchantedRoom::EnchantedRoom() {
    MapSite::setType("sala encantada");
    cout << "Entra al constructor de " << MapSite::getType() << endl;
}

EnchantedRoom::~EnchantedRoom() {

}

void EnchantedRoom::enter()
{
    cout << "agente entra a " << MapSite::getType() << endl;
}
#endif  //_ENCHANTEDROOM_H
