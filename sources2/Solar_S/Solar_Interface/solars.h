#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include <vector>
#include "star.h"
#include "planets.h"

class SolarS
{
    private:

        typedef std::vector<PlanetS> vector;
        typedef vector::iterator iterator;
        typedef vector::const_iterator c_iterator;

        Star star;
        vector planets;

        void calc_start();

    public:

        SolarS();
        SolarS(const Star & star_, const vector & planets_);

        void setStar(const Star & star);
        void setPlanets (const vector & planets_);

        Star getStar() const;
        vector getPlanets() const;
        size_t getSize() const;

        void planetsMovement(double); //Ìîäåëèðîâàíèå äâèæåíèÿ ïëàíåò
        std::string toString() const;
        void output(const char *filename, bool append) const;
        void input(const char *filename);
        void save() const;
};

#endif
