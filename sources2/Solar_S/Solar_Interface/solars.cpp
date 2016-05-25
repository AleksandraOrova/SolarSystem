#include "solars.h"
#include <fstream>
#include <cmath>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <QTextStream>
#include <QString>
#include <QFile>

SolarS::SolarS()
{

}

SolarS::SolarS(const Star & star_, const vector & planets_) : star(star_)
{
    for (c_iterator i = planets_.begin(); i != planets_.end(); ++i)
    {
        planets.push_back(*i);
    }
}

void SolarS::setStar(const Star & star)
{
    this->star = star;
}

void SolarS::setPlanets(const vector & planets_)
{
    for (c_iterator i = planets_.begin(); i != planets_.end(); ++i)
    {
        planets.push_back(*i);
    }
}

Star SolarS::getStar() const
{
    return star;
}

std::vector<PlanetS> SolarS::getPlanets() const
{
    return planets;
}

void SolarS::planetsMovement(double time)
{
    for (iterator i = planets.begin(); i != planets.end(); i++)
    {
        i->setPositionX(star.getPosition().getX() +
                        i->getOrbit() * cos(i->getStartTime() + time * i->getSpeed()));
        i->setPositionY(star.getPosition().getY() +
                        i->getOrbit() * sin(i->getStartTime() + time * i->getSpeed()));
    }
}

std::string SolarS::toString() const
{
    std::string str = star.toString() + "\n";

    for (c_iterator i = planets.begin(); i != planets.end(); i++) {
        str += "\n" + i->toString() + "\n";
    }

    return str;
}

void SolarS::output(const char *filename, bool append) const
{
    if (filename == NULL)
    {
        throw std::invalid_argument("Wrong filename!");
    }

    std::ofstream fout;

    if (append)
    {
        fout.open(filename, std::ios::out | std::ios::app);
    }
    else
    {
        fout.open(filename);
    }

    if (!fout)
    {
        throw std::runtime_error("File wasn't opened!");
    }

    fout << toString() << std::endl;
}

void SolarS::input(const char * filename)
{
    planets.clear();

    if (filename == NULL)
    {
        throw std::invalid_argument("Wrong filename!");
    }

    QFile file(filename);
    if (!file.open(QFile::ReadOnly))
    {
        throw std::runtime_error("File wasn't opened: " + std::string(filename));
    };
    QTextStream fin(&file);

    // Firt record - is star
    QString name, color;
    double mass, rad, x, y, speed;
    fin >> name >> mass >> rad >> x >> y;
    std::cout << name.toStdString() << mass << std::endl;
    star = Star(name.toStdString(), mass, rad, Coordinates(x, y));
    // Then - planets
    while (!fin.atEnd())
    {
        QString name = "";
        fin >> name >> color >> mass >> rad >> speed >> x >> y;

        if (name == "")
        {
            continue;
        }

        planets.push_back(PlanetS(name.toStdString(), color.toStdString(), mass, rad, speed, Coordinates(x, y)));
        name = "";
    }
    file.close();
    calc_start();
}

void SolarS::save() const
{
    QFile file("condition.log");
    if (!file.open(QFile::WriteOnly))
    {
        throw std::runtime_error("File wasn't opened: ");
    };
    QTextStream fout(&file);

    fout << star.getName().c_str() << " " << star.getMass() << " "
         << star.getRad() << " " << star.getPosition().getX()
         << " " << star.getPosition().getY() << "\n";

    for (c_iterator i = planets.begin(); i != planets.end(); ++i)
    {
        fout << i->getName().c_str() << " " << i->getColor().c_str()
             << " " << i->getMass() << " " << i->getRad()
             << " " << i->getSpeed() << " " << i->getPosition().getX()
             << " " << i->getPosition().getY() << "\n";
    }

    file.close();
}

size_t SolarS::getSize() const
{
    return planets.size();
}

void SolarS::calc_start()
{
    for (iterator i = planets.begin(); i != planets.end(); ++i)
    {
        i->setOrbit(std::sqrt(std::pow(i->getPosition().getX()
                                       - star.getPosition().getX(), 2)
                              + std::pow(i->getPosition().getY()
                                         - star.getPosition().getY(), 2)));

        i->setStartTime(std::atan(
                            (i->getPosition().getY() - star.getPosition().getY())
                            /
                            (i->getPosition().getX() - star.getPosition().getX())
                        ));

        if (i->getPosition().getX() - star.getPosition().getX() < 0)
        {
            i->setStartTime(3.14 + i->getStartTime());
        }
    }
}
