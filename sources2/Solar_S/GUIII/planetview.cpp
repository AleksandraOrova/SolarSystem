#include "planetview.h"

#include <QPainter>

PlanetView::PlanetView(QWidget * parent) : QWidget(parent)
{
}
void PlanetView::setPixmap(QPixmap pixmap){
    this->pixmap = pixmap;
}

void PlanetView::paintEvent(QPaintEvent *) {
    QPainter p(this); // Создаём новый объект рисовальщика
    p.setPen(QPen(Qt::red,1,Qt::SolidLine)); // Настройки рисования
    //p.drawLine(0,0,width(),height()); // Рисование линии
    p.drawPixmap(0,0,pixmap);
}
