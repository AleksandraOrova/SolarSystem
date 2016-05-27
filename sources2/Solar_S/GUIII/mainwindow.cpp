#include <QtWidgets>
#include "mainwindow.h"

MainWindow::MainWindow()
{
    widget = new QWidget;
    setCentralWidget(widget);
    widget->setFixedSize(1000, 800);

    planetView = new PlanetView();
    planetView->adjustSize();
    planetView->setFixedSize(widget->size());
    planetView->hide();
    planetName = new QLabel(tr("banana"));
    planetName->hide();

    satelliteView = new SatelliteView();
    satelliteView->adjustSize();
    satelliteView->setFixedSize(widget->size());
    satelliteView->hide();
    satelliteName = new QLabel(tr("banana"));
    satelliteName->hide();

    system = new SolarSystem(8);
    system->addPlanet(Planet("Меркурий", 3.302  * pow(10,23),   57909227000,     0.20563593,  0.3f,  0), 0);
    system->addPlanet(Planet("Венера",   4.8685 * pow(10,24),  108208930000,         0.0068,  0.4f,  0), 1);
    system->addPlanet(Planet("Земля",    5.973  * pow(10,24),  149598261000,     0.01671123,  0.5f,  0), 2);
    system->addPlanet(Planet("Марс",     6.4185 * pow(10,23),  227943820000,      0.0933941,  0.45f, 0), 3);
    system->addPlanet(Planet("Юпитер",   1.8986 * pow(10,27),  778547200000,       0.048775,  0.8f,  0), 4);
    system->addPlanet(Planet("Сатурн",   5.6846 * pow(10,26), 1433449370000,    0.055723219,  0.7f,  0), 5);
    system->addPlanet(Planet("Уран",     8.6832 * pow(10,25), 2876679082000,    0.044405586,  0.6f,  0), 6);
    system->addPlanet(Planet("Нептун",   1.0243 * pow(10,26), 4503443661000,    0.011214269,  0.6f,  0), 7);

    systemDrawer = new SystemDrawer(system);
    systemDrawer->adjustSize();
    systemDrawer->setFixedSize(widget->size());
    systemDrawer->hide();

    planetTimer = new QTimer(this);
    connect(planetTimer, SIGNAL(timeout()), SLOT(movePlanet()));

    juperos = new SolarSystem(16);
    juperos->addPlanet(Planet("Метида",     9.5    * pow(10,16),   127690000,       0.00002,     0.3f,  0), 0);
    juperos->addPlanet(Planet("Адрастея",   1.91   * pow(10,16),   128690000,       0.0015,      0.3f,  0), 1);
    juperos->addPlanet(Planet("Амальтея",   7.17   * pow(10,17),   181690000,       0.0032,      0.3f,  0), 2);
    juperos->addPlanet(Planet("Теба",       7.77   * pow(10,17),   222000000,       0.0038,      0.3f,  0), 3);
    juperos->addPlanet(Planet("Ио",         8.94   * pow(10,22),   422000000,       0.0041,      0.3f,  0), 4);
    juperos->addPlanet(Planet("Европа",     4.8    * pow(10,22),   617000000,       0.0094,      0.3f,  0), 5);
    juperos->addPlanet(Planet("Ганимед",    1.48   * pow(10,23),   1070000000,      0.0011,      0.3f,  0), 6);
    juperos->addPlanet(Planet("Каллисто",   1.08   * pow(10,23),   1883000000,      0.0074,      0.3f,  0), 7);
    juperos->addPlanet(Planet("Леда",       5.68   * pow(10,15),   11094000000,     0.1673,      0.3f,  0), 8);
    juperos->addPlanet(Planet("Гималия",    9.56   * pow(10,18),   11480000000,     0.1513,      0.3f,  0), 9);
    juperos->addPlanet(Planet("Лизистея",   7.77   * pow(10,16),   11720000000,     0.1322,      0.3f,  0), 10);
    juperos->addPlanet(Planet("Илара",      7.77   * pow(10,17),   11737000000,     0.1374,      0.3f,  0), 11);
    juperos->addPlanet(Planet("Ананке",     3.82   * pow(10,16),   21200000000,     0.3445,      0.3f,  0), 12);
    juperos->addPlanet(Planet("арме",       9.56   * pow(10,16),   22600000000,     0.2342,      0.3f,  0), 13);
    juperos->addPlanet(Planet("Писифе",     1.91   * pow(10,17),   23500000000,     0.3288,      0.3f,  0), 14);
    juperos->addPlanet(Planet("Синопе",     7.77   * pow(10,17),   23700000000,     0.2750,      0.3f,  0), 15);

    juperosDrawer = new JuperosDrawer(juperos);
    juperosDrawer->adjustSize();
    juperosDrawer->setFixedSize(widget->size());
    juperosDrawer->hide();

    satelliteTimer = new QTimer(this);
    connect(satelliteTimer, SIGNAL(timeout()), SLOT(moveSatellite()));

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    text = new QLabel;
    text->show();

    QPixmap background(":/1.jpg");
    QPalette palett;
    palett.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(palett);

    infoLabel = new QLabel(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Выберите пункт меню</center></h1></font>"));
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    current_planet = 0;
    current_system = "";
    step_delta = new QPushButton("Сдвиг на дельту", this);
    step_delta->resize(BUTTON_SIZE);
    step_delta->move(150, 590);
    step_delta->hide();
    connect(step_delta, SIGNAL(clicked()), SLOT(moveInTime()));

    days = new QLineEdit(this);
    createLine(days, 110, 550);
    hours = new QLineEdit(this);
    createLine(hours, 180, 550);
    minutes = new QLineEdit(this);
    createLine(minutes, 250, 550);
    seconds = new QLineEdit(this);
    createLine(seconds, 320, 550);

    days_text = new QLabel("Дни", this);
    createLabel(days_text, 110, 520);
    days_text->setStyleSheet("color: #ffffff;"
                             "font-size: 18px;"
                             "font-weight: bold;");
    days_text->hide();
    hours_text = new QLabel("Часы", this);
    createLabel(hours_text, 180, 520);
    hours_text->setStyleSheet("color: #ffffff;"
                              "font-size: 18px;"
                              "font-weight: bold;");
    hours_text->hide();
    minutes_text = new QLabel("Мин.", this);
    createLabel(minutes_text, 250, 520);
    minutes_text->setStyleSheet("color: #ffffff;"
                                "font-size: 18px;"
                                "font-weight: bold;");
    minutes_text->hide();
    seconds_text = new QLabel("Сек.", this);
    createLabel(seconds_text, 320, 520);
    seconds_text->setStyleSheet("color: #ffffff;"
                                "font-size: 18px;"
                                "font-weight: bold;");
    seconds_text->hide();


    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(8);
    layout->addWidget(systemDrawer);
    layout->addWidget(juperosDrawer);
    layout->addWidget(planetName);
    layout->addWidget(planetView);
    layout->addWidget(satelliteName);
    layout->addWidget(satelliteView);
    layout->addWidget(topFiller);
    layout->addWidget(infoLabel);
    layout->addWidget(bottomFiller);
    widget->setLayout(layout);

    createActions();
    createMenus();

    static_param = new QFrame(this);
    static_param->move(600, 60);
    static_param->setFixedSize(400, 250);
    static_param->hide();

    dynamic_param = new QFrame(this);
    dynamic_param->move(600, 450);
    dynamic_param->setFixedSize(350, 250);
    dynamic_param->hide();

    static_text_mass = new QLabel("Масса", static_param);
    createLabel(static_text_mass, 30, 50);
    static_text_period = new QLabel("Период", static_param);
    createLabel(static_text_period, 30, 100);
    static_text_ugl_V = new QLabel("Угловая скорость", static_param);
    createLabel(static_text_ugl_V, 30, 150);

    planet_mass = new QLabel(static_param);
    createLabel(planet_mass, 220, 50);
    planet_mass->setFixedSize(200, 20);
    planet_period = new QLabel(static_param);
    createLabel(planet_period, 220, 100);
    planet_period->setFixedSize(200, 20);
    planet_ugl_V = new QLabel(static_param);
    createLabel(planet_ugl_V, 220, 153);
    planet_ugl_V->setFixedSize(200, 20);

    dynamic_text_distance = new QLabel("Расстояние до Солнца", dynamic_param);
    createLabel(dynamic_text_distance, 30, 60);
    dynamic_text_distance->setFixedSize(350, 20);
    dynamic_text_ugol = new QLabel("Текущий угол", dynamic_param);
    createLabel(dynamic_text_ugol, 30, 140);

    planet_distance = new QLabel(dynamic_param);
    createLabel(planet_distance, 150, 90);
    planet_distance->setFixedSize(200, 20);
    planet_ugol = new QLabel(dynamic_param);
    createLabel(planet_ugol, 220, 140);
    planet_ugol->setFixedSize(200, 20);

    QString message = tr("Контекстное меню доступно при помощи правой клавиши мыши");
    statusBar()->showMessage(message);

    setWindowTitle(tr("Симулятор звездной системы"));
    setMinimumSize(160, 160);
    resize(730, 525);
}

void MainWindow::createLabel(QLabel* label, int x, int y)
{
   label->setStyleSheet("color: #ffffff;"
                        "font-size: 20px;"
                        "font-weight: bold;");
   label->move(x, y);
   label->show();
}

void MainWindow::createLine(QLineEdit *line, int x, int y)
{
    line->move(x, y);
    line->resize(60, 20);
    line->setStyleSheet("font-weight: bold;"
                        "font-size: 14px;");
    line->hide();
}

void MainWindow::updateLabel()
{
    Planet& planet = juperos->getPlanet(11);
    if (current_system == "solar") {
        planet = system->getPlanet(current_planet);
        dynamic_text_distance->setText("Расстояние до Солнца");
    }
    if (current_system == "juperos"){
        planet = juperos->getPlanet(current_planet);
        dynamic_text_distance->setText("Расстояние до Юпитера");
    }

    Time time = planet.periodAroundSun();
    double number = time.fromSecondstoYears();
    QString string_number = QString::number(number);
    planet_period->setText(string_number);
    planet_period->show();

    number = planet.sunDistance();
    string_number = QString::number(number);
    planet_distance->setText(string_number);
    planet_distance->show();

    number = planet.linearVelocity();
    string_number = QString::number(number);
    planet_ugl_V->setText(string_number);
    planet_ugl_V->show();

    number = planet.getTheta();
    string_number = QString::number(number);
    planet_ugol->setText(string_number);
    planet_ugol->show();

    number = planet.getMass();
    string_number = QString::number(number);
    planet_mass->setText(string_number);
    planet_mass->show();
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
    infoLabel->setText(tr("Вызвано <b>Помощь|О проекте</b>"));
    QMessageBox::about(this, tr("О проекте"),
            tr("Simulator of Solar System created by Aleksandra Orova"));
}

void MainWindow::aboutQt()
{
    infoLabel->setText(tr("Invoked <b>Help|About Qt</b>"));
}
void MainWindow::createActions()
{
    aboutAct = new QAction(tr("&О проекте"), this);
    aboutAct->setStatusTip(tr("Выбор краткой анотации к проекту"));
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

    aboutQtAct = new QAction(tr("&О Qt"), this);
    aboutQtAct->setStatusTip(tr("Показать библиотеки Qt"));
    connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(aboutQtAct, &QAction::triggered, this, &MainWindow::aboutQt);

    planets[0] = new QAction(tr("&Меркурий"), this);
    planets[0]->setStatusTip(tr("Выбор Меркурий"));
    connect(planets[0], &QAction::triggered, this, &MainWindow::Planet1);
    planets[1] = new QAction(tr("&Венера"), this);
    planets[1]->setStatusTip(tr("Выбор Венера"));
    connect(planets[1], &QAction::triggered, this, &MainWindow::Planet2);
    planets[2] = new QAction(tr("&Земля"), this);
    planets[2]->setStatusTip(tr("Выбор Земля"));
    connect(planets[2], &QAction::triggered, this, &MainWindow::Planet3);
    planets[3] = new QAction(tr("&Марс"), this);
    planets[3]->setStatusTip(tr("Выбор Марс"));
    connect(planets[3], &QAction::triggered, this, &MainWindow::Planet4);
    planets[4] = new QAction(tr("&Юпитер"), this);
    planets[4]->setStatusTip(tr("Выбор Юпитер"));
    connect(planets[4], &QAction::triggered, this, &MainWindow::Planet5);
    planets[5] = new QAction(tr("&Сатурн"), this);
    planets[5]->setStatusTip(tr("Выбор Сатурн"));
    connect(planets[5], &QAction::triggered, this, &MainWindow::Planet6);
    planets[6] = new QAction(tr("&Уран"), this);
    planets[6]->setStatusTip(tr("Выбор Уран"));
    connect(planets[6], &QAction::triggered, this, &MainWindow::Planet7);
    planets[7] = new QAction(tr("&Нептун"), this);
    planets[7]->setStatusTip(tr("Выбор Нептун"));
    connect(planets[7], &QAction::triggered, this, &MainWindow::Planet8);

    planetsInfo = new QAction(tr("Демонстрация движения"), this);
    planetsInfo->setStatusTip(tr("Демонстрация движения планет"));
    connect(planetsInfo, &QAction::triggered, this, &MainWindow::PlanetMotionShow);

    satellites[0] = new QAction(tr("&Метида"), this);
    satellites[0]->setStatusTip(tr("Выбор Метида"));
    connect(satellites[0], &QAction::triggered, this, &MainWindow::Satellite1);
    satellites[1] = new QAction(tr("&Адрастея"), this);
    satellites[1]->setStatusTip(tr("Выбор Адрастея"));
    connect(satellites[1], &QAction::triggered, this, &MainWindow::Satellite2);
    satellites[2] = new QAction(tr("&Амальтея"), this);
    satellites[2]->setStatusTip(tr("Выбор Амальтея"));
    connect(satellites[2], &QAction::triggered, this, &MainWindow::Satellite3);
    satellites[3] = new QAction(tr("&Тебя"), this);
    satellites[3]->setStatusTip(tr("Выбор Тебя"));
    connect(satellites[3], &QAction::triggered, this, &MainWindow::Satellite4);
    satellites[4] = new QAction(tr("&Ио"), this);
    satellites[4]->setStatusTip(tr("Выбор Ио"));
    connect(satellites[4], &QAction::triggered, this, &MainWindow::Satellite5);
    satellites[5] = new QAction(tr("&Европа"), this);
    satellites[5]->setStatusTip(tr("Выбор Европа"));
    connect(satellites[5], &QAction::triggered, this, &MainWindow::Satellite6);
    satellites[6] = new QAction(tr("&Ганимед"), this);
    satellites[6]->setStatusTip(tr("Выбор Ганимед"));
    connect(satellites[6], &QAction::triggered, this, &MainWindow::Satellite7);
    satellites[7] = new QAction(tr("&Каллисто"), this);
    satellites[7]->setStatusTip(tr("Выбор Каллисто"));
    connect(satellites[7], &QAction::triggered, this, &MainWindow::Satellite8);
    satellites[8] = new QAction(tr("&Леда"), this);
    satellites[8]->setStatusTip(tr("Выбор Леда"));
    connect(satellites[8], &QAction::triggered, this, &MainWindow::Satellite9);
    satellites[9] = new QAction(tr("&Гималия"), this);
    satellites[9]->setStatusTip(tr("Выбор Гималия"));
    connect(satellites[9], &QAction::triggered, this, &MainWindow::Satellite10);
    satellites[10] = new QAction(tr("&Лизистея"), this);
    satellites[10]->setStatusTip(tr("Выбор Лизистея"));
    connect(satellites[10], &QAction::triggered, this, &MainWindow::Satellite11);
    satellites[11] = new QAction(tr("&Илара"), this);
    satellites[11]->setStatusTip(tr("Выбор Илара"));
    connect(satellites[11], &QAction::triggered, this, &MainWindow::Satellite12);
    satellites[12] = new QAction(tr("&Ананке"), this);
    satellites[12]->setStatusTip(tr("Выбор Ананке"));
    connect(satellites[12], &QAction::triggered, this, &MainWindow::Satellite13);
    satellites[13] = new QAction(tr("&Карме"), this);
    satellites[13]->setStatusTip(tr("Выбор Карме"));
    connect(satellites[13], &QAction::triggered, this, &MainWindow::Satellite14);
    satellites[14] = new QAction(tr("&Пасифе"), this);
    satellites[14]->setStatusTip(tr("Выбор Пасифе"));
    connect(satellites[14], &QAction::triggered, this, &MainWindow::Satellite15);
    satellites[15] = new QAction(tr("&Синопе"), this);
    satellites[15]->setStatusTip(tr("Выбор Синопе"));
    connect(satellites[15], &QAction::triggered, this, &MainWindow::Satellite16);

    satellitesInfo = new QAction(tr("Демонстрация движения"), this);
    satellitesInfo->setStatusTip(tr("Демонстрация движения планет"));
    connect(satellitesInfo, &QAction::triggered, this, &MainWindow::SatelliteMotionShow);
}

void MainWindow:: Planet1()
{   if(planetTimer->isActive())
        planetTimer->stop();
    systemDrawer->hide();
    current_system = "solar";
    current_planet = 1;
    hideSatellite();
    hidePlanet();
    updateLabel();
    planetView->setPixmap(QPixmap(":/mercury.jpg"));
    planetName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Меркурий</center></h1></font>"));
    showPlanet(0);
}
void MainWindow:: Planet2()
{
    if(satelliteTimer->isActive())
        satelliteTimer->stop();
    juperosDrawer->hide();
    current_system = "solar";
    current_planet = 2;
    hideSatellite();
    hidePlanet();
    updateLabel();
    planetView->setPixmap(QPixmap(":/venus.jpg"));
    planetName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Венера</center></h1></font>"));
    showPlanet(1);
}
void MainWindow:: Planet3()
{
    hideSatellite();
    hidePlanet();
    current_system = "solar";
    current_planet = 3;
    updateLabel();
    planetView->setPixmap(QPixmap(":/earth.jpg"));
    planetName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Земля</center></h1></font>"));
    showPlanet(2);
}
void MainWindow:: Planet4()
{
    hideSatellite();
    hidePlanet();
    current_system = "solar";
    current_planet = 4;
    updateLabel();
    planetView->setPixmap(QPixmap(":/mars.jpg"));
    planetName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Марс</center></h1></font>"));
    showPlanet(3);
}
void MainWindow:: Planet5()
{
    hideSatellite();
    hidePlanet();
    current_system = "solar";
    current_planet = 5;
    updateLabel();
    planetView->setPixmap(QPixmap(":/juperos.jpg"));
    planetName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Юпитер</center></h1></font>"));
    showPlanet(4);
}
void MainWindow:: Planet6()
{
    hideSatellite();
    hidePlanet();
    current_system = "solar";
    current_planet = 6;
    updateLabel();
    planetView->setPixmap(QPixmap(":/saturn.jpg"));
    planetName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Сатурн</center></h1></font>"));
    showPlanet(5);
}
void MainWindow:: Planet7()
{
    hideSatellite();
    hidePlanet();
    current_system = "solar";
    current_planet = 7;
    updateLabel();
    planetView->setPixmap(QPixmap(":/uranus.jpg"));
    planetName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Уран</center></h1></font>"));
    showPlanet(6);
}
void MainWindow:: Planet8()
{
    hideSatellite();
    hidePlanet();
    current_system = "solar";
    current_planet = 8;
    updateLabel();
    planetView->setPixmap(QPixmap(":/neptun.jpg"));
    planetName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Нептун</center></h1></font>"));
    showPlanet(7);
}

void MainWindow:: Satellite1()
{
    hidePlanet();
    hideSatellite();
    current_system = "juperos";
    current_planet = 1;
    updateLabel();
    satelliteView->setPixmap(QPixmap(":/Metida.jpg"));
    satelliteName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Метида</center></h1></font>"));
    showSatellite(0);
}
void MainWindow:: Satellite2()
{
    hidePlanet();
    hideSatellite();
    current_system = "juperos";
    current_planet = 2;
    updateLabel();
    satelliteView->setPixmap(QPixmap(":/adrastea.jpg"));
    satelliteName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Адрастея</center></h1></font>"));
    showSatellite(1);
}
void MainWindow:: Satellite3()
{
    hidePlanet();
    hideSatellite();
    current_system = "juperos";
    current_planet = 3;
    updateLabel();
    satelliteView->setPixmap(QPixmap(":/Amalthea.jpg"));
    satelliteName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Амальтея</center></h1></font>"));
    showSatellite(2);
}
void MainWindow:: Satellite4()
{
    hidePlanet();
    hideSatellite();
    current_system = "juperos";
    current_planet = 4;
    updateLabel();
    satelliteView->setPixmap(QPixmap(":/Teba.jpg"));
    satelliteName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Теба</center></h1></font>"));
    showSatellite(3);
}
void MainWindow:: Satellite5()
{
    hidePlanet();
    hideSatellite();
    current_system = "juperos";
    current_planet = 5;
    updateLabel();
    satelliteView->setPixmap(QPixmap(":/Io.jpg"));
    satelliteName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Ио</center></h1></font>"));
    showSatellite(4);
}
void MainWindow:: Satellite6()
{
    hidePlanet();
    hideSatellite();
    current_system = "juperos";
    current_planet = 6;
    updateLabel();
    satelliteView->setPixmap(QPixmap(":/europa.jpg"));
    satelliteName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Европа</center></h1></font>"));
    showSatellite(5);
}
void MainWindow:: Satellite7()
{
    hidePlanet();
    hideSatellite();
    current_system = "juperos";
    current_planet = 7;
    updateLabel();
    satelliteView->setPixmap(QPixmap(":/Ganimed.jpg"));
    satelliteName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Ганимед</center></h1></font>"));
    showSatellite(6);
}
void MainWindow:: Satellite8()
{
    hidePlanet();
    hideSatellite();
    current_system = "juperos";
    current_planet = 8;
    updateLabel();
    satelliteView->setPixmap(QPixmap(":/Kallisto.jpg"));
    satelliteName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Каллисто</center></h1></font>"));
    showSatellite(7);
}
void MainWindow:: Satellite9()
{
    hidePlanet();
    hideSatellite();
    current_system = "juperos";
    current_planet = 9;
    updateLabel();
    satelliteView->setPixmap(QPixmap(":/Leda.jpg"));
    satelliteName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Леда</center></h1></font>"));
    showSatellite(8);
}
void MainWindow:: Satellite10()
{
    hidePlanet();
    hideSatellite();
    current_system = "juperos";
    current_planet = 10;
    updateLabel();
    satelliteView->setPixmap(QPixmap(":/Gimalia.jpg"));
    satelliteName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Гималия</center></h1></font>"));
    showSatellite(9);
}
void MainWindow:: Satellite11()
{
    hidePlanet();
    hideSatellite();
    current_system = "juperos";
    current_planet = 11;
    updateLabel();
    satelliteView->setPixmap(QPixmap(":/Lizistea.jpg"));
    satelliteName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Лизистея</center></h1></font>"));
    showSatellite(10);
}
void MainWindow:: Satellite12()
{
    hidePlanet();
    hideSatellite();
    current_system = "juperos";
    current_planet = 12;
    updateLabel();
    satelliteView->setPixmap(QPixmap(":/Ilara.jpg"));
    satelliteName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Илара</center></h1></font>"));
    showSatellite(11);
}
void MainWindow:: Satellite13()
{
    hidePlanet();
    hideSatellite();
    current_system = "juperos";
    current_planet = 13;
    updateLabel();
    satelliteView->setPixmap(QPixmap(":/Ananke.jpg"));
    satelliteName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Ананке</center></h1></font>"));
    showSatellite(12);
}
void MainWindow:: Satellite14()
{
    hidePlanet();
    hideSatellite();
    current_system = "juperos";
    current_planet = 14;
    updateLabel();
    satelliteView->setPixmap(QPixmap(":/Karme.jpg"));
    satelliteName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Карме</center></h1></font>"));
    showSatellite(13);
}
void MainWindow:: Satellite15()
{
    hidePlanet();
    hideSatellite();
    current_system = "juperos";
    current_planet = 15;
    updateLabel();
    satelliteView->setPixmap(QPixmap(":/Pasife.jpg"));
    satelliteName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Писифе</center></h1></font>"));
    showSatellite(14);
}
void MainWindow:: Satellite16()
{
    hidePlanet();
    hideSatellite();
    current_system = "juperos";
    current_planet = 16;
    updateLabel();
    satelliteView->setPixmap(QPixmap(":/Sinope.jpg"));
    satelliteName->setText(tr("<font style=\"color:#fff; font-family:Times New Roman; font-size:40pt;\"><h1><center>Синопе</center></h1></font>"));
    showSatellite(15);
}

void MainWindow:: PlanetInfoShow()
{
    hidePlanet();
    hideSatellite();
    if (planetTimer->isActive())
        planetTimer->stop();
}
void MainWindow:: SatelliteInfoShow()
{
    hidePlanet();
    hideSatellite();
    if (satelliteTimer->isActive())
        satelliteTimer->stop();
}

void MainWindow:: createMenus()
{
    project = menuBar()->addMenu(tr("&Проект"));
    project->addAction(aboutAct);
    project->addAction(aboutQtAct);

    solarSystemView = menuBar()->addMenu(tr("&Солнечная система"));
    for (int i = 0; i < 8; i++)
        solarSystemView->addAction(planets[i]);
    solarSystemView->addSeparator();
    solarSystemView->addAction(planetsInfo);

    juperosView = menuBar()->addMenu(tr("&Юпитер и спутники"));
    for (int i = 0; i < 16; i++)
        juperosView->addAction(satellites[i]);
    juperosView->addSeparator();
    juperosView->addAction(satellitesInfo);
}

void MainWindow:: hidePlanet(){
    //step_delta->hide();
    infoLabel->hide();
    planetView->hide();
    planetName->hide();
    static_param->hide();
    dynamic_param->hide();
    days_text->hide();
    minutes_text->hide();
    hours_text->hide();
    seconds_text->hide();
    days->hide();
    hours->hide();
    minutes->hide();
    seconds->hide();
    step_delta->hide();
}
void MainWindow:: hideSatellite(){
    //step_delta->hide();
    infoLabel->hide();
    satelliteView->hide();
    satelliteName->hide();
    static_param->hide();
    dynamic_param->hide();
    days_text->hide();
    minutes_text->hide();
    hours_text->hide();
    seconds_text->hide();
    days->hide();
    hours->hide();
    minutes->hide();
    seconds->hide();
    step_delta->hide();
}

void MainWindow:: showPlanet(int id){
    if(planetTimer->isActive())
        planetTimer->stop();
    systemDrawer->hide();
    //step_delta->show();
    planetView->show();
    planetName->show();
    static_param->show();
    dynamic_param->show();
    days_text->show();
    minutes_text->show();
    hours_text->show();
    seconds_text->show();
    days->show();
    hours->show();
    minutes->show();
    seconds->show();
    step_delta->show();
    //connect(step_delta, SIGNAL(clicked()), SLOT(SolarSystem::PlanetInfoShow));
}
void MainWindow:: showSatellite(int id){
    if(satelliteTimer->isActive())
        satelliteTimer->stop();
    juperosDrawer->hide();
    //step_delta->show();
    satelliteView->show();
    satelliteName->show();
    static_param->show();
    dynamic_param->show();
    days_text->show();
    minutes_text->show();
    hours_text->show();
    seconds_text->show();
    days->show();
    hours->show();
    minutes->show();
    seconds->show();
    step_delta->show();
    //connect(step_delta, SIGNAL(clicked()), SLOT(SolarSystem::PlanetInfoShow));
}

void MainWindow:: PlanetMotionShow(){
    hidePlanet();
    systemDrawer->show();
    planetTimer->start(20);
}
void MainWindow:: movePlanet(){
    system->step(60*60*24*10); //10 days
    systemDrawer->repaint();
}

void MainWindow::moveInTime()
{
    double delta = 0;
    QString number = days->text();
    double num = number.toDouble();
    delta = num;
    number = hours->text();
    num = number.toDouble();
    delta = 24 * delta + num;
    number = minutes->text();
    num = number.toDouble();
    delta = 60 * delta + num;
    number = seconds->text();
    num = number.toDouble();
    delta = 60 * delta + num;

    if (current_system == "solar") {
        Planet& planet = system->getPlanet(current_planet);
        planet.step(delta);
    }
    if (current_system == "juperos") {
        Planet& planet = juperos->getPlanet(current_planet);
        planet.step(delta);
    }
    updateLabel();
}

void MainWindow:: SatelliteMotionShow(){
    hideSatellite();
    juperosDrawer->show();
    satelliteTimer->start(20);
}
void MainWindow:: moveSatellite(){
    juperos->step(60*60); //10 days
    juperosDrawer->repaint();
}
