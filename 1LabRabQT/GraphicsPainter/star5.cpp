#include "star5.h"
Star5::Star5(int n,QObject *parent)
    : Quadrate{parent}
{
    a=0;
    type='5';
      this->n= n;
    r=70;
    R=90;
    centrX=Width/2;
    centrY=Height/2;
    px=new double[n*2+1];
    py=new double[n*2+1];
    for(int i=0;i<n*2+1;i++){
        if(i%2){
            px[i]=centrX+(r/2)*cos(a*3.14159/180);
            py[i]=centrY-(r/2)*sin(a*3.14159/180);

        }
        else{
            px[i]=centrX+R*cos(a*M_PI/180);
            py[i]=centrY-R*sin(a*M_PI/180);
        }
        a+=180/n;
    }
    px[n*2]=px[0];
    py[n*2]=py[0];

    star5.moveTo(px[0],py[0]);

    for(int i=0;i<2*n+1;i++){
        star5.lineTo(px[i],py[i]);
    }
}

Star5::~Star5()
{
    delete px;
     delete py;
}

void Star5::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    root=sqrt(Width*Width+Height*Height);
    newWidth=size*root*Width;
     newHeight=size*root*Height;

    if (size!=1) {
               painter->scale(size, size);
    }

    if(degree){

          painter->rotate(degree);
 }

painter->setPen(Qt::black);

painter->setBrush(Qt::darkCyan);


    painter->drawPath(star5);


    Q_UNUSED(option);
    Q_UNUSED(widget);
}
