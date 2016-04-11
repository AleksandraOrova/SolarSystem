#ifndef PLANETINFO_H
#define PLANETINFO_H
#include "vector3.h"
#include <cstring>

// класс, содержащий информацию о планете без логики, отстутствуют методы, отвечающие за движение планеты

class PlanetInfo
{
    char* name;
    Vector3* coords;
    float mass;
public:
    PlanetInfo(); // конструктор по умолчанию
    PlanetInfo(char* name, float x, float y, float z, float mass); // задает инфомацию о планете
    void setPosition(float x, float y, float z); // задает координаты планете
    void setMass(float mass); // задает массу планеты
    char* toString(); // конвертация в строку
};

#endif // PLANETINFO_H
