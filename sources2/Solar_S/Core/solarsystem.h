#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include "simulator_api.h"
#include "planet.h"
#include <iostream>
using namespace std;

// класс, хранящий в себе массив планет Солнечной системы

class SolarSystem : public simulator_api

{

public:
//TODO добавить noexcept в функции, не генерирующие исключения
//TODO добавить const к аргументам функций, где только возможно.

    SolarSystem();
    SolarSystem(int count);
    void step(double delta);

    //Лучше передать объект planet как ссылку на const Planet.
    //TODO заменить передачу указателя на передачу ссылки на const.

    void addPlanet(const Planet& planet, int id);

    //TODO добавить const
    //В c++ появились ссылки, которых нет в с.
    //В данном методе разумно будет возвращать ссылку на объект, а не указатель.
    //TODO заменить указатель ссылкой

    Planet& getPlanet(int id);

    //TODO добавить const
    bool idValid(int id);
private:
    int planetsCount;
    Planet* planets;

    friend ostream& operator << (ostream& out, const SolarSystem& solarSystem); //перегрузка оператора вывода в поток
};

#endif // SOLARSYSTEM_H
