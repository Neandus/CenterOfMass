#ifndef MYGRAPHICVIEWER_H
#define MYGRAPHICVIEWER_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "myscene.h"


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
    void changeBrush();
    void addAxis();
    void addPoint();

private:
    QString mWorksapcePath;
    MyScene *mScene;

};

#endif // MYGRAPHICVIEWER_H
