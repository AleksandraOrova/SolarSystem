#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include "planet.h"

// класс, хранящий в себе массив планет Солнечной системы

class SolarSystem
{
private:
    int planetsCount;
    Planet* planets;
public:
    SolarSystem(); // конструктор по умолчанию
    SolarSystem(int count); // конструктор с параметром
    void step(float delta); // метод, который обновляет время жизни планеты, прибовляя к возрасту каждой константу (течение времени)
    char* toString(); // конвертирование в строку
};

#endif // SOLARSYSTEM_H
