#include "planet.h"

Planet::Planet()
{

}
Planet::Planet(char* name, float startX, float startY, float startZ, float mass)
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
    info->setPosition(age, age, age);//тут должны быть функции изменения координат
}
char* Planet::toString()
{
    return 0;
}
