#include "planet.h"

Planet::Planet()
{

}
Planet::Planet(string name, float startX, float startY, float startZ, float mass)
{
    info = new PlanetInfo(name, startX, startY, startZ, mass);
    age = 0;
}
void Planet::step(float delta)
{
    setAge(age + delta);
}
void Planet::setAge(float age)
{
    this->age = age;
    info->moveBy(age, age, age);//тут должны быть функции изменения координат
}

ostream& operator << (ostream& out, const Planet& planet){
    if (&planet==NULL){
        out << "NULL";
        return out;
    }
    out << *planet.info << " age:" << planet.age;
    return out;
}
