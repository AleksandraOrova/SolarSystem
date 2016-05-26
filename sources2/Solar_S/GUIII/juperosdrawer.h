#ifndef JUPEROSDRAWER_H
#define JUPEROSDRAWER_H

#include<QWidget>
#include<QPixmap>
#include<QPainter>

#include "solarsystem.h"

class JuperosDrawer : public QWidget
{
private:
    SolarSystem* juperos;
    void drawJuperos(QPainter& s, Planet& satellite, double ppu);
protected:
    void paintEvent(QPaintEvent *);
public:
    JuperosDrawer(SolarSystem* juperos, QWidget * parent = 0) : QWidget(parent), juperos(juperos){}
};

#endif // SYSTEMDRAWER_H
