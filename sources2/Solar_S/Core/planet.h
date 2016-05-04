#ifndef PLANET_H
#define PLANET_H

using namespace std;

#include "timehoursseconds.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <float.h>

// класс, содеражищий в себе информацию о планете и методы, отвечающие за ее движение
// является родителем класса каждой планеты солнечной системы

class Planet
{
    const double G = 6.67 * pow(10,-11);
    const double SunMass = 1.989 * pow(10,30);
    const double EarthMass = 5.973 * pow(10,24);
    const double LenghtFromEarthToMoon = 384400000;
    const double Pi = 3.1415;
    string name;
    double LenghtToSun;
    double theta;
    double radius;
    double p; //параметры эллипса
    double e; //параметры эллипса
    double radiusA; //параметры эллипса
    double radiusB; //параметры эллипса
    double mass;
public:
    //TODO добавить noexcept для всех функций, не генерирующих исключений

    Planet();

    //TODO переименовть переменные
    //передавать string по значению неэффективно. лучше по ссылке на константный объект.

    //TODO заменить передачу string name по значению передачей по ссылке на константу.
    //если аргументы функции не будут изменяться внутри функции, то есть не переданы по ссылке, то лучше передавать их как const.

    //пользовательские типы и std контейнеры - как ссылку на конст. а встроенные int и т.д - const значение
    //TODO добавить const к аргументам функций, где только возможно.

    Planet(string name, double mass, double radiusA, double e, double radius, double theta);
    /**
     * @brief gravitationalForce
     * @return
     */
    double gravitationalForce() const;
    /**
     * @brief angularVelocity
     * @return
     */
    double angularVelocity()const;
    /**
     * @brief velocity
     * @return
     */
    double velocity() const;
    /**
     * @brief sunDistance
     * @return
     */
    double sunDistance() const;
    /**
     * @brief periodAroundSun
     * @return
     */
    Time periodAroundSun() const;

    //Все функции снизу ответственны за взаимодействие с пользователем. В ядре им НЕ МЕСТО!!!
    //По фаулеру надо move method.
    //TODO переместить функции взаимодействия с пользователем из ядра в приложение

    void step(double delta);
    /**
     * @brief printStaticParameters
     * @param out
     */
    void printStaticParameters (ostream& out);
    /**
     * @brief printDynamicParameters
     * @param out
     */
    void printDynamicParameters (ostream& out);
    /**
     * @brief printShortInfo
     * @param out
     */
    void printShortInfo (ostream& out);
    /**
     * @brief printDelta
     * @param out
     * @param delta
     */
    void printDelta(ostream& out, int delta);


    friend ostream& operator << (ostream& out, const Planet& planet); // перегрузка оператора вывода в поток
};

#endif // PLANET_H
