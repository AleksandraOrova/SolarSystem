#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include "planet.h"
#include <iostream>
using namespace std;

// класс, хранящий в себе массив планет Солнечной системы

class SolarSystem
{
private:
    int planetsCount;
    Planet** planets;
public:
    SolarSystem(); // конструктор по умолчанию
    SolarSystem(int count); // конструктор с параметром
    void step(float delta); // метод, который обновляет время жизни планеты, прибовляя к возрасту каждой константу (течение времени)
    void addPlanet(Planet* planet, int id); // добавляет планету в солнечную систему
    void movePlanet();

    friend ostream& operator << (ostream& out, const SolarSystem& solarSystem); //перегрузка оператора вывода в поток
};

#endif // SOLARSYSTEM_H
