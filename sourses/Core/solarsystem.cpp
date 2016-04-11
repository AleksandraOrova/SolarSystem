#include "solarsystem.h"

SolarSystem::SolarSystem()
{
    planetsCount = 0;
    planets = 0;
}
SolarSystem::SolarSystem(int count)
{
    planetsCount = count;
    planets = new Planet[count];
}
void SolarSystem::step(float delta)
{
    for(int i = 0; i < planetsCount; i++)
        planets[i].step(delta);
}
char* SolarSystem::toString()
{
    return 0;
}
