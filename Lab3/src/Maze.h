#include <vector>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

#include "Room.h"
#include "Door.h"
#include "Wall.h"

#ifndef MAZE_H
#define	MAZE_H

class Maze {
public:
    Maze();
    Maze(const Maze& orig);
    virtual ~Maze();
    
    void AddRoom(Room*);
    Room* RoomNo(int) const;

    vector<Room*> & getAtributtes();
    string toString();
private:
    vector< Room* > rooms;
};

Maze::Maze() {
}

Maze::Maze(const Maze& orig) {
}

Maze::~Maze() {
}

void Maze::AddRoom(Room* nr) {
    rooms.push_back(nr);
}

Room* Maze::RoomNo(int rn) const {
    Room* pr = 0;
    for (auto pr : rooms) {
        if (pr->getId() == rn)
            break;
    }
    return pr;
}

string Maze::toString()
{
    ostringstream s;
    for (auto rp : rooms) 
        s << rp->toString() << endl;

    return s.str();
}

vector<Room*> & Maze::getAtributtes() {
    return this->rooms;
}

#endif	/* MAZE_H */

