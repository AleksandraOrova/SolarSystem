#ifndef STAR_H
#define STAR_H

#include "spaceobject.h"

class Star : public SpaceObject
{
    public:
        Star();
        Star(const std::string & name, double mass,
             double rad, const Coordinates & position);
        std::string toString() const;
};

#endif
