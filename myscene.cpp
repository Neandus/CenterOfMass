#include "myscene.h"
#include <QPointF>
#include <QGraphicsItem>

constexpr qreal point_size = 4;

MyScene::MyScene(QWidget *parent) : QGraphicsScene(parent)
{
    mPen = std::make_unique<QPen>();
}

MyScene::~MyScene()
{
    if(mPixmap != nullptr)
    {
        delete mPixmap;
    }
}

void MyScene::setPixmap(QGraphicsPixmapItem *pixmap)
{
    if(mPixmap != nullptr)
    {
        delete mPixmap;
    }

    mPixmap = pixmap;
}

void MyScene::cleanImage()
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

void MyScene::addAxis()
{
    if(mAxis == nullptr)
        mSetAxis = true;
}

void MyScene::addPoint()
{
    mSetPoint = true;
}

void MyScene::changeBrush(std::pair<QColor, int> newPen)
{
    mPenColor = newPen.first;
    mPenWidth = newPen.second;

    mPen->setColor(mPenColor);
    mPen->setWidth(mPenWidth);
}

void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(mPixmap != nullptr)
    {
        if(mSetAxis)
        {
            if(mAxis == nullptr)
            {
                QPointF pos = event->scenePos();
                mAxis = this->addLine(pos.x(), 0, pos.x(), this->height(), *mPen);
            }
        }
        else if(mSetPoint)
        {
            QPointF pos = event->scenePos();
            mPoints.push_back(this->addEllipse(pos.x() - (point_size/2),
                                               pos.y() - (point_size/2),
                                               point_size, point_size, *mPen));
        }
        else
        {
            //nothig to do here
        }
    }

    mSetAxis = false;
    mSetPoint = false;
}

