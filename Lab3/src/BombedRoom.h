#include "Room.h"

#if !defined(_BOMBEDROOM_H)
#define _BOMBEDROOM_H

class BombedRoom : public Room {
public:
	BombedRoom();
	~BombedRoom();

	void enter() override;
};

BombedRoom::BombedRoom() {
	MapSite::setType("sala con bomba");
	cout << "Entra al constructor de " << MapSite::getType() << endl;
}

BombedRoom::~BombedRoom() {

}

void BombedRoom::enter()
{
	cout << "agente entra a " << MapSite::getType() << endl;
}
#endif  //_BOMBEDROOM_H
