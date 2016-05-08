#ifndef PLANET_H
#define PLANET_H

using namespace std;

#include "timehoursseconds.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <float.h>

/**
 * @brief класс, содеражищий в себе информацию о планете и методы, отвечающие за ее движение
 * является родителем класса каждой планеты солнечной системы
 */

class Planet
{
    constexpr static double G = 6.67 * pow(10,-11) ;
    constexpr static double SunMass = 1.989 * pow(10,30);
    constexpr static double EarthMass = 5.973 * pow(10,24);
    constexpr static double LenghtFromEarthToMoon = 384400000;
    constexpr static double Pi = 3.1415;
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

    Planet();
    Planet(Planet& planet);

    Planet(const string& name, const double mass, const double radiusA, const double e, const double radius, const double theta);
    /**
     * @brief Вычисление силы тяжести на планете
     */
    double gravitationalForce() const;

    /**
     * @brief Вывод угловой скорости движения планеты
     * @return
     */
    double angularVelocity() const;

    /**
     * @brief Вывод линейной скорости движения планеты
     * @return
     */
    double velocity() const;

    /**
     * @brief Вывод расстояния от планеты до Солнца
     * @return
     */
    double sunDistance() const;

    /**
     * @brief Вывод периода обращения вокруг Солнца
     */
    Time periodAroundSun() const;

    /**
     * @brief Сдвиг планеты на дельту по времени
     * @param delta
     */
    void step(const double delta);

    /**
     * @brief Вывод статических параметров планеты
     * @param out
     */
    void printStaticParameters (ostream& out) const;

    /**
     * @brief Вывод динамических параметров планеты
     * @param out
     */
    void printDynamicParameters (ostream& out) const;

    /**
     * @brief Вывод информации о планете в строчку
     * @param out
     */
    void printShortInfo (ostream& out) const;

    /**
     * @brief Вывод состояния планеты через дельту времени
     * @param out
     * @param delta
     */
    void printDelta(ostream& out, const int delta);


    friend ostream& operator << (ostream& out, const Planet& planet); // перегрузка оператора вывода в поток
};

#endif // PLANET_H
