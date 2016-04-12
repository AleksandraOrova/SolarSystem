#include "planetinfo.h"

PlanetInfo::PlanetInfo()
{
    name = "";
    coords = new Vector3();
}

PlanetInfo::PlanetInfo(string name, float x, float y, float z, float mass)
{
    this->name = name;
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

void PlanetInfo::moveBy(float dx, float dy, float dz){
    coords->moveBy(dx, dy, dz);
}

ostream& operator << (ostream& out, const PlanetInfo& planetInfo)
{
    if (&planetInfo==NULL){
        out << "NULL";
        return out;
    }
    out << planetInfo.name << " (" << planetInfo.mass << ") " << *planetInfo.coords;
    return out;
}
