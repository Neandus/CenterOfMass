#include "mygraphicviewer.h"
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>
#include <QMouseEvent>

constexpr qreal point_size = 4;

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
    if(mAxis != nullptr)
    {
        delete mAxis;
        mAxis = nullptr;
    }

    std::for_each(std::begin(mPoints), std::end(mPoints), [](QGraphicsEllipseItem* & point) {
            delete point;
            point = nullptr;
    });

    if(mPoints.size())
    {
        mPoints.clear();
    }
}

void MyGraphicViewer::addAxis()
{
    if(mAxis == nullptr)
        mSetAxis = true;
}

void MyGraphicViewer::addPoint()
{
    mSetPoint = true;
}

void MyGraphicViewer::changeBrush()
{
    //TODO: Implement something here
}

void MyGraphicViewer::mousePressEvent(QMouseEvent *event)
{
    if(mSetAxis)
    {
        if(mAxis == nullptr)
        {
            mAxis = mScene->addLine(event->pos().x(), 0,
                                    event->pos().x(), mScene->height());
        }
    }
    else if(mSetPoint)
    {
        mPoints.push_back(mScene->addEllipse(event->pos().x() - (point_size/2),
                                             event->pos().y() - (point_size/2),
                                             point_size, point_size));
    }
    else
    {
        //nothig to do here
    }

    mSetAxis = false;
    mSetPoint = false;
}
