#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mWorkspace(new Workspace(parent))
{
    ui->setupUi(this);
    createActions();
    displayWorkspace();
}

MainWindow::~MainWindow()
{
    delete mWorkspace;
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

void MainWindow::displayWorkspace()
{
    ui->treeView->setModel(&mWorkspace->mFileSystemModel);
    ui->treeView->setRootIndex(mWorkspace->getModelIndex());
}


void MainWindow::dodajPacjenta()
{}
void MainWindow::usunPacjenta()
{}
void MainWindow::wybierzFolderRoboczy()
{
    mWorkspace->update();
    displayWorkspace();
}
void MainWindow::Pomoc()
{}
void MainWindow::oProgramie()
{}
