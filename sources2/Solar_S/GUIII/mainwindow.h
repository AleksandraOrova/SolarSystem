#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "planetview.h"
#include "satelliteview.h"
#include "solarsystem.h"
#include "systemdrawer.h"
#include "juperosdrawer.h"

class QAction;
class QActionGroup;
class QLabel;
class QMenu;
class QLineEdit;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    const QSize WINDOW_SIZE { 300, 90 };
    const QSize BUTTON_SIZE { 200, 50 };

public:
    MainWindow();

protected:
    void contextMenuEvent(QContextMenuEvent *event) Q_DECL_OVERRIDE;

private slots:
    void about();
    void aboutQt();

    void Planet1();
    void Planet2();
    void Planet3();
    void Planet4();
    void Planet5();
    void Planet6();
    void Planet7();
    void Planet8();
    void PlanetInfoShow();
    void PlanetMotionShow();
    void SatelliteInfoShow();
    void SatelliteMotionShow();

    void Satellite1();
    void Satellite2();
    void Satellite3();
    void Satellite4();
    void Satellite5();
    void Satellite6();
    void Satellite7();
    void Satellite8();
    void Satellite9();
    void Satellite10();
    void Satellite11();
    void Satellite12();
    void Satellite13();
    void Satellite14();
    void Satellite15();
    void Satellite16();
    void showPlanet(int id);
    void hidePlanet();
    void showSatellite(int id);
    void hideSatellite();


    void ComparePlanetsShow();
    void CompareSatellitesShow();

private:

    void createActions();
    void createMenus();

    QAction *exitAct;
    QAction *undoAct;
    QAction *redoAct;
    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;
    QAction *boldAct;
    QAction *italicAct;
    QAction *leftAlignAct;
    QAction *rightAlignAct;
    QAction *justifyAct;
    QAction *centerAct;
    QAction *setLineSpacingAct;
    QAction *setParagraphSpacingAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
    QLabel *infoLabel;
    QLineEdit *lineEdit;
    QPushButton* step_delta;

    QMenu *project;
    QAction *aboutAction;
    QAction *closeAction;

    QMenu *solarSystemView;
    QAction *planets[8];
    QAction *planetsInfo;
    QAction *comparePlanets;

    QMenu *juperosView;
    QAction *satellites[14];
    QAction *satellitesInfo;
    QAction *compareSatellites;
    QPainter *canvas;
    QWidget *widget;
    PlanetView *planetView;
    QLabel *planetName;
    SatelliteView *satelliteView;
    QLabel *satelliteName;
    SystemDrawer* systemDrawer;
    JuperosDrawer* juperosDrawer;
    SolarSystem* system;
    SolarSystem* juperos;
    QTimer* planetTimer;
    QTimer* satelliteTimer;

public slots:
    void movePlanet();
    void moveSatellite();
};

#endif
