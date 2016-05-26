#include "satelliteview.h"

void SatelliteView::setPixmap(QPixmap pixmap)
{
    this->pixmap = pixmap;
}

void SatelliteView::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setPen(QPen(Qt::red,1,Qt::SolidLine)); // Настройки рисования
    p.drawPixmap(0,0,480, 727, pixmap);
}
