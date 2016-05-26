#include "planetview.h"

void PlanetView::setPixmap(QPixmap pixmap)
{
    this->pixmap = pixmap;
}

void PlanetView::paintEvent(QPaintEvent *) {
    QPainter p(this);
    p.setPen(QPen(Qt::red,1,Qt::SolidLine)); // Настройки рисования
    p.drawPixmap(0,0,500, 427,pixmap);
}
