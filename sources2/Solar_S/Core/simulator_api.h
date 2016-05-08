#ifndef SIMULATOR_API_H
#define SIMULATOR_API_H

#include"planet.h"

class simulator_api{
public:
    virtual void step(double delta) = 0;
    /**
     * @brief addPlanet
     * @param planet
     * @param id
     */
    virtual void addPlanet(const Planet& planet, int id) = 0;
    /**
     * @brief getPlanet
     * @param id
     * @return
     */
    virtual Planet& getPlanet(int id) = 0;
    /**
     * @brief idValid
     * @param id
     * @return
     */
    virtual bool idValid(int id) = 0;
};

#endif // SIMULATOR_API_H
