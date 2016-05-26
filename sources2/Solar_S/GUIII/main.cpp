#include <QApplication>
#include <QtWidgets>
#include "mainwindow.h"

int main(int argc,char **argv)
{
    QApplication app(argc, argv);
    MainWindow window;
    window.setFixedSize(1000,800);
    window.show();
    return app.exec();
}

