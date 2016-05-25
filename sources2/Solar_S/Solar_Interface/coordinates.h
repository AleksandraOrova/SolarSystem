#ifndef COORDINATES_H
#define COORDINATES_H

#include <iostream>
#include <string>

class Coordinates
{
    private:
        double x0, y0;

    public:
        Coordinates();
        Coordinates (double x, double y);

        void setX (double x);
        void setY(double y);

        double getX () const;
        double getY () const;

        Coordinates & operator = (const Coordinates & that);

};

#endif
