#ifndef PLANET_H
#define PLANET_H

#include "planetinfo.h"

// класс, содеражищий в себе информацию о планете и методы, отвечающие за ее движение
// является родителем класса каждой планеты солнечной системы

class Planet
{
    PlanetInfo* info;
    float age;
public:
    Planet(); // конструктор по умолчанию
    Planet(char* name, float startX, float startY, float startZ, float mass); // конструктор с параметрами
    void step(float delta); // метод, увеличивающий время жизни планеты и перещитывающий ее координаты
    void setAge(float age); // устанавливает возраст планеты
    void setInfo(PlanetInfo* info); // устанавливает информацию планете
    char* toString(); // конвертирует планету в строку
};

#endif // PLANET_H
