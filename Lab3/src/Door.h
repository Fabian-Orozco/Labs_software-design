#include "Room.h"

#ifndef DOOR_H
#define	DOOR_H

class Door : public MapSite {
public:
    Door(Room* = 0, Room* = 0);
    Door(const Door& orig);
    virtual ~Door();
    Room* getFirstRoom();
    Room* getSecondRoom();
    Room* OtherSideFrom(Room*);
    void setRooms(Room* f, Room* s);
    bool isOpen();
private:
    Room* _room1;
    Room* _room2;
    bool _isOpen;
};

Door::Door(Room* f, Room* s): _room1(s), _room2(f) {
}

Door::Door(const Door& orig) {

}

void Door::setRooms(Room* f, Room* s) {
    this->_room1 = f;
    this->_room2 = s;
}

Room* Door::getFirstRoom() {
    return _room1;
}

Room* Door::getSecondRoom() {
    return _room2;
}

bool Door::isOpen() {
    return _isOpen;
}

Door::~Door() {
}

Room* Door::OtherSideFrom(Room* r) {
    Room* rsl = 0;
    if (r == _room1)
        rsl = _room2;
    else rsl = _room1;
    return rsl;
}

#endif	/* DOOR_H */

