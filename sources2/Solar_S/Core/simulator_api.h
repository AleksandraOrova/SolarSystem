#ifndef SIMULATOR_API_H
#define SIMULATOR_API_H

#include"planet.h"

class simulator_api{
public:
    /**
     * @brief сдвиг
     * @param время для сдвига
     */
    virtual void step(double delta) const= 0; // noexcept

    /**
     * @brief добавить планету в список
     * @param планета
     * @param номер планеты
     */
    virtual void addPlanet(const Planet& planet, int id) const = 0; // noexcept

    /**
     * @brief получить планету из списка
     * @param номер планеты
     */
    virtual Planet& getPlanet(int id) const = 0; // noexcept

    /**
     * @brief Проверка на адекватность номера планеты
     * @param Номер планеты для проверки
     * @return
     */
    virtual bool idValid(int id) const = 0; // noexcept
};

#endif // SIMULATOR_API_H
