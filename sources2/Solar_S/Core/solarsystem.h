#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include "planet.h"
#include <iostream>
using namespace std;

// класс, хранящий в себе массив планет Солнечной системы
//Документировать доксидженом http://www.stack.nl/~dimitri/doxygen/manual/docblocks.html
class SolarSystem
{
    //Поменять местами private и public. см класс Time....
private:
    int planetsCount;
    Planet** planets;
public:
//TODO добавить noexcept в функции, не генерирующие исключения
//TODO добавить const к аргументам функций, где только возможно.
    SolarSystem(); // конструктор по умолчанию
    SolarSystem(int count); // конструктор с параметром
    //Step вроде переводится как шаг. Не вижу связи с описанием метода. Лучше изменить его название так, чтобы комментарий был не нужен.
    void step(double delta); // метод, который обновляет время жизни планеты, прибовляя к возрасту каждой константу (течение времени)
    //Лучше передать объект planet как ссылку на const Planet.
    //TODO заменить передачу указателя на передачу ссылки на const.
    void addPlanet(Planet* planet, int id); // добавляет планету в солнечную систему
    //TODO добавить const
    //В c++ появились ссылки, которых нет в с.
    //В данном методе разумно будет возвращать ссылку на объект, а не указатель.
    //TODO заменить указатель ссылкой
    Planet* getPlanet(int id);
    //TODO добавить const
    bool idValid(int id);


    friend ostream& operator << (ostream& out, const SolarSystem& solarSystem); //перегрузка оператора вывода в поток
};

#endif // SOLARSYSTEM_H
