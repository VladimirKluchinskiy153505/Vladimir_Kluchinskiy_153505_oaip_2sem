#include "circle.h"
Circle::Circle(QObject *parent)
    : Quadrate{parent}
{
    type='c';
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    root=sqrt(Width*Width+Height*Height);
    newWidth=size*root*Width;
     newHeight=size*root*Height;
    if (size!=1) {
        // prepareGeometryChange();
               painter->scale(size, size);
    }

    if(degree){
       // painter->translate((this->boundingRect().width()-500)/2,(this->boundingRect().height()-500)/2);
        //  painter->translate(this->boundingRect().center().x(),this->boundingRect().center().y());

          painter->rotate(degree);

    }
    painter->setPen(Qt::black);
    painter->setBrush(Qt::magenta);

    painter->drawEllipse(0,0,Width,Height);


    Q_UNUSED(option);
    Q_UNUSED(widget);
}
