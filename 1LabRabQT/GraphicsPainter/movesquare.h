#ifndef MOVEITEM_H
#define MOVEITEM_H
#include "info.h"
#include "viewsquare.h"
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <cmath>
class ViewSquare;
class Quadrate : public QObject, public QGraphicsItem
{
    friend ViewSquare;
    Q_OBJECT
public:
    explicit Quadrate(QObject *parent = 0);
    ~Quadrate();
    int X;
    int Y;
    int Width;
    int Height;
    int XShift;
    int YShift;
    double root;
    char type;
double size;
double newWidth;
double newHeight;
int Square;
int Perimetr;
protected:

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void wheelEvent(QGraphicsSceneWheelEvent *event) override;
     void keyPressEvent(QKeyEvent *event) override;
    // QGraphicsItem interface
    // QGraphicsItem interface
    double degree;

    void keyReleaseEvent(QKeyEvent *event) override;


};

#endif // MOVEITEM\_H
