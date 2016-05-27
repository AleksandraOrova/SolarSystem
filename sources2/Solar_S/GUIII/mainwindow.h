#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
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

private:

    void createActions();
    void createMenus();
    void createLabel(QLabel* , int x, int y);
    void createLine(QLineEdit* , int x, int y);

    void updateLabel();

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

    QMenu *juperosView;
    QAction *satellites[14];
    QAction *satellitesInfo;
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
    QLabel* text;

    QFrame* static_param;
    QFrame* dynamic_param;
    QLabel* static_text_mass;
    QLabel* static_text_period;
    QLabel* static_text_ugl_V;
    QLabel* dynamic_text_distance;
    QLabel* dynamic_text_ugol;

    QLabel* planet_mass;
    QLabel* planet_period;
    QLabel* planet_ugl_V;
    QLabel* planet_distance;
    QLabel* planet_ugol;

    QLineEdit* days;
    QLabel* days_text;
    QLineEdit* hours;
    QLabel* hours_text;
    QLineEdit* minutes;
    QLabel* minutes_text;
    QLineEdit* seconds;
    QLabel* seconds_text;

    std::string current_system;
    int current_planet;

public slots:
    void movePlanet();
    void moveInTime();
    void moveSatellite();
};

#endif
