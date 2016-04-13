#ifndef PLANET_H
#define PLANET_H

#include "timehoursseconds.h"
#include <iostream>
#include <math.h>
#include <float.h>

using namespace std;
// класс, содеражищий в себе информацию о планете и методы, отвечающие за ее движение
// является родителем класса каждой планеты солнечной системы

class Planet
{
    const float G = 6.67 * pow(10,-11);
    const float sunM = 1.989 * pow(10,30);
    const float eaM = 5.973 * pow(10,24);
    const float RTL = 384400000;
    string name;
    float RS;
    float theta;
    float radius;
    float mass;
public:
    Planet(); // конструктор по умолчанию
    Planet(string name, float mass, float RS, float radius, float theta); // конструктор с параметрами
    float gravitationalForce() const;
    float angularVelocity()const;
    float velocity() const;
    float angularPosition(float t) const;
    float varAngularPosition(float t, float dt) const;
    TimeHoursSeconds periodAroundSun() const;


    friend ostream& operator << (ostream& out, const Planet& planet); // перегрузка оператора вывода в поток
};

#endif // PLANET_H
