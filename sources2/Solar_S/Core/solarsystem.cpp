#include "solarsystem.h"
// Я тут немного расставил пробелы перед знаками математических и логических операций,
// было тяжело читать. Если вам не нравится, уберите их.

// todo использовать список инициализации
// SolarSystem::SolarSystem():
//  planetsCount(0),
//  planets(0)
// {}
// todo planets все-таки указатель, инициализируйте nullptr'ом
SolarSystem::SolarSystem(){
    planetsCount = 0;
    planets = 0;
}

SolarSystem::SolarSystem(int count){
    planetsCount = count;
    planets = new Planet[count];
}

void SolarSystem::addPlanet(const Planet& planet, int id) const{
    if (id >= planetsCount)
    // todo может быть, бросать исключение здесь. Все-таки пользователь думает, что добавилось,
    //  а мы не говорим даже, что нет.
        return;
    planets[id] = planet;
}

void SolarSystem::step(double delta) const{
    for (int i = 0; i < planetsCount; i++)
    {
        planets[i].step(delta);
    }
}
Planet& SolarSystem::getPlanet(int id) const{
    return planets[id - 1];
}

bool SolarSystem::idValid(int id) const{
    return (id > 0 && id <= planetsCount);
}

ostream& operator << (ostream& out, const SolarSystem& solarSystem){
    if (&solarSystem == NULL){
        out << "NULL";
        return out;
    }
    out << "\n";
    for (int i = 0; i < solarSystem.planetsCount; i++)
        out << solarSystem.planets[i] << "\n";
    return out;
}
