#include "planets.h"

PlanetS::PlanetS(const std::string & name, const std::string & color, double mass,
               double rad, double speed, const Coordinates & position)
    : SpaceObject(name, mass, rad, position), start_t(0)
{
    this->color = color;
    this->speed = speed;
}

void PlanetS::setColor(const std::string & color)
{
    this->color = color;
}

void PlanetS::setSpeed(double speed)
{
    this->speed = speed;
}

void PlanetS::setOrbit(double orbit)
{
    this->orbit = orbit;
}

std::string PlanetS::getColor() const
{
    return color;
}

double PlanetS::getSpeed() const
{
    return speed;
}

double PlanetS::getOrbit() const
{
    return orbit;
}

double PlanetS::getStartTime() const
{
    return start_t;
}

void PlanetS::setStartTime(double start_t)
{
    this->start_t = start_t;
}

std::string PlanetS::toString() const
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
