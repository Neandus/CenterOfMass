#include "mygraphicviewer.h"
#include <QFileDialog>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include "pendialog.h"

MyGraphicViewer::MyGraphicViewer(QWidget *parent)
  : QGraphicsView(parent),
    mWorksapcePath(QDir::currentPath()),
    mScene(new MyScene)
{
    setMouseTracking(true);
    setAttribute(Qt::WA_StaticContents);
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

    QPixmap image{fileName};
    mScene->clear();
    auto pixmap = mScene->addPixmap(image);
    mScene->setPixmap(pixmap);
    show();
}

void MyGraphicViewer::saveImage()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                   "Save image",
                                                   mWorksapcePath,
                                                   "BMP Files (*.bmp);;JPEG (*.JPEG);;PNG (*.png)" );
    if (!fileName.isNull())
    {
        QPixmap pixMap = this->grab();
        pixMap.save(fileName);
    }
}

void MyGraphicViewer::cleanImage()
{
    mScene->cleanImage();
}

void MyGraphicViewer::addAxis()
{
    mScene->addAxis();
}

void MyGraphicViewer::addPoint()
{
    mScene->addPoint();
}

void MyGraphicViewer::changeBrush()
{
    auto newPen = PenDialog::getPen(this, mScene->mPenWidth, mScene->mPenColor);
    mScene->changeBrush(newPen);
}
