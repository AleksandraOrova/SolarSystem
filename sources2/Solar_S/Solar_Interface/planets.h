#ifndef PLANETS_H
#define PLANETS_H

#include "spaceobject.h"

class PlanetS : public SpaceObject
{
    private:
        std::string color;
        double speed, orbit, start_t;

    public:
        PlanetS (const std::string & name, const std::string & color, double mass,
                double rad, double speed, const Coordinates & position);

        void setColor(const std::string & color);
        void setSpeed(double speed);
        void setOrbit(double orbit);
        void setStartTime(double start_t);

        std::string getColor() const;
        double getSpeed() const;
        double getOrbit() const;
        double getStartTime() const;

        std::string toString() const;
};

#endif
