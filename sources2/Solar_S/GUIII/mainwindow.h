#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QActionGroup;
class QLabel;
class QMenu;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected:
    void contextMenuEvent(QContextMenuEvent *event) Q_DECL_OVERRIDE;

private slots:
    void newFile();
    void open();
    void save();
    void print();
    void undo();
    void redo();
    void cut();
    void copy();
    void paste();
    void bold();
    void italic();
    void leftAlign();
    void rightAlign();
    void justify();
    void center();
    void setLineSpacing();
    void setParagraphSpacing();

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

private:
    void createActions();
    void createMenus();

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *formatMenu;
    QMenu *helpMenu;
    QActionGroup *alignmentGroup;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *printAct;
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
};

#endif
