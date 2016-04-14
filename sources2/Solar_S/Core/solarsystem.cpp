#include "solarsystem.h"

SolarSystem::SolarSystem(){
    planetsCount = 0;
    planets = 0;
}

SolarSystem::SolarSystem(int count){
    planetsCount = count;
    planets = new Planet*[count];
}

void SolarSystem::step(float delta){
}

void SolarSystem::addPlanet(Planet* planet, int id){
    if (id>=planetsCount)
        return;
    planets[id] = planet;
}

/*
void SolarSystem::movePlanet()
while t < seconds:
    rate(50);
    for plan in range(len(planets)):
        planetsf[plan].pos = rotate(planetsf[plan].pos,angle=planets[plan].varAngularPosition(t,dt.s),axis=(0,0,1));
    v = rotate(v,angle=moon.varAngularPosition(t,dt.s,m2=2),axis=(0,0,1));
    mo.pos = ea.pos + v;
    t += dt.s;
*/

ostream& operator << (ostream& out, const SolarSystem& solarSystem){
    if (&solarSystem==NULL){
        out << "NULL";
        return out;
    }
    out << "{\n";
    for(int i = 0; i<solarSystem.planetsCount; i++)
        out << "\t" << *solarSystem.planets[i] << "\n";
    out << "}";
    return out;
}
