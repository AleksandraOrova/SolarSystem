#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include "planetinfo.h"
#include <string>

class SolarSystem
{
private:
    int planetsCount;
    PlanetInfo* planets;
public:
    SolarSystem();
    SolarSystem(int count);
    void step(float deltaTime);
    void setPlanetInfo(int id, PlanetInfo info);
    void readPlanetFromFile(int id, char* fileName);
    char* toString();
};

#endif // SOLARSYSTEM_H
