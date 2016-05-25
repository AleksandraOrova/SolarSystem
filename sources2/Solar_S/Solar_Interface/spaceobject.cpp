#include <iostream>
#include <string>
#include <vector>
#include "spaceobject.h"
#include <cmath>
#include <typeinfo>

SpaceObject::SpaceObject()
{};

SpaceObject::SpaceObject(const std::string & name_, double mass_,
                         double rad_, const Coordinates & position_)
    : name(name_), mass(mass_), rad(rad_), position(position_)
{}

void SpaceObject::setName(const std::string & name)
{
    this->name = name;
}

void SpaceObject::setMass(double mass)
{
    this->mass = mass;
}

void SpaceObject::setRad(double rad)
{
    this->rad = rad;
}

void SpaceObject::setPosition(const Coordinates & position)
{
    this->position = position;
}

void SpaceObject::setPositionX(double x)
{
    position.setX(x);
}

void SpaceObject::setPositionY(double y)
{
    position.setY(y);
}

std::string SpaceObject::getName() const
{
    return name;
}

double SpaceObject::getMass() const
{
    return mass;
}

double SpaceObject::getRad() const
{
    return rad;
}

Coordinates SpaceObject::getPosition() const
{
    return position;
}
