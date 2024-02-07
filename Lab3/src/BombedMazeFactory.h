#include "MazeFactory.h"
#include "BombedWall.h"
#include "BombedRoom.h"
#include "BombedDoor.h"

#if !defined(_BOMBEDMAZEFACTORY_H)
#define _BOMBEDMAZEFACTORY_H

class BombedMazeFactory : public MazeFactory {
public:
	Maze* createMaze();
	Wall* createWall();
	Door* createDoor(Room* r1, Room* r2);
	Room* createRoom();
};

Maze* BombedMazeFactory::createMaze() {
	Maze* m = new Maze();
	return m;
}

Wall* BombedMazeFactory::createWall() {
	return new BombedWall();
}

Door* BombedMazeFactory::createDoor(Room* r1, Room* r2) {
	return new BombedDoor(r1, r2);
}

Room* BombedMazeFactory::createRoom() {
	return new BombedRoom();
}
#endif  //_BOMBEDMAZEFACTORY_H
