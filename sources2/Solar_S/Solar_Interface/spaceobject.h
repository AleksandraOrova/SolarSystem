#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H

#include "coordinates.h"
#include "functions.h"
#include <sstream>
#include <iostream>

class SpaceObject
{
    protected:
        std::string name;
        double mass, rad;
        Coordinates position;

    public:

        SpaceObject();
        SpaceObject(const std::string & name, double mass,
                    double rad, const Coordinates & position);

        void setName (const std::string & name);
        void setMass (double mass);
        void setRad (double rad);
        void setPosition(const Coordinates & position);
        void setPositionX(double x);
        void setPositionY(double y);

        std::string getName() const;
        double getMass() const;
        double getRad() const;
        Coordinates getPosition() const;
};

#endif
