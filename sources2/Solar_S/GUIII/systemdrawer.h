#ifndef SYSTEMDRAWER_H
#define SYSTEMDRAWER_H

#include<QWidget>
#include<QPixmap>
#include<QPainter>

#include "solarsystem.h"

class SystemDrawer : public QWidget
{
private:
    SolarSystem* system;
    void drawPlanet(QPainter& p, Planet& planet, double ppu);
protected:
    void paintEvent(QPaintEvent *);
public:
    SystemDrawer(SolarSystem* system, QWidget * parent = 0) : QWidget(parent), system(system){}
};

#endif // SYSTEMDRAWER_H
