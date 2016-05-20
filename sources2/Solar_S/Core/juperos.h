#include "solarsystem.h"
#ifndef JUPEROS_H
#define JUPEROS_H


class Juperos : public SolarSystem
{
public:
    Juperos() : SolarSystem(){}
    Juperos(int count) : SolarSystem(count){}
};

#endif // JUPEROS_H
