#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#ifndef MAPSITE_H
#define	MAPSITE_H

class MapSite {
public:
    enum Direction {North, South, East, West};
    static int idg;
    
    MapSite();
    virtual ~MapSite();
    MapSite(const MapSite& orig);

    int getId();
    virtual void enter() = 0;
    virtual string toString();
    void setType(string nt);
    string getType();
    virtual void getAtributos(vector< pair< string, string > >& vectorValores);

private:
    int id;
    string type;
};

MapSite::MapSite(): id(idg) {
    idg++;
}

MapSite::MapSite(const MapSite& orig) {
}

MapSite::~MapSite() {
}

int MapSite::getId() {
    return id;
}

void MapSite::setType(string nt)
{
    type = nt;
}

string MapSite::getType() {
    return type;
}

string MapSite::toString()
{
    ostringstream s;
    s << MapSite::getType() << " # " << MapSite::getId() << endl;
    return s.str();
}

void MapSite::getAtributos(vector< pair< string, string > >& vectorValores) {
    vectorValores.push_back( pair< string, string >("id", to_string(this->id)));
    vectorValores.push_back( pair< string, string >("type", this->type));
}

#endif	/* MAPSITE_H */

