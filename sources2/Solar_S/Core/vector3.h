#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
using namespace std;

// класс с координатами планеты
// содержит основыне методы по работе с координатами

class Vector3
{
private:
    float x;
    float y;
    float z;
public:
    Vector3(); // конструктор по умолчанию
    Vector3(float x, float y, float z); // задает координаты вектора при создании
    void setPosition(float x, float y, float z); //устанавливает кооординаты
    void moveBy(float dx, float dy, float dz); // смещает координаты на dx, dy, dz

    friend ostream& operator << (ostream& out, const Vector3& vector3); // перегрузка оператора вывода в поток
};

#endif // VECTOR3_H
