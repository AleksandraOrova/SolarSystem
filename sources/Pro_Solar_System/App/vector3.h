#ifndef VECTOR3_H
#define VECTOR3_H


class Vector3
{
public:
    float x;
    float y;
    float z;
    Vector3();
    Vector3(float x, float y, float z);
    void moveBy(float dx, float dy, float dz);
    char* toString();
};

#endif // VECTOR3_H
