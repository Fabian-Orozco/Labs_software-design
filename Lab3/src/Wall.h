#include "MapSite.h"

#ifndef WALL_H
#define	WALL_H

class Wall : public MapSite {
public:
    Wall();
    Wall(const Wall& orig);
    virtual ~Wall();
    
private:

};

Wall::Wall() {

}

Wall::Wall(const Wall& orig) {
}

Wall::~Wall() {
}

#endif	/* WALL_H */

