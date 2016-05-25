#include "coordinates.h"

Coordinates::Coordinates() : x0(0), y0(0)
{

}

Coordinates::Coordinates(double x, double y) : x0(x), y0(y)
{

}

void Coordinates::setX(double x)
{
    x0 = x;
}

void Coordinates::setY(double y)
{
    y0 = y;
}

double Coordinates::getX() const
{
    return x0;
}

double Coordinates::getY() const
{
    return y0;
}

Coordinates & Coordinates::operator = (const Coordinates & that)
{
    x0 = that.x0;
    y0 = that.y0;
    return *this;
}
