#ifndef JUPITERMOONS_H
#define JUPITERMOONS_H

#include "simulator_api.h"
#include "planet.h"
#include <iostream>
using namespace std;

class JupiterMoons : public simulator_api

{

public:
    JupiterMoons();
    JupiterMoons(int count);
    void step(double delta) const noexcept;
    void addMoon(const Moon& Moon, int id) const noexcept;
    Moon& getMoon(int id) const noexcept;
    bool idValid(int id) const noexcept;

private:
    int moonsCount;
    Moon* moons;

    friend ostream& operator << (ostream& out, const JupiterMoons& jupiterMoons);
};

#endif // JUPITERMOONS_H
