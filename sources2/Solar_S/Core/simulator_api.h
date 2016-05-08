#ifndef SIMULATOR_API_H
#define SIMULATOR_API_H

#include"planet.h"

class simulator_api{
public:
    /**
     * @brief сдвиг
     * @param время для сдвига
     */
    virtual void step(double delta) const noexcept = 0;

    /**
     * @brief добавить планету в список
     * @param планета
     * @param номер планеты
     */
    virtual void addPlanet(const Planet& planet, int id) const noexcept = 0;

    /**
     * @brief получить планету из списка
     * @param номер планеты
     */
    virtual Planet& getPlanet(int id) const noexcept = 0;

    /**
     * @brief Проверка на адекватность номера планеты
     * @param Номер планеты для проверки
     * @return
     */
    virtual bool idValid(int id) const noexcept = 0;
};

#endif // SIMULATOR_API_H
