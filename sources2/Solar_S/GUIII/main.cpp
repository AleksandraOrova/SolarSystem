#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QSlider>
#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QtGui>
#include <QPalette>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QStatusBar>
#include <QLineEdit>
#include "mainwindow.h"

int main(int argc,char **argv)
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}

