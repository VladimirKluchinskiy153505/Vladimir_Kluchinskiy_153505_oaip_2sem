#include "movesquare.h"
#include "centroid.h"
#include "viewsquare.h"
#include "info.h"
#include <QKeyEvent>
#include <QTimer>
#include <cmath>
Quadrate::Quadrate(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
size=1;
degree=0;
XShift=0;
YShift=0;
Width=90;
Height=90;
Square=Width*Height;
Perimetr=(Width+Height)*2;
root=sqrt(Width*Width+Height*Height);;
newWidth = size*root*Width;
newHeight=size*root*Height;
X=0;
Y=0;
type='q';
//QTimer* timer= new QTimer(this);
setFlag(QGraphicsItem::ItemIsFocusable);
//setFocus();
//timer->start(1000/100);
}

Quadrate::~Quadrate()
{

}

QRectF Quadrate::boundingRect() const
{

    return QRectF (-newWidth,-newHeight,newWidth*2,newHeight*2);
}

void Quadrate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
    painter->setBrush(Qt::red);

    painter->drawRect(0,0,Width,Height);


    Q_UNUSED(option);
    Q_UNUSED(widget);
}
void Quadrate::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    this->setPos(mapToScene(event->pos()));
}

void Quadrate::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void Quadrate::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Info::obj=this;
    Centroid::obj=this;
    ViewSquare::obj=this;
    Q_UNUSED(event);
}
void Quadrate::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    if (event->delta() < 0){
               size -= 0.1;
    }else if(event->delta()>0){
        size+=0.1;

    }

}

void Quadrate::keyPressEvent(QKeyEvent *event)
{

}

void Quadrate::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Left:
        degree-=5;
    break;

    case Qt::Key_Right:
        degree+=5;
        break;
    default:
        break;
    }
}
