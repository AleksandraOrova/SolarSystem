#include "solarsystem.h"

SolarSystem::~SolarSystem(){
    delete[] planets;
}

void SolarSystem::addPlanet(const Planet& planet, int id) const noexcept{
    if (!idValid(id))
        return;
    planets[id] = planet;
}

void SolarSystem::step(double delta) const noexcept{
    for (int i = 0; i < planetsCount; i++)
    {
        planets[i].step(delta);
    }
}

Planet& SolarSystem::getPlanet(int id) const noexcept{
    return planets[id - 1];
}

bool SolarSystem::idValid(int id) const noexcept{
    return (id >= 0 && id <= planetsCount);
}

std::ostream& operator << (std::ostream& out, const SolarSystem& solarSystem){
    if (&solarSystem == NULL){
        out << "NULL";
        return out;
    }
    out << "\n";
    for (int i = 0; i < solarSystem.planetsCount; i++)
        out << solarSystem.planets[i] << "\n";
    return out;
}
