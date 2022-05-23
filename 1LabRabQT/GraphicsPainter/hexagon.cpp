#include "hexagon.h"

Hexagon::Hexagon(QObject *parent)
    : Quadrate{parent}
{
    type ='x';
}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    root=sqrt(Width*Width+Height*Height);
    newWidth=size*root*Width;
     newHeight=size*root*Height;
    if (size!=1) {
         prepareGeometryChange();
               painter->scale(size, size);
    }

    if(degree){
       // painter->translate((this->boundingRect().width()-500)/2,(this->boundingRect().height()-500)/2);
        //  painter->translate(this->boundingRect().center().x(),this->boundingRect().center().y());

          painter->rotate(degree);

    }
    painter->setPen(Qt::black);

    QPolygonF polygon;
    polygon<<QPointF(0,Height/3)<<QPointF(0,Height*2/3)<<QPointF(Width/2,Height)<<QPointF(Width,Height*2/3)<<QPointF(Width,Height/3)<<QPointF(Width/2,0);
    painter->setBrush(Qt::cyan);

    painter->drawPolygon(polygon);


    Q_UNUSED(option);
    Q_UNUSED(widget);
}
