#include "planet.h"

// todo можно сделать такой конструктор inline и убрать это отсюда
Planet::Planet(){

}
// todo использовать список инициализации
Planet::Planet(const string& name,
               const double mass,
               const double radiusA,
               const double e,
               const double radius,
               const double theta)
{
    this->LenghtToSun = (radiusA+radiusB)/2;
    this->radius = radius;
    this->name = name;
    this->mass = mass;
    this->theta = theta;
    this->radiusA = radiusA;
    this->p = (1-pow(e,2))*radiusA;
    this->e = e;
}

Planet::Planet(Planet& planet)
{
    this->name = planet.name;
    this->LenghtToSun = planet.LenghtToSun;
    this->theta = planet.theta;
    this->radius = planet.radius;
    this->p = planet.p;
    this->e = planet.e;
    this->radiusA = planet.radiusA;
    this->radiusB = planet.radiusB;
    this->mass = planet.mass;
}

// todo следующие пять методов (и метод sunDistance) можно сделать inline (вынести в .h файл), если хотите
// а вообще, это норм выносить методы в одну строчку прямо в header. У вас много таких
double Planet::gravitationalForce() const
{
    return (G * (mass*SunMass)/pow(LenghtToSun,2));
}

double Planet::angularVelocity() const
{
    return sqrt(gravitationalForce()/(mass*LenghtToSun));
}

double Planet::velocity() const
{
    return (angularVelocity() * LenghtToSun);
}

Time Planet::periodAroundSun() const
{
    return Time(2*Pi/angularVelocity(),0,0,0);
}

void Planet::step(const double delta)
{
    theta += delta*angularVelocity();
}

void Planet::printStaticParameters (ostream& out) const
{
    out << "Масса:                          " << mass << " кг" << endl;
    out << "Угловая скорость:               " << angularVelocity() << " рад/с" << endl;
    out << "Период обращения вокруг солнца: " << periodAroundSun().fromSecondstoYears() << " земной год/с" << endl;
}

void Planet::printDynamicParameters (ostream& out) const
{
    out << "Расстояние до солнца:           " << sunDistance() << " км" << endl;
    out << "Текущий угол:                   " << theta << " рад" << endl;
}

void Planet::printShortInfo (ostream& out) const
{
    out << name << "     \t"
        << mass << "\t"
        << sunDistance() << "\t"
        << periodAroundSun().fromSecondstoYears() << "    \t"
        << theta << "\t"
        << endl;
}

void Planet::printDelta(ostream& out, const int delta)
{
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
    out << "Период обращения вокруг солнца: " << planet.periodAroundSun().fromSecondstoYears() << " земной год/с" << endl;
    out << "Текущий угол:                   " << planet.theta << " рад" << endl;
    return out;
}
