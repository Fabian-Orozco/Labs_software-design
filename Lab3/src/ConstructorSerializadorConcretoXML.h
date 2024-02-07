#ifndef SERIALIZADOR_XML_H
#define SERIALIZADOR_XML_H

#include "ConstructorSerializadorAbstracto.h"

class ConstructorSerializadorXML : public ConstructorSerializadorAbstracto {
public:
	ConstructorSerializadorXML();
	~ConstructorSerializadorXML();

	/* SERIALIZADORES */
	virtual void inicioObjeto(string nombreObjeto) override;
	virtual void finObjeto() override;

	virtual void serializarRoom(Room* room) override;
  void serializarLado(MapSite::Direction direction, Room* room);
	virtual void serializarDoor(Door* door ) override;
	virtual void serializarWall(Wall* wall) override;

	virtual string obtSerializacion() override;

private:
	string serializacion; // el producto del Constructor
	string nombreObjeto;
};

ConstructorSerializadorXML::ConstructorSerializadorXML() : serializacion("") , nombreObjeto("")
{}

ConstructorSerializadorXML::~ConstructorSerializadorXML()
{}

void ConstructorSerializadorXML::inicioObjeto(string nombreObjeto) {
	serializacion = serializacion + '<' + nombreObjeto + '>';
  this->nombreObjeto = nombreObjeto;
}

void ConstructorSerializadorXML::finObjeto() {
	serializacion += "\n</" + this->nombreObjeto + '>';
}

void ConstructorSerializadorXML::serializarRoom(Room* room) {

	serializacion = serializacion + "\n\t<Room";
	serializacion = serializacion + " type" + '=' + '\"' + room->getType() + '\"';
	serializacion = serializacion + " id" + '=' + '\"' + to_string(room->getId()) + '\"' + ">\n";
	this->serializarLado(MapSite::Direction::North, room);
  this->serializarLado(MapSite::Direction::South, room);
  this->serializarLado(MapSite::Direction::East, room);
  this->serializarLado(MapSite::Direction::West, room);
	serializacion = serializacion + "\n\t</Room>";
}

void ConstructorSerializadorXML::serializarLado(MapSite::Direction direction, Room* room) {
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

void ConstructorSerializadorXML::serializarDoor(Door* door) {
  vector<pair<string, string >> atributos;
  door->getAtributos(atributos);
  vector<pair<string, string >>::iterator it = atributos.begin();
  serializacion += "\t\t<Door ";
  while(it != atributos.end()){
    serializacion += it->first + "=\"" + it->second + "\"";
    it++;
    if(it != atributos.end()){
      serializacion += ", ";
    }
  }
  serializacion += "</Door>\n";
}

void ConstructorSerializadorXML::serializarWall(Wall* wall) {
  vector<pair<string, string >> atributos;
  wall->getAtributos(atributos);
  vector<pair<string, string >>::iterator it = atributos.begin();
  serializacion += "\t\t<Wall ";
  while(it != atributos.end()){
    serializacion += it->first + "=\"" + it->second + "\"";
    it++;
    if(it != atributos.end()){
      serializacion += ", ";
    }
  }
  serializacion += "</Wall>\n";
}

string ConstructorSerializadorXML::obtSerializacion() {
	return serializacion;
}


#endif  // SERIALIZADOR_XML_H
