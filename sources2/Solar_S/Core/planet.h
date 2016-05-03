#ifndef PLANET_H
#define PLANET_H

#include "timehoursseconds.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <float.h>

using namespace std;
// класс, содеражищий в себе информацию о планете и методы, отвечающие за ее движение
// является родителем класса каждой планеты солнечной системы

class Planet
{
    const double G = 6.67 * pow(10,-11);
    const double sunM = 1.989 * pow(10,30);
    const double eaM = 5.973 * pow(10,24);
    const double RTL = 384400000;
    string name;
    double RS; //расстояние до солнца
    double theta;
    double radius;
    double p; //параметры эллипса
    double e; //параметры эллипса
    double radiusA; //параметры эллипса
    double radiusB; //параметры эллипса
    double mass;
public:
    Planet(); // конструктор по умолчанию
    Planet(string name, double mass, double radiusA, double e, double radius, double theta); // конструктор с параметрами
    double gravitationalForce() const;
    double angularVelocity()const;
    double velocity() const;
    double angularPosition(double t) const; //TODO: удалить
    double varAngularPosition(double t, double dt) const;//TODO: удалить
    double sunDistance() const;
    TimeHoursSeconds periodAroundSun() const;
    void step(double delta);
    void printStaticParameters (ostream& out);
    void printDynamicParameters (ostream& out);
    void printShortInfo (ostream& out);
    void printDelta(ostream& out, int delta);


    friend ostream& operator << (ostream& out, const Planet& planet); // перегрузка оператора вывода в поток
};

#endif // PLANET_H
