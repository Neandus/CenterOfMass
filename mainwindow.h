#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <memory>

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
    QFileSystemModel * mFileSystemModel;
    QString mWorkspacePath;

    void createActions();
    void displayWorkspace();

    void readWorkspacePath();

    void dodajPacjenta();
    void usunPacjenta();
    void wybierzFolderRoboczy();
    void Pomoc();
    void oProgramie();
};

#endif // MAINWINDOW_H
