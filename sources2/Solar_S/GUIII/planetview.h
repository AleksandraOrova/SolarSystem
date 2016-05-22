#ifndef PLANETVIEW_H
#define PLANETVIEW_H

#include<QWidget>
#include<QPixmap>

class PlanetView : public QWidget
{
    Q_OBJECT
public:
    PlanetView(QWidget * parent = 0);
    void setPixmap(QPixmap pixmap);
protected:
    void paintEvent(QPaintEvent *);
private:
    QPixmap pixmap;
};

#endif // PLANETVIEW_H
