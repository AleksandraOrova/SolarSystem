#include "planets.h"
//#include "Functions.hpp"

Planet::Planet(const std::string & name, const std::string & color, double mass,
               double rad, double speed, const Coordinates & position)
    : SpaceObject(name, mass, rad, position), start_t(0)
{
    this->color = color;
    this->speed = speed;
}

void Planet::setColor(const std::string & color)
{
    this->color = color;
}

void Planet::setSpeed(double speed)
{
    this->speed = speed;
}

void Planet::setOrbit(double orbit)
{
    this->orbit = orbit;
}

std::string Planet::getColor() const
{
    return color;
}

double Planet::getSpeed() const
{
    return speed;
}

double Planet::getOrbit() const
{
    return orbit;
}

double Planet::getStartTime() const
{
    return start_t;
}

void Planet::setStartTime(double start_t)
{
    this->start_t = start_t;
}

std::string Planet::toString() const
{
    std::string str =
        "Planet: " + this->getName() +
        "\nColor: " + this->getColor() +
        "\nMass: " + doubleToString(this->getMass()) +
        "\nRadius: " + doubleToString(this->getRad()) +
        "\nSpeed: " + doubleToString(this->getSpeed()) +
        "\nCoordinates: (" + doubleToString(this->getPosition().getX()) + "," + doubleToString(this->getPosition().getY()) + ")" ;
    return str;
}
