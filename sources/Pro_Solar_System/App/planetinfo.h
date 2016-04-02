#ifndef PLANETINFO_H
#define PLANETINFO_H
#include <string>
#include "vector3.h"

class PlanetInfo
{
    char* name;
    float mass;
    float currentTime;
    Vector3 position;
public:
    PlanetInfo();
    PlanetInfo(char* name, float mass, float x, float y, float z);
    void moveBy(float dx, float dy, float dz);
    void step(float deltaTime);
    void setTime(float newTime);
    char* toString();
};

#endif // PLANETINFO_H
