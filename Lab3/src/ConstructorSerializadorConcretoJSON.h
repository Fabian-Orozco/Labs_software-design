#ifndef SERIALIZADOR_JSON_H
#define SERIALIZADOR_JSON_H

#include "ConstructorSerializadorAbstracto.h"

class ConstructorSerializadorJSON : public ConstructorSerializadorAbstracto {
public:
	ConstructorSerializadorJSON();
	~ConstructorSerializadorJSON();

	/* SERIALIZADORES */
	virtual void inicioObjeto(string nombreObjeto) override;
	virtual void finObjeto() override;
	virtual void serializarRoom(Room* room) override;
  void serializarLado(MapSite::Direction direction, Room* room);
	virtual void serializarDoor(Door* door ) override;
	virtual void serializarWall(Wall* wall) override;
	virtual string obtSerializacion() override;

private:
	string serializacion; // producto del constructor
};


ConstructorSerializadorJSON::ConstructorSerializadorJSON()
{}


ConstructorSerializadorJSON::~ConstructorSerializadorJSON()
{}

void ConstructorSerializadorJSON::inicioObjeto(string nombreObjeto = "") {
	serializacion = "{";
  serializacion = serializacion + "\n\t" + "\"" + nombreObjeto + "\" :";
}


void ConstructorSerializadorJSON::finObjeto() {
	serializacion = serializacion + "\n}";
}

void ConstructorSerializadorJSON::serializarRoom(Room* room) {
  serializacion = serializacion + "\n\t{\n\t\t\"Room\" : \n\t\t{";
  serializacion = serializacion + " \n\t\t\t\"Type\" : \"" + room->getType() + "\",";
  serializacion = serializacion + " \n\t\t\t\"id\" :" + to_string(room->getId()) + ',';
  this->serializarLado(MapSite::Direction::North, room);
  this->serializarLado(MapSite::Direction::South, room);
  this->serializarLado(MapSite::Direction::East, room);
  this->serializarLado(MapSite::Direction::West, room);
  serializacion = serializacion + "\n\t\t}"; // finaliza el serializado de room
}

void ConstructorSerializadorJSON::serializarLado(MapSite::Direction direction, Room* room) {
  MapSite* side = room->GetSide(direction);

  // verifica si la sala tiene el lado.
  if (side) {
    // verifica si es una puerta
    Door* doorPtr = dynamic_cast<Door*>(side);
    if(doorPtr) {
      // serializa la puerta
      this->serializarDoor(doorPtr);
    } else {
        // verifica si es una pared
        Wall* wallPtr = dynamic_cast<Wall*>(side);
        if (wallPtr) {
          // serializa la pared
          this->serializarWall(wallPtr);
      }
    }
  }
  side = nullptr;
}

void ConstructorSerializadorJSON::serializarDoor(Door* door) {
  vector<pair<string, string >> atributos;
  door->getAtributos(atributos);
  vector<pair<string, string >>::iterator it = atributos.begin();
  serializacion += "\n\t\t\tDoor: {";
  while(it != atributos.end()){
    serializacion += it->first + ":\"" + it->second + "\"";
    it++;
    if(it != atributos.end()){
      serializacion += ", ";
    }
  }
  serializacion += "},";
}

void ConstructorSerializadorJSON::serializarWall(Wall* wall) {
  vector<pair<string, string >> atributos;
  wall->getAtributos(atributos);
  vector<pair<string, string >>::iterator it = atributos.begin();
  serializacion += "\n\t\t\tWall: {";
  while(it != atributos.end()){
    serializacion += it->first + ":\"" + it->second + "\"";
		it++;
		if(it != atributos.end()){
			serializacion += ", ";
		}
  }
  serializacion += "},";
}

string ConstructorSerializadorJSON::obtSerializacion() {
	return serializacion;
}



#endif  // SERIALIZADOR_JSON_H