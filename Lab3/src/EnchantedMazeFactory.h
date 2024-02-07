#include "Maze.h"
#include "MazeFactory.h"
#include "EnchantedDoor.h"
#include "EnchantedRoom.h"
#include "EnchantedWall.h"


#if !defined(_ENCHANTEDMAZEFACTORY_H)
#define _ENCHANTEDMAZEFACTORY_H

class EnchantedMazeFactory : public MazeFactory {
public:
	Maze* createMaze();
	Wall* createWall();
	Door* createDoor(Room* r1, Room* r2);
	Room* createRoom();
};

Maze* EnchantedMazeFactory::createMaze() {
	return new Maze();
}

Wall* EnchantedMazeFactory::createWall() {
	return new EnchantedWall();
}

Door* EnchantedMazeFactory::createDoor(Room* r1, Room* r2) {
	return new EnchantedDoor(r1, r2);
}

Room* EnchantedMazeFactory::createRoom() {
	return new EnchantedRoom();
}

#endif  //_ENCHANTEDMAZEFACTORY_H
