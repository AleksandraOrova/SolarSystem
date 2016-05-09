#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include "simulator_api.h"
#include "planet.h"
#include <iostream>

// todo ...
using namespace std;

/**
 * @brief класс, хранящий в себе массив планет Солнечной системы
 */
// todo исправить замечания, написанные после TODO (с прошлого ревью) =)
// todo указывать слово override для перекрывающих функций
class SolarSystem : public simulator_api

{

public:

//TODO добавить noexcept в функции, не генерирующие исключения
//TODO добавить const к аргументам функций, где только возможно.
    // вы же добавили const. Можно стереть TODO

    /**
     * @brief конструктор по умолчанию
     */
    SolarSystem();

    /**
     * @brief конструктор с параметрами
     * @param count
     */
    // todo добавить слово explicit к такому конструктору. Вы же не хотите, чтобы люди писали, например
    // "SolarSystem my_system = 4;" ?
    SolarSystem(int count);

    // todo можно убрать эти комментарии, они есть в родительском классе. Но там нужно сделать их нормальными
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
     * @brief Получение планеты из массива планет
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
    // todo чем вам так вектор не нравится? почему именно массив?
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
