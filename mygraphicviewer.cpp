#include "mygraphicviewer.h"
#include <QFileDialog>
#include <QPixmap>

MyGraphicViewer::MyGraphicViewer(QWidget *parent)
  : QGraphicsView(parent),
    mWorksapcePath(QDir::currentPath()),
    mScene(new QGraphicsScene)
{
    setScene(mScene);
}

MyGraphicViewer::~MyGraphicViewer()
{
    delete mScene;
}

void MyGraphicViewer::setWorkspacePath(const QString workspacePath)
{
    mWorksapcePath = workspacePath;
}

void MyGraphicViewer::loadImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    mWorksapcePath,
                                                    tr("Images (*.png *.jpeg *.jpg *.bmp)"));

    QPixmap image(fileName);
    mScene->clear();
    mScene->addPixmap(image);
    show();
}

void MyGraphicViewer::saveImage()
{}

void MyGraphicViewer::cleanImage()
{}

void MyGraphicViewer::addAxis()
{}

void MyGraphicViewer::addPoint()
{}
