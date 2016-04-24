#include "planet.h"

Planet::Planet()
{

}
Planet::Planet(string name, double mass, double RS, double radius, double theta)
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
    out << "Угловая скорость " << planet.angularVelocity() << " рад/с" << endl;
    out << "Период обращения вокруг солнца " << planet.periodAroundSun().fromStoYears() << " земной год/с" << endl;
    out << "Текущий положение " << planet.theta << " рад" << endl;
    return out;
}

double Planet::gravitationalForce() const{
    return (G * (mass*sunM)/pow(RS,2));
}

double Planet::angularVelocity() const
{
    return sqrt(gravitationalForce()/(mass*RS));
}
double Planet::velocity() const
{
    return (angularVelocity() * RS);
}
double Planet::angularPosition(double t) const//TODO: удалить
{
    return (theta + angularVelocity() * t);
}
double Planet::varAngularPosition(double t, double dt) const//TODO: удалить
{
    return (angularPosition(t+dt)-angularPosition(t));
}
TimeHoursSeconds Planet::periodAroundSun() const
{
    return TimeHoursSeconds(2*3.1415/angularVelocity(),0,0,0);
}
void Planet::step(double delta){
    theta += delta*angularVelocity();
}
