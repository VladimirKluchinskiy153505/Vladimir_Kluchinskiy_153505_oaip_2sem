#ifndef STAR5_H
#define STAR5_H
#include "movesquare.h"
#include "viewsquare.h"
class ViewSquare;
class Star5 : public Quadrate
{
    friend ViewSquare;
public:
    explicit Star5(int n,QObject *parent = nullptr);
    ~Star5();
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
protected:
     float a;
     int n;
     double *px;
     double *py;
     float r;
     float R;
     float centrX;
     float centrY;
      QPainterPath star5;
};

#endif // STAR5_H
