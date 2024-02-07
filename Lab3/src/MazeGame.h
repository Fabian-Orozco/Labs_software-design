#include <sstream>
#include <random>
#include <vector>

using namespace std;

#include "Maze.h"
#include "MazeFactory.h"
#ifndef MAZEGAME_H
#define	MAZEGAME_H

class MazeGame {
public:
    MazeGame();
    MazeGame(const MazeGame& orig);
    virtual ~MazeGame();
    
    Maze* createMaze(MazeFactory*);
    string toString();
    Maze * getAtributtes();
private:
    Maze* aMaze;
	void fillRoom(Room* room, Door* d1, Door* d2, int entrance, int exit, MazeFactory* f);
	int findEntrance(int exit);
};


MazeGame::MazeGame(): aMaze(0) {
}

MazeGame::MazeGame(const MazeGame& orig) {
}

MazeGame::~MazeGame() {
}

Maze* MazeGame::createMaze(MazeFactory* f) {
	aMaze = f->createMaze();
	vector<Room*> rooms;
	vector<Door*> doors;
	
	// Se crean los cuartos
	for (int i = 0; i < 7; ++i){
		rooms.push_back(f->createRoom());
    }
	
	// Se crean las puertas
	doors.push_back(f->createDoor(rooms[6], rooms[0]));
	for (int i = 0; i < 6; ++i){
		doors.push_back(f->createDoor(rooms[i], rooms[(i+1)]));
    }
	doors.push_back(f->createDoor(rooms[6], rooms[0]));
	
	// Se unen las puertas con los cuartos y se crean los walls
	int entrance = rand() % 4;
	int exit = 0;
	for (int i = 0; i < 7; ++i){
		exit = (entrance + rand() % 3 + 1) % 4;
		fillRoom(rooms[i], doors[i], doors[(i+1)], entrance, exit, f);
		aMaze->AddRoom(rooms[i]);
		entrance = findEntrance(exit);
    }
    
    return aMaze;
}

string MazeGame::toString()
{
    ostringstream s;
    s << aMaze->toString();
    return s.str();
}

void MazeGame::fillRoom(Room* room, Door* d1, Door* d2, int entrance, int exit, MazeFactory* f){
	for (int i = 0; i < 4; ++i){
		
		if (entrance == i){
			room->SetSide(static_cast<MapSite::Direction>(i), d1);
		}else if (exit == i){
			room->SetSide(static_cast<MapSite::Direction>(i), d2);
		}else{
			room->SetSide(static_cast<MapSite::Direction>(i), f->createWall());
		}
	}
}

int MazeGame::findEntrance(int exit){
	switch(exit) {
		case 0:
			return 1;
			break;
			
		case 1:
			return 0;
			break;
			
		case 2:
			return 3;
			break;
			
		case 3:
			return 2;
			break;
	}
	return 0;
}

Maze * MazeGame::getAtributtes() {
    return aMaze;
}
#endif	/* MAZEGAME_H */

