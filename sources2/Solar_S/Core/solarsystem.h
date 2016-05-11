#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include "simulator_api.h"
#include "planet.h"
#include <iostream>

/**
 * @brief класс, хранящий в себе массив планет Солнечной системы
 */

class SolarSystem : public Simulator_api

{

public:
    /**
     * @brief конструктор по умолчанию
     */
    SolarSystem(): planetsCount(0), planets(nullptr){}

    /**
     * @brief деструктор
     */
    ~SolarSystem();

    /**
     * @brief конструктор с параметрами
     * @param count
     */
    explicit SolarSystem(int count): planetsCount(count), planets(new Planet[count]){}

    void step(double delta) const noexcept override final;

    void addPlanet(const Planet& planet, int id) const noexcept override final;

    Planet& getPlanet(int id) const noexcept override final;

    bool idValid(int id) const noexcept override final;
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
    friend std::ostream& operator << (std::ostream& out, const SolarSystem& solarSystem);
};

#endif // SOLARSYSTEM_H
