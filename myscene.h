#ifndef MYSCENE_H
#define MYSCENE_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QPen>
#include <atomic>
#include <memory>

class MyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MyScene(QWidget *parent = 0);
    ~MyScene();

    void setPixmap(QGraphicsPixmapItem *pixmap);
    QColor mPenColor{ 0, 0, 0};
    int mPenWidth{};

signals:

public slots:
    void cleanImage();
    void changeBrush(std::pair<QColor, int> newPen);
    void addAxis();
    void addPoint();

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:

    QGraphicsPixmapItem *mPixmap{nullptr};
    QGraphicsLineItem *mAxis{nullptr};
    std::vector<QGraphicsEllipseItem*> mPoints;
    std::unique_ptr<QPen> mPen;

    std::atomic_bool mSetAxis{false};
    std::atomic_bool mSetPoint{false};

};

#endif // MYSCENE_H
