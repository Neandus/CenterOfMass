#ifndef MYGRAPHICVIEWER_H
#define MYGRAPHICVIEWER_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

class MyGraphicViewer : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyGraphicViewer(QWidget *parent = 0);
    virtual ~MyGraphicViewer();

    void setWorkspacePath(const QString workspacePath);

signals:

public slots:
    void loadImage();
    void saveImage();
    void cleanImage();
    void addAxis();
    void addPoint();

private:
    QString mWorksapcePath;
    QGraphicsScene *mScene;
    QGraphicsLineItem  *mAxis{nullptr};
    std::vector<QGraphicsEllipseItem> mPoints;
};

#endif // MYGRAPHICVIEWER_H
