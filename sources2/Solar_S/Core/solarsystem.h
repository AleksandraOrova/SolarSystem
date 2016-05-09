#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include "simulator_api.h"
#include "planet.h"
#include <iostream>
using namespace std;

/**
 * @brief класс, хранящий в себе массив планет Солнечной системы
 */

class SolarSystem : public simulator_api

{

public:

//TODO добавить noexcept в функции, не генерирующие исключения
//TODO добавить const к аргументам функций, где только возможно.

    /**
     * @brief конструктор по умолчанию
     */
    SolarSystem();

    /**
     * @brief конструктор с параметрами
     * @param count
     */
    SolarSystem(int count);

    /**
     * @brief сдвиг
     * @param время для сдвига
     */
    void step(double delta) const; // noexcept

    /**
     * @brief добавить планету в список
     * @param планета
     * @param номер планеты
     */
    void addPlanet(const Planet& planet, int id) const; // noexcept

    //TODO добавить const
    //В c++ появились ссылки, которых нет в с.
    //В данном методе разумно будет возвращать ссылку на объект, а не указатель.
    //TODO заменить указатель ссылкой

    /**
     * @brief Получение планеты из смассива планет
     * @param id
     * @return
     */
    Planet& getPlanet(int id) const;// noexcept

    /**
     * @brief Проверка на адекватность номера планеты
     * @param Номер планеты для проверки
     * @return
     */
    bool idValid(int id) const; // noexcept
private:
    /**
     * @brief Количество планет в системе
     */
    int planetsCount;

    /**
     * @brief Массив со всеми планетами в системе
     */
    Planet* planets;

    /**
     * @brief перегрузка оператора вывода в поток <<
     * @param out поток вывода
     * @param solarSystem
     * @return
     */
    friend ostream& operator << (ostream& out, const SolarSystem& solarSystem);
};

#endif // SOLARSYSTEM_H
