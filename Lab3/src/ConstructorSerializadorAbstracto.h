#ifndef SERIALIZADOR_ABSTRACTO_H
#define SERIALIZADOR_ABSTRACTO_H

#include <string>

#include "Room.h"
#include "Door.h"
#include "Wall.h"

using namespace std;

class ConstructorSerializadorAbstracto {
public:
	ConstructorSerializadorAbstracto() {};
	~ConstructorSerializadorAbstracto() {};

	/* SERIALIZADORES */
	virtual void inicioObjeto(string nombreObjeto) = 0;
	virtual void finObjeto() = 0;
	virtual void serializarRoom(Room* room) = 0;
	virtual void serializarDoor(Door* door ) = 0;
	virtual void serializarWall(Wall* wall) = 0;
	virtual string obtSerializacion() = 0;
};


#endif  // SERIALIZADOR_ABSTRACTO_H