#include "solarsystem.h"

SolarSystem::SolarSystem(){
    planetsCount = 0;
    planets = 0;
}

SolarSystem::SolarSystem(int count){
    planetsCount = count;
    planets = new Planet[count];
}

void SolarSystem::addPlanet(const Planet& planet, int id) const{
    if (id>=planetsCount)
        return;
    planets[id] = planet;
}

void SolarSystem::step(double delta) const{
    for(int i = 0; i <planetsCount; i++)
    {
        planets[i].step(delta);
    }
}
Planet& SolarSystem::getPlanet(int id) const{
    return planets[id-1];
}

bool SolarSystem::idValid(int id) const{
    return (id > 0 && id <=planetsCount);
}

ostream& operator << (ostream& out, const SolarSystem& solarSystem){
    if (&solarSystem==NULL){
        out << "NULL";
        return out;
    }
    out << "\n";
    for(int i = 0; i<solarSystem.planetsCount; i++)
        out << solarSystem.planets[i] << "\n";
    return out;
}
