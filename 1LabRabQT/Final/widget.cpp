#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include <QPainter>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene=new QGraphicsScene(0,0,1920,980,this);
    scene->setBackgroundBrush(QBrush(Qt::white));
    ui->graphicsView->setScene(scene);
    scene->addRect(scene->sceneRect());

QColor color_face=QColor(0,188,63);
    Ellipse* face=new Ellipse(QPointF(scene->width()/2-500,scene->height()/2-400),color_face,1000,800,100,nullptr);
    scene->addItem(face);

    Triangle* nose=new Triangle(face);
    face->scene()->addItem(nose);

qDebug()<<face->x();

QColor color_eye1=QColor(255,221,0);
    Eye* eye1=new Eye(QPoint(face->boundingRect().width()/4-30,face->y()+100),color_eye1,200,120,20,face);
    face->scene()->addItem(eye1);

    Zrachok* zrachok=new Zrachok(eye1);
    eye1->scene()->addItem(zrachok);

    QColor color_eye2=QColor(110,26,194);
        Eye* eye2=new Eye(QPoint(face->boundingRect().width()/4*3-200+30,face->y()+100),color_eye2,200,120,20,face);
        face->scene()->addItem(eye2);

        Zrachok* zrachok2=new Zrachok(eye2);
        eye1->scene()->addItem(zrachok2);

        QColor color_lips=QColor(124,14,14);
        UpLips* lip_1=new UpLips(QPoint(350,600),color_lips,300,50,10,face);
        face->scene()->addItem(lip_1);

        LowLips* lip_2=new LowLips(QPoint(350,650),color_lips,300,50,10,face);
        face->scene()->addItem(lip_1);

    animationTimer=new QTimer(this);
    connect(animationTimer,SIGNAL(timeout()),scene,SLOT(advance()));
    // connect(animationTimer,SIGNAL(timeout()),scene,SLOT(advance()));
    animationTimer->start(1000/100);
}

Widget::~Widget()
{
    delete ui;
}

Ellipse::Ellipse(QPointF initPos,QColor color, int w, int h, int spread, QGraphicsItem *parent):QGraphicsEllipseItem(parent)
{
    xspeed=1;
    yspeed=1;
    flag1=true;
    flag2=true;
    this->InitPos=initPos;
    this->Spread=spread;
   this-> Color=color;
    setBrush(Color);
    setRect(0,0,w,h);
    setPos(initPos);
}

void Ellipse::advance(int phase)
{
    if(!Spread){
moveBy(0,0);
    }
int x_left_bound=this->InitPos.x()-Spread;
int x_right_bound=this->InitPos.x()+Spread;
int y_upper_bound=this->InitPos.y()-Spread;
if(phase){
    if(flag1&&flag2){
    moveBy(xspeed,yspeed);
    if(this->x()>x_right_bound)
        this->change2();
    }
    else if(flag1&&!flag2){
        moveBy(0,-yspeed);
        if(this->y()<y_upper_bound){
            this->change1();
        this->change2();
        }
    }else if(!flag1&&flag2){
        moveBy(-xspeed,yspeed);
        if(this->x()<x_left_bound){
            this->change2();
        }
    }
    else{
        moveBy(0,-yspeed);
        if(this->y()<y_upper_bound){
            this->change1();
            this->change2();
        }
    }
}
}

void Ellipse::change1(){
    flag1=!flag1;
}

void Ellipse::change2(){
    flag2=!flag2;
}


Eye::Eye(QPointF initPos,QColor color, int w, int h, int spread, QGraphicsItem *parent):Ellipse(initPos,color,w,h,spread,parent)
{
}

Eye::~Eye()
{

}

Triangle::Triangle(QGraphicsEllipseItem *parent):QGraphicsItem(parent)
{
}

Triangle::~Triangle()
{

}

QRectF Triangle::boundingRect() const
{
return QRectF(-25,-40,50,80);
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPolygon polygon;   // Используем класс полигона, чтобы отрисовать треугольник
    // Помещаем координаты точек в полигональную модель
    polygon << QPoint(500,150) << QPoint(400,500) << QPoint(600,500);
    painter->setBrush(Qt::red);     // Устанавливаем кисть, которой будем отрисовывать объект
    painter->drawPolygon(polygon);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

UpLips::UpLips(QPointF initPos, QColor color, int w, int h, int spread, QGraphicsItem *parent):Ellipse( initPos,color,w, h,  spread, parent)
{
    xspeed=1;
    yspeed=1;
    flag=true;
    this->InitPos=initPos;
    this->Spread=spread;
   this-> Color=color;
    setBrush(Color);
    setRect(0,0,w,h);
    setPos(initPos);
}

void UpLips::advance(int phase)
{
    if(flag){
    moveBy(0,-0.5);
    if(this->y()<575){
        change();
      }
    }
    else{
        moveBy(0,0.5);
        if(this->y()>600){
            change();
        }
    }

}

void UpLips::change()
{
    flag=!flag;
}

LowLips::LowLips(QPointF initPos, QColor color, int w, int h, int spread, QGraphicsItem *parent):Ellipse( initPos,color,w, h,  spread, parent)
{
    xspeed=1;
    yspeed=1;
    flag=true;
    this->InitPos=initPos;
    this->Spread=spread;
   this-> Color=color;
    setBrush(Color);
    setRect(0,0,w,h);
    setPos(initPos);
}

void LowLips::advance(int phase)
{
    if(flag){
    moveBy(0,0.5);
    if(this->y()>675){
        change();
      }
    }
    else{
        moveBy(0,-0.5);
        if(this->y()<650){
            change();
        }
    }
}

void LowLips::change()
{
     flag=!flag;
}

Zrachok::Zrachok(QGraphicsEllipseItem *parrent):QGraphicsItem(parrent)
{

}

Zrachok::~Zrachok()
{

}

QRectF Zrachok::boundingRect() const
{
return QRectF(0,0,70,70);
}

void Zrachok::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);     // Устанавливаем кисть, которой будем отрисовывать объект
    painter->drawEllipse(65,25,70,70);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
