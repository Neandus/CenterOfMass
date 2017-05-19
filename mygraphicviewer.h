#ifndef MYGRAPHICVIEWER_H
#define MYGRAPHICVIEWER_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <atomic>
#include <memory>

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
    void changeBrush();

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
private:
    QString mWorksapcePath;
    QGraphicsScene *mScene;
    QGraphicsLineItem *mAxis{nullptr};
    std::vector<QGraphicsEllipseItem*> mPoints;
    std::unique_ptr<QPen> mPen;

    std::atomic_bool mSetAxis{false};
    std::atomic_bool mSetPoint{false};
};

#endif // MYGRAPHICVIEWER_H
