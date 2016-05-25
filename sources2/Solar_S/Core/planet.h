#ifndef PLANET_H
#define PLANET_H


#include "timehoursseconds.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <float.h>

/**
 * @brief класс, содержащий в себе информацию о планете и методы, отвечающие за ее движение
 * является родителем класса каждой планеты солнечной системы
 */

class Planet
{
    static constexpr double G = 6.67 * pow(10,-11) ;
    static constexpr double SunMass = 1.989 * pow(10,30);
    static constexpr double Pi = 3.1415;
    std::string name;
    double LenghtToSun;
    double theta;
    double radius;
    double p; //параметры эллипса
    double e; //параметры эллипса
    double radiusA; //параметры эллипса
    double mass;
public:

    Planet(){}

    Planet(Planet& planet);

    Planet(const std::string& name, const double mass, const double radiusA, const double e, const double radius, const double theta);

    /**
     * @brief Возвращает силу тяжести на планете
     */
    double gravitationalForce() const{ return (G * (mass*SunMass)/pow(LenghtToSun,2)); }

    /**
     * @brief Возвращает угловую скорость движения планеты
     */
    double angularVelocity() const { return sqrt(gravitationalForce()/(mass*LenghtToSun)); }

    /**
     * @brief Возвращает линейную скорость движения планеты
     */

    double linearVelocity() const { return (angularVelocity() * LenghtToSun); }
    /**
     * @brief Возвращает расстояние от планеты до Солнца
     */
    double sunDistance() const { return(p/(1-e*cos(theta)))/1000; }

    /**
     * @brief Возвращает период обращения вокруг Солнца
     */
    Time periodAroundSun() const { return Time(2*Pi/angularVelocity(),0,0,0); }

    /**
     * @brief Сдвиг планеты на дельту по времени
     * @param delta время, на которое нужно сдвинуть планету
     */
    void step(const double delta) { theta += delta*angularVelocity(); }

    /**
     * @brief Вывод статических параметров планеты
     * @param out поток для вывода
     */
    void printStaticParameters (std::ostream& out) const;

    /**
     * @brief Вывод динамических параметров планеты
     * @param out поток для вывода
     */
    void printDynamicParameters (std::ostream& out) const;

    /**
     * @brief Вывод информации о планете в строчку
     * @param out поток для вывода
     */
    void printShortInfo (std::ostream& out) const;

    /**
     * @brief Вывод состояния планеты через дельту времени
     * @param out поток для вывода
     * @param delta прошедшее время
     */
    void printDelta(std::ostream& out, const int delta);

    /**
     * @brief Устанавливает время движения планеты
     * @param time время в секундах прошедшее с начала движения планеты
     */
    void setLifeTime(double time){theta = time*angularVelocity();}


    /**
     * @brief Перегрузка оператора вывода в поток
     */
    friend std::ostream& operator << (std::ostream& out, const Planet& planet);
    double getX() { return sunDistance()*cos(theta);}
    double getY() { return sunDistance()*sin(theta);}
};

#endif // PLANET_H
