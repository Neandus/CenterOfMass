#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mWorkspace(new Workspace(parent)),
    mSceneLeft(new QGraphicsScene),
    mSceneRight(new QGraphicsScene)
{
    ui->setupUi(this);
    createActions();
    displayWorkspace();
}

MainWindow::~MainWindow()
{
    delete mSceneLeft;
    delete mSceneRight;
    delete mWorkspace;
    delete ui;
}

void MainWindow::createActions()
{
    //MENU
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

    //PRZEGLĄDARKI
    ui->load_image_left->setStatusTip(tr("Załaduj zdjęcie"));
    ui->save_image_left->setStatusTip(tr("Zapisz zdjęcie"));
    ui->clean_image_left->setStatusTip(tr("Wyczyść zdjęcie"));
    ui->add_axis_left->setStatusTip(tr("Dodaj oś"));
    ui->add_point_left->setStatusTip(tr("Dodaj punkt"));

    ui->load_image_right->setStatusTip(tr("Załaduj zdjęcie"));
    ui->save_image_right->setStatusTip(tr("Zapisz zdjęcie"));
    ui->clean_image_right->setStatusTip(tr("Wyczyść zdjęcie"));
    ui->add_axis_right->setStatusTip(tr("Dodaj oś"));
    ui->add_point_right->setStatusTip(tr("Dodaj punkt"));

    connect(ui->load_image_left, &QPushButton::clicked, ui->graphicsView_left, &MyGraphicViewer::loadImage);
    connect(ui->save_image_left, &QPushButton::clicked, ui->graphicsView_left, &MyGraphicViewer::saveImage);
    connect(ui->clean_image_left, &QPushButton::clicked, ui->graphicsView_left, &MyGraphicViewer::cleanImage);
    connect(ui->add_axis_left, &QPushButton::clicked, ui->graphicsView_left, &MyGraphicViewer::addAxis);
    connect(ui->add_point_left, &QPushButton::clicked, ui->graphicsView_left, &MyGraphicViewer::addPoint);

    connect(ui->load_image_right, &QPushButton::clicked, ui->graphicsView_right, &MyGraphicViewer::loadImage);
    connect(ui->save_image_right, &QPushButton::clicked, ui->graphicsView_right, &MyGraphicViewer::saveImage);
    connect(ui->clean_image_right, &QPushButton::clicked, ui->graphicsView_right, &MyGraphicViewer::cleanImage);
    connect(ui->add_axis_right, &QPushButton::clicked, ui->graphicsView_right, &MyGraphicViewer::addAxis);
    connect(ui->add_point_right, &QPushButton::clicked, ui->graphicsView_right, &MyGraphicViewer::addPoint);

    ui->load_image_left->setIcon(QIcon("/home/mszadkox/git/CenterOfMass/resources/folder.svg"));
    ui->save_image_left->setIcon(QIcon("/home/mszadkox/git/CenterOfMass/resources/data-transfer-download.svg"));
    ui->clean_image_left->setIcon(QIcon("/home/mszadkox/git/CenterOfMass/resources/trash.svg"));
    ui->add_axis_left->setIcon(QIcon("/home/mszadkox/git/CenterOfMass/resources/arrow-top.svg"));
    ui->add_point_left->setIcon(QIcon("/home/mszadkox/git/CenterOfMass/resources/target.svg"));

    ui->load_image_right->setIcon(QIcon("/home/mszadkox/git/CenterOfMass/resources/folder.svg"));
    ui->save_image_right->setIcon(QIcon("/home/mszadkox/git/CenterOfMass/resources/data-transfer-download.svg"));
    ui->clean_image_right->setIcon(QIcon("/home/mszadkox/git/CenterOfMass/resources/trash.svg"));
    ui->add_axis_right->setIcon(QIcon("/home/mszadkox/git/CenterOfMass/resources/arrow-top.svg"));
    ui->add_point_right->setIcon(QIcon("/home/mszadkox/git/CenterOfMass/resources/target.svg"));
}

void MainWindow::displayWorkspace()
{
    ui->graphicsView_left->setWorkspacePath(mWorkspace->getWorkspacePath());
    ui->graphicsView_right->setWorkspacePath(mWorkspace->getWorkspacePath());
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
    ui->graphicsView_left->setWorkspacePath(mWorkspace->getWorkspacePath());
    ui->graphicsView_right->setWorkspacePath(mWorkspace->getWorkspacePath());
    displayWorkspace();
}
void MainWindow::Pomoc()
{}
void MainWindow::oProgramie()
{}
