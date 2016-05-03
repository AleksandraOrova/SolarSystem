#include "planet.h"

//по идее, он генерируется самостоятельно
//TODO удалить конструктор
Planet::Planet()
{

}

//TODO заменить тело конструктора списком инициализации
Planet::Planet(string name, double mass, double radiusA, double e, double radius, double theta){
    this->RS = (radiusA+radiusB)/2;
    this->radius = radius;
    this->name = name;
    this->mass = mass;
    this->theta = theta;
    this->radiusA = radiusA;
    this->p = (1-pow(e,2))*radiusA;
    this->e = e;
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
//а что ж не удалила?
double Planet::angularPosition(double t) const//TODO: удалить
{
    return (theta + angularVelocity() * t);
}
//а что ж не удалила?
double Planet::varAngularPosition(double t, double dt) const//TODO: удалить
{
    return (angularPosition(t+dt)-angularPosition(t));
}

//вижу 3.1415. Это же почти число пи. резонно создать константу с данным значением. код станет понятней
//TODO добавить констату Pi
TimeHoursSeconds Planet::periodAroundSun() const
{
    return TimeHoursSeconds(2*3.1415/angularVelocity(),0,0,0);
}
void Planet::step(double delta){
    theta += delta*angularVelocity();
}

void Planet::printStaticParameters (ostream& out){
    out << "Масса:                          " << mass << " кг" << endl;
    out << "Угловая скорость:               " << angularVelocity() << " рад/с" << endl;
    out << "Период обращения вокруг солнца: " << periodAroundSun().fromStoYears() << " земной год/с" << endl;
}

void Planet::printDynamicParameters (ostream& out){
    out << "Расстояние до солнца:           " << sunDistance() << " км" << endl;
    out << "Текущий угол:                   " << theta << " рад" << endl;
}
void Planet::printShortInfo (ostream& out){
    out << name << "     \t"
        << mass << "\t"
        << sunDistance() << "\t"
        << periodAroundSun().fromStoYears() << "    \t"
        << theta << "\t"
        << endl;
}
void Planet::printDelta(ostream& out, int delta){
    out << "Планета\tТекущий угол\tПосле сдвига\tВремя в секундах" << endl
        << name << "\t\t" << theta << "\t\t";
    step(delta);
    out << theta << "\t" << delta;
}
double Planet::sunDistance() const
{
    return(p/(1-e*cos(theta)))/1000;
}


ostream& operator << (ostream& out, const Planet& planet)
{
    if (&planet==NULL){
        out << "NULL";
        return out;
    }
    out << "Название планеты:               " << planet.name << endl;
    out << "Масса:                          " << planet.mass << " кг" << endl;
    out << "Расстояние до солнца:           " << planet.sunDistance() << " км" << endl;
    out << "Угловая скорость:               " << planet.angularVelocity() << " рад/с" << endl;
    out << "Период обращения вокруг солнца: " << planet.periodAroundSun().fromStoYears() << " земной год/с" << endl;
    out << "Текущий угол:                   " << planet.theta << " рад" << endl;
    return out;
}
