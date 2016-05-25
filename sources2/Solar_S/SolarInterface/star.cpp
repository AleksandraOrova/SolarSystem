#include "star.h"
//#include "Functions.h"

Star::Star()
    : SpaceObject()
{}

Star::Star(const std::string & name, double mass,
           double rad, const Coordinates & position)
    : SpaceObject(name, mass, rad, position)
{}

std::string Star::toString() const
{
    std::string str =
        "Star: " + this->getName() +
        "\nMass: " + doubleToString(this->getMass()) +
        "\nRadius: " + doubleToString(this->getRad()) +
        "\nCoordinates: (" + doubleToString(this->getPosition().getX()) +
        "," + doubleToString(this->getPosition().getY()) + ")" ;
    return str;
}
