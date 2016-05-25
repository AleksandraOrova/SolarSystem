#include "solar_interface.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Solar_Interface my_interface(a.applicationDirPath());
    my_interface.show();
    return a.exec();
}
