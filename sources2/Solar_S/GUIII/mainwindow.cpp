#include <QtWidgets>

#include "mainwindow.h"

MainWindow::MainWindow()
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    infoLabel = new QLabel(tr("<i>Choose a menu option, or right-click to "
                              "invoke a context menu</i>"));
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addWidget(topFiller);
    layout->addWidget(infoLabel);
    layout->addWidget(bottomFiller);
    widget->setLayout(layout);

    createActions();
    createMenus();

    QString message = tr("A context menu is available by right-clicking");
    statusBar()->showMessage(message);

    setWindowTitle(tr("Симулятор звездной системы"));
    setMinimumSize(160, 160);
    resize(480, 320);

    QPixmap background(":/SolarSystem/report/andromedawan.jpg");
    QPalette qPalette;
    qPalette.setBrush(this->backgroundRole(),QBrush(background));
    this->setPalette(qPalette);
    this->setFixedSize(730,525);
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(cutAct);
    menu.addAction(copyAct);
    menu.addAction(pasteAct);
    menu.exec(event->globalPos());
}

void MainWindow::about()
{
    infoLabel->setText(tr("Invoked <b>Help|About</b>"));
    QMessageBox::about(this, tr("About Menu"),
            tr("The <b>Menu</b> example shows how to create "
               "menu-bar menus and context menus."));
}
void MainWindow::aboutQt()
{
    infoLabel->setText(tr("Invoked <b>Help|About Qt</b>"));
}

void MainWindow::createActions()
{

    aboutAct = new QAction(tr("О &проекте"), this);
    aboutAct->setStatusTip(tr("Выбор краткой анотации к проекту"));
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

    aboutQtAct = new QAction(tr("О &Qt"), this);
    aboutQtAct->setStatusTip(tr("Показать библиотеки Qt"));
    connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(aboutQtAct, &QAction::triggered, this, &MainWindow::aboutQt);

    planets[0] = new QAction(tr("&Меркурий"), this);
    planets[0]->setStatusTip(tr("Выбор &Меркурий"));
    connect(planets[0], &QAction::triggered, this, &MainWindow::Planet1);
    planets[1] = new QAction(tr("&Венера"), this);
    planets[1]->setStatusTip(tr("Выбор &Венера"));
    connect(planets[1], &QAction::triggered, this, &MainWindow::Planet2);
    planets[2] = new QAction(tr("&Земля"), this);
    planets[2]->setStatusTip(tr("Выбор &Земля"));
    connect(planets[2], &QAction::triggered, this, &MainWindow::Planet3);
    planets[3] = new QAction(tr("&Марс"), this);
    planets[3]->setStatusTip(tr("Выбор &Марс"));
    connect(planets[3], &QAction::triggered, this, &MainWindow::Planet4);
    planets[4] = new QAction(tr("&Юпитер"), this);
    planets[4]->setStatusTip(tr("Выбор &Юпитер"));
    connect(planets[4], &QAction::triggered, this, &MainWindow::Planet5);
    planets[5] = new QAction(tr("&Сатурн"), this);
    planets[5]->setStatusTip(tr("Выбор &Сатурн"));
    connect(planets[5], &QAction::triggered, this, &MainWindow::Planet6);
    planets[6] = new QAction(tr("&Уран"), this);
    planets[6]->setStatusTip(tr("Выбор &Уран"));
    connect(planets[6], &QAction::triggered, this, &MainWindow::Planet7);
    planets[7] = new QAction(tr("&Нептун"), this);
    planets[7]->setStatusTip(tr("Выбор &Нептун"));
    connect(planets[7], &QAction::triggered, this, &MainWindow::Planet8);

    planetsInfo = new QAction(tr("Общая информация"), this);
    planetsInfo->setStatusTip(tr("Вывод полной информации о планетах"));
    connect(planetsInfo, &QAction::triggered, this, &MainWindow::Planet8);
    comparePlanets = new QAction(tr("Сравнение планет"), this);
    comparePlanets->setStatusTip(tr("Вывод таблицы сравнения планет"));

    satellites[0] = new QAction(tr("&Метида"), this);
    satellites[0]->setStatusTip(tr("Выбор &Метида"));
    connect(satellites[0], &QAction::triggered, this, &MainWindow::Satellite1);
    satellites[1] = new QAction(tr("&Адрастея"), this);
    satellites[1]->setStatusTip(tr("Выбор &Адрастея"));
    connect(satellites[1], &QAction::triggered, this, &MainWindow::Satellite2);
    satellites[2] = new QAction(tr("&Амальтея"), this);
    satellites[2]->setStatusTip(tr("Выбор &Амальтея"));
    connect(satellites[2], &QAction::triggered, this, &MainWindow::Satellite3);
    satellites[3] = new QAction(tr("&Тебя"), this);
    satellites[3]->setStatusTip(tr("Выбор &Тебя"));
    connect(satellites[3], &QAction::triggered, this, &MainWindow::Satellite4);
    satellites[4] = new QAction(tr("&Ио"), this);
    satellites[4]->setStatusTip(tr("Выбор &Ио"));
    connect(satellites[4], &QAction::triggered, this, &MainWindow::Satellite5);
    satellites[5] = new QAction(tr("&Европа"), this);
    satellites[5]->setStatusTip(tr("Выбор &Европа"));
    connect(satellites[5], &QAction::triggered, this, &MainWindow::Satellite6);
    satellites[6] = new QAction(tr("&Ганимед"), this);
    satellites[6]->setStatusTip(tr("Выбор &Ганимед"));
    connect(satellites[6], &QAction::triggered, this, &MainWindow::Satellite7);
    satellites[7] = new QAction(tr("&Каллисто"), this);
    satellites[7]->setStatusTip(tr("Выбор &Каллисто"));
    connect(satellites[7], &QAction::triggered, this, &MainWindow::Satellite8);
    satellites[8] = new QAction(tr("&Леда"), this);
    satellites[8]->setStatusTip(tr("Выбор &Леда"));
    connect(satellites[8], &QAction::triggered, this, &MainWindow::Satellite9);
    satellites[9] = new QAction(tr("&Гималия"), this);
    satellites[9]->setStatusTip(tr("Выбор &Гималия"));
    connect(satellites[9], &QAction::triggered, this, &MainWindow::Satellite10);
    satellites[10] = new QAction(tr("&Лизистея"), this);
    satellites[10]->setStatusTip(tr("Выбор &Лизистея"));
    connect(satellites[10], &QAction::triggered, this, &MainWindow::Satellite11);
    satellites[11] = new QAction(tr("&Илара"), this);
    satellites[11]->setStatusTip(tr("Выбор &Илара"));
    connect(satellites[11], &QAction::triggered, this, &MainWindow::Satellite12);
    satellites[12] = new QAction(tr("&Ананке"), this);
    satellites[12]->setStatusTip(tr("Выбор &Ананке"));
    connect(satellites[12], &QAction::triggered, this, &MainWindow::Satellite13);
    satellites[13] = new QAction(tr("&Карме"), this);
    satellites[13]->setStatusTip(tr("Выбор &Карме"));
    connect(satellites[13], &QAction::triggered, this, &MainWindow::Satellite14);
    satellites[14] = new QAction(tr("&Пасифе"), this);
    satellites[14]->setStatusTip(tr("Выбор &Пасифе"));
    connect(satellites[14], &QAction::triggered, this, &MainWindow::Satellite15);
    satellites[15] = new QAction(tr("&Синопе"), this);
    satellites[15]->setStatusTip(tr("Выбор &Синопе"));
    connect(satellites[15], &QAction::triggered, this, &MainWindow::Satellite16);

    satellitesInfo = new QAction(tr("Общая информация"), this);
    satellitesInfo->setStatusTip(tr("Вывод полной информации о планетах"));
    compareSatellites = new QAction(tr("Сравнение планет"), this);
    compareSatellites->setStatusTip(tr("Вывод таблицы сравнения планет"));
}


void MainWindow:: Planet1()
{
    infoLabel->setText(tr("Вызвано <b>Звездная система - Меркурий</b>"));
}
void MainWindow:: Planet2()
{
    infoLabel->setText(tr("Вызвано <b>Звездная система - Венера</b>"));
}
void MainWindow:: Planet3()
{
    infoLabel->setText(tr("Вызвано <b>Звездная система - Земля</b>"));
}
void MainWindow:: Planet4()
{
    infoLabel->setText(tr("Вызвано <b>Звездная система - Марс</b>"));
}
void MainWindow:: Planet5()
{
    infoLabel->setText(tr("Вызвано <b>Звездная система - Юпитер</b>"));
}
void MainWindow:: Planet6()
{
    infoLabel->setText(tr("Вызвано <b>Звездная система - Сатурн</b>"));
}
void MainWindow:: Planet7()
{
    infoLabel->setText(tr("Вызвано <b>Звездная система - Уран</b>"));
}
void MainWindow:: Planet8()
{
    infoLabel->setText(tr("Вызвано <b>Звездная система - Нептун</b>"));
}

void MainWindow:: Satellite1()
{
    infoLabel->setText(tr("Вызвано <b>Юпитер и спутники - Метида</b>"));
}
void MainWindow:: Satellite2()
{
    infoLabel->setText(tr("Вызвано <b>Юпитер и спутники - Адрастея</b>"));
}
void MainWindow:: Satellite3()
{
    infoLabel->setText(tr("Вызвано <b>Юпитер и спутники - Амальтея</b>"));
}
void MainWindow:: Satellite4()
{
    infoLabel->setText(tr("Вызвано <b>Юпитер и спутники - Теба</b>"));
}
void MainWindow:: Satellite5()
{
    infoLabel->setText(tr("Вызвано <b>Юпитер и спутники - Ио</b>"));
}
void MainWindow:: Satellite6()
{
    infoLabel->setText(tr("Вызвано <b>Юпитер и спутники - Европа</b>"));
}
void MainWindow:: Satellite7()
{
    infoLabel->setText(tr("Вызвано <b>Юпитер и спутники - Ганимед</b>"));
}
void MainWindow:: Satellite8()
{
    infoLabel->setText(tr("Вызвано <b>Юпитер и спутники - Каллисто</b>"));
}
void MainWindow:: Satellite9()
{
    infoLabel->setText(tr("Вызвано <b>Юпитер и спутники - Леда</b>"));
}
void MainWindow:: Satellite10()
{
    infoLabel->setText(tr("Вызвано <b>Юпитер и спутники - Гималия</b>"));
}
void MainWindow:: Satellite11()
{
    infoLabel->setText(tr("Вызвано <b>Юпитер и спутники - Лизистея</b>"));
}
void MainWindow:: Satellite12()
{
    infoLabel->setText(tr("Вызвано <b>Юпитер и спутники - Илара</b>"));
}
void MainWindow:: Satellite13()
{
    infoLabel->setText(tr("Вызвано <b>Юпитер и спутники - Ананке</b>"));
}
void MainWindow:: Satellite14()
{
    infoLabel->setText(tr("Вызвано <b>Юпитер и спутники - Карме</b>"));
}
void MainWindow:: Satellite15()
{
    infoLabel->setText(tr("Вызвано <b>Юпитер и спутники - Писифе</b>"));
}
void MainWindow:: Satellite16()
{
    infoLabel->setText(tr("Вызвано <b>Юпитер и спутники - Синопе</b>"));
}

void MainWindow::createMenus()
{
    helpMenu = menuBar()->addMenu(tr("&Проект"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);

    solarSystemView = menuBar()->addMenu(tr("&Солнечная система"));
    for (int i = 0; i < 8; i++)
        solarSystemView->addAction(planets[i]);
    solarSystemView->addSeparator();
    solarSystemView->addAction(planetsInfo);
    solarSystemView->addAction(comparePlanets);

    juperosView = menuBar()->addMenu(tr("&Юпитер и спутники"));
    for (int i = 0; i < 16; i++)
        juperosView->addAction(satellites[i]);
    juperosView->addSeparator();
    juperosView->addAction(satellitesInfo);
    juperosView->addAction(compareSatellites);
}
