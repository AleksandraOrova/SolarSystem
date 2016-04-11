#include "planetinfo.h"

PlanetInfo::PlanetInfo()
{
    name = new char[1];
    strcpy(name, "0");
    coords = new Vector3();
}

PlanetInfo::PlanetInfo(char* name, float x, float y, float z, float mass)
{
    name = new char[strlen(name)];
    strcpy(name, name);
    coords = new Vector3(x, y, z);
    setMass(mass);
}
void PlanetInfo::setPosition(float x, float y, float z)
{
    coords->setPosition(x, y ,z);
}
void PlanetInfo::setMass(float mass)
{
    this->mass = mass;
}
char* PlanetInfo::toString()
{
    return 0;
}
