#include "planet.h"

Planet::Planet(const std::string& name,
               const double mass,
               const double radiusA,
               const double e,
               const double radius,
               const double theta):
    name(name),
    LenghtToSun(radiusA),
    theta(theta),
    radius(radius),
    p((1-pow(e,2))*radiusA),
    e(e),
    radiusA(radiusA),
    mass(mass) {}

Planet::Planet(Planet& planet):
    name (planet.name),
    LenghtToSun (planet.LenghtToSun),
    theta (planet.theta),
    radius (planet.radius),
    p(planet.p),
    e(planet.e),
    radiusA(planet.radiusA),
    mass(planet.mass) {}

void Planet::printStaticParameters (std::ostream& out) const
{
    out << "Масса:                          " << mass << " кг" << std::endl;
    out << "Угловая скорость:               " << angularVelocity() << " рад/с" << std::endl;
    out << "Период обращения вокруг солнца: " << periodAroundSun().fromSecondstoYears() << " земной год/с" << std::endl;
}

void Planet::printDynamicParameters (std::ostream& out) const
{
    out << "Расстояние до солнца:           " << sunDistance() << " км" << std::endl;
    out << "Текущий угол:                   " << theta << " рад" << std::endl;
}

void Planet::printShortInfo (std::ostream& out) const
{
    out << name << "     \t"
        << mass << "\t"
        << sunDistance() << "\t"
        << periodAroundSun().fromSecondstoYears() << "    \t"
        << theta << "\t"
        << std::endl;
}

void Planet::printDelta(std::ostream& out, const int delta)
{
    out << "Планета\tТекущий угол\tПосле сдвига\tВремя в секундах" << std::endl
        << name << "\t\t" << theta << "\t\t";
    step(delta);
    out << theta << "\t" << delta;
}

std::ostream& operator << (std::ostream& out, const Planet& planet)
{
    if (&planet==NULL){
        out << "NULL";
        return out;
    }
    out << "Название планеты:               " << planet.name << std::endl;
    out << "Масса:                          " << planet.mass << " кг" << std::endl;
    out << "Расстояние до солнца:           " << planet.sunDistance() << " км" << std::endl;
    out << "Угловая скорость:               " << planet.angularVelocity() << " рад/с" << std::endl;
    out << "Период обращения вокруг солнца: " << planet.periodAroundSun().fromSecondstoYears() << " земной год/с" << std::endl;
    out << "Текущий угол:                   " << planet.theta << " рад" << std::endl;
    return out;
}
