#include "vector3.h"

Vector3::Vector3()
{
    setPosition(0,0,0);
}
Vector3::Vector3(float x, float y, float z)
{
    setPosition(x,y,z);
}
void Vector3::setPosition(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
void Vector3::moveBy(float dx, float dy, float dz)
{
    x+=dx;
    y+=dy;
    z+=dz;
}
ostream& operator << (ostream& out, const Vector3& vector3)
{
    if (&vector3==NULL){
        out << "NULL";
        return out;
    }
    out << "(" << vector3.x << " ; " << vector3.y << " ; " << vector3.z << ")";
    return out;
}
