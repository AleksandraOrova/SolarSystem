#include "juperosdrawer.h"

void JuperosDrawer::paintEvent(QPaintEvent *) {
    QPainter s(this);
    //p.setBrush(QBrush(Qt::black));
    //p.drawRect(0,0, width(), height());
    s.setBrush(QBrush(Qt::white,Qt::NoBrush));
    s.setPen(QPen(Qt::red,1,Qt::SolidLine));
    double ppu = width()/juperos->getPlanet(16).sunDistance()/4;
    for(int i = 16; i > 0; i--)
        drawJuperos(s, juperos->getPlanet(i), ppu);
}

void JuperosDrawer::drawJuperos(QPainter& s, Planet& juperos, double ppu){
    s.setBrush(QBrush(Qt::white,Qt::NoBrush));
    s.drawEllipse(QPoint(480, 370),
                  juperos.sunDistance()*ppu,
                  juperos.sunDistance()*ppu);

    s.setBrush(QBrush(Qt::white,Qt::SolidPattern));
    s.drawEllipse(
                QPoint(
                      480 + juperos.getX()*ppu,
                      370 - juperos.getY()*ppu
                      ),
                  4,
                  4);
}
