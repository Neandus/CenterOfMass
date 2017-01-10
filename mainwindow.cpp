#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QFile>
#include <QMessageBox>
#include <QDebug>
#include <QTextStream>


const char * workspace_path = ".workspace";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mFileSystemModel(new QFileSystemModel),
    mWorkspacePath(QDir::currentPath())

{
    ui->setupUi(this);
    createActions();
    displayWorkspace();
}

MainWindow::~MainWindow()
{
    delete mFileSystemModel;
    delete ui;
}

void MainWindow::createActions()
{
    ui->actionDodaj_pacjenta->setStatusTip(tr("Dodaje nowy wpis pacjenta w obecnym folderze roboczym."));
    ui->actionUsu_pacjenta->setStatusTip(tr("Usuwa zaznaczony wpis pacjenta z obecnego folderu roboczego."));
    ui->actionWybierz_folder_roboczy->setStatusTip(tr("Umożliwia zmianę folderu roboczego."));
    ui->actionO_programie->setStatusTip(tr("Wyświetla informację o programie."));
    ui->actionPomoc->setStatusTip(tr("Wyświetla pomoc."));

    connect(ui->actionDodaj_pacjenta, &QAction::triggered, this, &MainWindow::dodajPacjenta);
    connect(ui->actionUsu_pacjenta, &QAction::triggered, this, &MainWindow::usunPacjenta);
    connect(ui->actionWybierz_folder_roboczy, &QAction::triggered, this, &MainWindow::wybierzFolderRoboczy);
    connect(ui->actionPomoc, &QAction::triggered, this, &MainWindow::Pomoc);
    connect(ui->actionO_programie, &QAction::triggered, this, &MainWindow::oProgramie);
}

void MainWindow::readWorkspacePath()
{
    QFile workspaceFile(workspace_path);

    if(!workspaceFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(0, "Warning", "Workspace file has not been found! Workspace set to defualt path.");

        //create file with default path
        QFile defaultFile(workspace_path);
        if(!defaultFile.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            QMessageBox::warning(0, "Error", "Workspace file couldn't be created!");
        }
        else
        {
            QTextStream out(&defaultFile);
            out << mWorkspacePath << endl;
        }
        defaultFile.close();
    }
    else
    {
        //read workspace path
        QTextStream in(&workspaceFile);
        if(!in.atEnd()) {
            QString line = in.readLine();
            //TODO validate path
            mWorkspacePath = line;
        }
    }
    workspaceFile.close();
}

void MainWindow::displayWorkspace()
{
    readWorkspacePath();
    mFileSystemModel->setRootPath(mWorkspacePath);
    ui->treeView->setModel(mFileSystemModel);
    ui->treeView->setRootIndex(mFileSystemModel->index(mWorkspacePath));
}


void MainWindow::dodajPacjenta()
{}
void MainWindow::usunPacjenta()
{}
void MainWindow::wybierzFolderRoboczy()
{


}
void MainWindow::Pomoc()
{}
void MainWindow::oProgramie()
{}
