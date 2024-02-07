#include <sstream>
using namespace std;

#include "Door.h"

#if !defined(_BOMBEDDOOR_H)
#define _BOMBEDDOOR_H

class BombedDoor : public Door {
public:
	BombedDoor();
	BombedDoor(Room* f, Room* s);
	~BombedDoor();
	void getAtributos(vector< pair< string, string > >& vectorValores) override;

	void enter() override;

private:

};

int MapSite::idg = 0;

BombedDoor::BombedDoor()
{
	MapSite::setType("puerta con bomba");
}

BombedDoor::~BombedDoor()
{
}

BombedDoor::BombedDoor(Room* f, Room* s){
	Door::setRooms(f, s);
	MapSite::setType("puerta con bomba");
}

void BombedDoor::enter()
{
	cout << "agente pasa por " << MapSite::getType() << endl;
}


void BombedDoor::getAtributos(vector< pair< string, string > >& vectorValores) {
	vectorValores.push_back( pair< string, string >("type", this->getType()));
	vectorValores.push_back( pair< string, string >("id", to_string(this->getId())));
	vectorValores.push_back( pair< string, string >("is_Open", to_string(this->isOpen())));
	if (this->getFirstRoom()) {
		vectorValores.push_back( pair< string, string >("Room1", to_string(this->getFirstRoom()->getId())));
	} else {
		vectorValores.push_back( pair< string, string >("Room1", "Null"));
	}
	if (this->getSecondRoom()) {
		vectorValores.push_back( pair< string, string >("Room2", to_string(this->getSecondRoom()->getId())));
	} else {
		vectorValores.push_back( pair< string, string >("Room2", "Null"));
	}
}

#endif  //_BOMBEDDOOR_H
