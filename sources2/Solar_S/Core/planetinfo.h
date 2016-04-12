#ifndef PLANETINFO_H
#define PLANETINFO_H
#include "vector3.h"
#include <cstring>
#include <iostream>
using namespace std;

// класс, содержащий информацию о планете без логики, отстутствуют методы, отвечающие за движение планеты

class PlanetInfo
{
    string name;
    Vector3* coords;
    float mass;
public:
    PlanetInfo(); // конструктор по умолчанию
    PlanetInfo(string name, float x, float y, float z, float mass); // задает инфомацию о планете
    void setPosition(float x, float y, float z); // задает координаты планете
    void setMass(float mass); // задает массу планеты

    void moveBy(float dx, float dy, float dz); // сдвигает планету на dx, dy, dz
    friend ostream& operator << (ostream& out, const PlanetInfo& planetInfo); // перегрузка оператора вывода в поток
};

#endif // PLANETINFO_H
