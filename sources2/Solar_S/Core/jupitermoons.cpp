#include "jupitermoons.h"

JupiterMoons::JupiterMoons(){
    planetsCount = 0;
    planets = 0;
}

JupiterMoons::JupiterMoons(int count){
    moonsCount = count;
    moons = new Moons[count];
}

void JupiterMoons::addMoon(const Moon& moon, int id) const noexcept{
    if (id>=moonsCount)
        return;
    moons[id] = moon;
}

void JupiterMoons::step(double delta) const noexcept{
    for(int i = 0; i <moonsCount; i++)
    {
        moons[i].step(delta);
    }
}
Planet& JupiterMoons::getPlanet(int id) const noexcept{
    return moons[id-1];
}

bool JupiterMoons::idValid(int id) const noexcept{
    return (id > 0 && id <=moonsCount);
}

ostream& operator << (ostream& out, const JupiterMoons& jupiterMoons){
    if (&jupiterMoons==NULL){
        out << "NULL";
        return out;
    }
    out << "\n";
    for(int i = 0; i<jupiterMoons.moonsCount; i++)
        out << jupiterMoons.moons[i] << "\n";
    return out;
}
