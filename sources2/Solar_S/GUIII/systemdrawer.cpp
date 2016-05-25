#include "systemdrawer.h"

void SystemDrawer::paintEvent(QPaintEvent *) {
    QPainter p(this);
    //p.setBrush(QBrush(Qt::black));
    //p.drawRect(0,0, width(), height());
    p.setBrush(QBrush(Qt::white,Qt::NoBrush));
    p.setPen(QPen(Qt::red,1,Qt::SolidLine));
    double ppu = width()/system->getPlanet(8).sunDistance()/3;
    for(int i = 8; i > 0; i--)
        drawPlanet(p, system->getPlanet(i), ppu);
}

void SystemDrawer::drawPlanet(QPainter& p, Planet& planet, double ppu){
    p.setBrush(QBrush(Qt::white,Qt::NoBrush));
    p.drawEllipse(QPoint(width()/2, height()/2),
                  planet.sunDistance()*ppu,
                  planet.sunDistance()*ppu);

    p.setBrush(QBrush(Qt::white,Qt::SolidPattern));
    p.drawEllipse(
                QPoint(
                      width()/2 + planet.getX()*ppu,
                      height()/2 - planet.getY()*ppu
                      ),
                  4,
                  4);
}
