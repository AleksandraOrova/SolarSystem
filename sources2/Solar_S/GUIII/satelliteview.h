#ifndef SATELLITEVIEW_H
#define SATELLITEVIEW_H

#include<QWidget>
#include<QPixmap>
#include<QPainter>

class SatelliteView : public QWidget
{
    Q_OBJECT
public:
    SatelliteView(QWidget * parent = 0) : QWidget(parent){}
    void setPixmap(QPixmap pixmap);
protected:
    void paintEvent(QPaintEvent *);
private:
    QPixmap pixmap;
};

#endif // SATELLITEVIEW_H
