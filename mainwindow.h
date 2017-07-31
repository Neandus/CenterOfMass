#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myscene.h"
#include "workspace.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Workspace *mWorkspace;

    MyScene * mSceneLeft;
    MyScene * mSceneRight;

    void createActions();
    void displayWorkspace();

    void dodajPacjenta();
    void usunPacjenta();
    void wybierzFolderRoboczy();
    void Pomoc();
    void oProgramie();

};

#endif // MAINWINDOW_H
