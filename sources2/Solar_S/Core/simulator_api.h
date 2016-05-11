#ifndef SIMULATOR_API_H
#define SIMULATOR_API_H

#include "planet.h"

class Simulator_api{
public:

    /**
     * @brief сдвиг планет в системе
     * @param delta время, на которое будут сдвинуты планеты в системе
     */
    virtual void step(double delta) const noexcept = 0;

    /**
     * @brief добавить планету в список
     * @param planet планета для добавления
     * @param id номер планеты в списке
     */
    virtual void addPlanet(const Planet& planet, int id) const noexcept = 0;

    /**
     * @brief возвращает планету из списка планет
     * @param номер планеты
     */
    virtual Planet& getPlanet(int id) const noexcept = 0;

    /**
     * @brief Проверка на адекватность номера планеты
     * @param Номер планеты для проверки
     * @return true - id планеты существует в данной системе false - планеты с таким номером в системе нет
     */
    virtual bool idValid(int id) const noexcept = 0;

    ~Simulator_api() {}
};

#endif // SIMULATOR_API_H
