#ifndef SIMULATOR_API_H
#define SIMULATOR_API_H

#include "planet.h"

// todo дописать noexcept для методов, не генерирующих исключение
// todo классы принято называть с заглавной буквы

class simulator_api{
public:
    // todo сделаете комментарий подробнее.
    // Для виртуальных методов достаточно указывать их только в родительком классе
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
    // todo в каком случае метод возвращает true, а в каком false?
    virtual bool idValid(int id) const = 0; // noexcept

    // todo в классе, от которого наследуются нужен виртуальный деструктор.
    // хотя бы ~Simulator_api() {}
};

#endif // SIMULATOR_API_H
