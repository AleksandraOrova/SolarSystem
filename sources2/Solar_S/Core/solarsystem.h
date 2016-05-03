#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include "simulator_api.h"
#include "planet.h"
#include <iostream>
using namespace std;

// класс, хранящий в себе массив планет Солнечной системы
class SolarSystem : public simulator_api
{
private:
    int planetsCount;
    Planet** planets;
public:
    SolarSystem(); // конструктор по умолчанию
    SolarSystem(int count); // конструктор с параметром
    void step(double delta); // метод, который обновляет время жизни планеты, прибовляя к возрасту каждой константу (течение времени)
    void addPlanet(Planet* planet, int id); // добавляет планету в солнечную систему
    Planet* getPlanet(int id);
    bool idValid(int id);


    friend ostream& operator << (ostream& out, const SolarSystem& solarSystem); //перегрузка оператора вывода в поток
};

#endif // SOLARSYSTEM_H
