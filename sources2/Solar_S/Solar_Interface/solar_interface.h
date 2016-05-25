#ifndef SOLAR_INTERFACE_H
#define SOLAR_INTERFACE_H

#include <QtGui>
#include <QWidget>
#include <QPushButton>
#include <QTimer>
#include <QTextStream>
#include <QLineEdit>

#include "solars.h"

class Solar_Interface : public QWidget
{
        Q_OBJECT

    public:
        Solar_Interface(QString path, QWidget *parent = 0);
        void timerEvent(QTimerEvent *);
        void paintEvent(QPaintEvent *);
        void clear (QPainter & paint);
        ~Solar_Interface();

    private slots:

        void on_save_b_clicked();
        void on_load_b_clicked();
        void on_in_text_clicked();
        void on_speed_up_clicked();
        void on_speed_down_clicked();

    private:

        QPushButton * save_b, * load_b, * in_text,
                    * speed_up, * speed_down;
        QTimer * timer;
        QLineEdit * inp;
        //SolarS my_system;
        double curr_time; // period: 6,3
        double speed;
        QString path;
};

#endif // SOLAR_INTERFACE_H
