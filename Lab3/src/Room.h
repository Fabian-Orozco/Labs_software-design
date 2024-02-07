#include <sstream>
using namespace std;

#include "MapSite.h"

#ifndef ROOM_H
#define	ROOM_H

class Room : public MapSite {
public:
    Room();
    Room(const Room& orig);
    virtual ~Room();
    
    MapSite* GetSide(Direction) const;
    void SetSide(Direction, MapSite*);
    virtual string toString() override;

private:
    MapSite* _sides[4];
};

Room::Room() {
    for (int i = 0; i < 4; i++)
        _sides[i] = 0;
}

Room::Room(const Room& orig) {
}

Room::~Room() {
    cout << "Entra al destructor de cuartos" << endl;
}

MapSite* Room::GetSide(Direction d) const {
    return _sides[d];
}

void Room::SetSide(Direction d, MapSite* ms) {
    _sides[d] = ms;
}

string Room::toString() {
    ostringstream s;
    s << MapSite::toString();
    for (int i = 0; i < 4; i++) {
        s << _sides[i]->toString() << endl;
    }
    return s.str();
}
#endif	/* ROOM_H */

