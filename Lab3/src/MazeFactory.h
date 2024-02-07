#include "Maze.h"
#include "Wall.h"
#include "Door.h"
#include "Room.h"

#if !defined(_MAZEFACTORY_H)
#define _MAZEFACTORY_H


class MazeFactory {
public:
	virtual Maze* createMaze() = 0;
	virtual Wall* createWall() = 0;
	virtual Door* createDoor(Room* r1, Room* r2) = 0;
	virtual Room* createRoom() = 0;
};

#endif  //_MAZEFACTORY_H
