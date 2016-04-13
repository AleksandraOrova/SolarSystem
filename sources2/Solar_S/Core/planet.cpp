#include "planet.h"

Planet::Planet()
{

}
Planet::Planet(string name, float mass, float RS, float radius, float theta)
{
    this->theta = theta;
    this->radius = radius;
    this->RS = RS;
    this->mass = mass;
    this->name = name;
}

ostream& operator << (ostream& out, const Planet& planet)
{
    if (&planet==NULL){
        out << "NULL";
        return out;
    }
    out << "Название планеты: " << planet.name << endl;
    out << "Масса: " << planet.mass << " кг" << endl;
    out << "Расстояние до солнца " << planet.RS/1000 << " км" << endl;
    out << "Угловая скорость " << planet.angularVelocity() << "рад/с" << endl;
    out << "Период обращения вокруг солнца " << planet.periodAroundSun().fromStoYears() << " земной год/с" << endl;
    return out;
}

float Planet::gravitationalForce() const
{
    return (G * (mass*sunM)/pow(RS,2));
}
float Planet::angularVelocity() const
{
    return sqrt(gravitationalForce()/(mass*RS));
}
float Planet::velocity() const
{
    return (angularVelocity() * RS);

}
float Planet::angularPosition(float t) const
{
    return (theta + angularVelocity() * t);

}
float Planet::varAngularPosition(float t, float dt) const
{
    return (angularPosition(t+dt)-angularPosition(t));
}
TimeHoursSeconds Planet::periodAroundSun() const
{
    return TimeHoursSeconds(2*3.1415/angularVelocity(),0,0,0);
}
