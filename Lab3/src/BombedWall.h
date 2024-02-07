#include <sstream>
using namespace std;

#include "Wall.h"

#if !defined(_BOMBEDWALL_H)
#define _BOMBEDWALL_H

class BombedWall : public Wall {
public:
	BombedWall();
	~BombedWall();
	virtual void getAtributos(vector< pair< string, string > >& vectorValores) override;

	void enter() override;
};

BombedWall::BombedWall() {
	MapSite::setType("pared con bomba");
}

BombedWall::~BombedWall() {

}

void BombedWall::enter()
{
	cout << "agente choca con " << MapSite::getType() << endl;
}

void BombedWall::getAtributos(vector< pair< string, string > >& vectorValores) {
	vectorValores.push_back( pair< string, string >("type", this->getType()));
	vectorValores.push_back( pair< string, string >("id", to_string(this->getId())));
}

#endif  //_BOMBEDWALL_H
