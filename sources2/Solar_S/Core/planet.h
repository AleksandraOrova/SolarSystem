#ifndef PLANET_H
#define PLANET_H

#include "timehoursseconds.h"
#include <iostream>
#include <iomanip>
//В c++ используют хэдеры cmath, cfloat
//TODO заменить хэдеры
#include <math.h>
#include <float.h>

//Страуструп говорил, что нехорошо исползовать using namespace ...
//Причин несколько
//TODO убрать глобальное объявление using namespace
using namespace std;
// класс, содеражищий в себе информацию о планете и методы, отвечающие за ее движение
// является родителем класса каждой планеты солнечной системы

//TODO документировать доксидженом
class Planet
{
    //TODO поменять местами public и private. объяснение в timehoursseconds
    const double G = 6.67 * pow(10,-11);
    const double sunM = 1.989 * pow(10,30);//TODO не понятно название, если это физический термин так сокращенно обзепринято пишется, тогда ок
    const double eaM = 5.973 * pow(10,24);//TODO не понятно название, если это физический термин так сокращенно обзепринято пишется, тогда ок
    const double RTL = 384400000;//TODO не понятно название, если это физический термин так сокращенно обзепринято пишется, тогда ок
    string name;
    //По фаулеру, комментарий часто является дезодорантом, чтобы скрыть душок. Тут как раз так.
    //TODO переименовать переменную
    double RS; //расстояние до солнца
    double theta;
    double radius;
    //TODO аналогично, см выше
    double p; //параметры эллипса
    double e; //параметры эллипса
    double radiusA; //параметры эллипса
    double radiusB; //параметры эллипса
    double mass;
public:
    //TODO добавить noexcept для всех функций, не генерирующих исключений
    Planet(); // конструктор по умолчанию
    //TODO переименовть переменные
    //передавать string по значению неэффективно. лучше по ссылке на константный объект.
    //TODO заменить передачу string name по значению передачей по ссылке на константу.
    //если аргументы функции не будут изменяться внутри функции, то есть не переданы по ссылке, то лучше передавать их как const.
    //пользовательские типы и std контейнеры - как ссылку на конст. а встроенные int и т.д - const значение
    //TODO добавить const к аргументам функций, где только возможно.
    Planet(string name, double mass, double radiusA, double e, double radius, double theta); // конструктор с параметрами
    double gravitationalForce() const;
    double angularVelocity()const;
    double velocity() const;
    double angularPosition(double t) const; //TODO: удалить
    double varAngularPosition(double t, double dt) const;//TODO: удалить
    double sunDistance() const;
    TimeHoursSeconds periodAroundSun() const;
    //Все функции снизу ответственны за взаимодействие с пользователем. В ядре им НЕ МЕСТО!!!
    //По фаулеру надо move method.
    //TODO переместить функции взаимодействия с пользователем из ядра в приложение
    void step(double delta);
    void printStaticParameters (ostream& out);
    void printDynamicParameters (ostream& out);
    void printShortInfo (ostream& out);
    void printDelta(ostream& out, int delta);


    friend ostream& operator << (ostream& out, const Planet& planet); // перегрузка оператора вывода в поток
};

#endif // PLANET_H
