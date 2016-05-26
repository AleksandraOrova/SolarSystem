#ifndef PLANETVIEW_H
#define PLANETVIEW_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>

class PlanetView : public QWidget
{
    Q_OBJECT
public:
    PlanetView(QWidget * parent = 0) : QWidget(parent){}
    void setPixmap(QPixmap pixmap);
protected:
    void paintEvent(QPaintEvent *);
private:
    QPixmap pixmap;
};

#endif // PLANETVIEW_H
