//
//
#include "Door.h"
#include "Room.h"

#include <sstream>
using namespace std;

#if !defined(_ENCHANTEDDOOR_H)
#define _ENCHANTEDDOOR_H



class EnchantedDoor : public Door {
public:
	EnchantedDoor();
	EnchantedDoor(Room* f, Room* s);
	~EnchantedDoor();
	void getAtributos(vector< pair< string, string > >& vectorValores) override;

	void enter() override;
};

EnchantedDoor::EnchantedDoor() {
	MapSite::setType("puerta encantada");
}

EnchantedDoor::EnchantedDoor(Room* f, Room* s){
	Door::setRooms(f, s);
	MapSite::setType("puerta encantada");
}

EnchantedDoor::~EnchantedDoor() {
}

void EnchantedDoor::enter()
{
	cout << "agente pasa por " << MapSite::getType() << endl;
}

void EnchantedDoor::getAtributos(vector< pair< string, string > >& vectorValores) {
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

#endif  //_ENCHANTEDDOOR_H
