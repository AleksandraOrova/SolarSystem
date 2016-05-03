#ifndef SIMULATOR_API_H
#define SIMULATOR_API_H

#include"planet.h"

class simulator_api{
public:
    virtual void step(double delta) = 0; // метод, который обновляет время жизни планеты, прибовляя к возрасту каждой константу (течение времени)
    virtual void addPlanet(Planet* planet, int id) = 0; // добавляет планету в солнечную систему
    virtual Planet* getPlanet(int id) = 0;
    virtual bool idValid(int id) = 0;

    };

#endif // SIMULATOR_API_H
