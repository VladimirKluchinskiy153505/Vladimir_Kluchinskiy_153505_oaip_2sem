#include "info.h"
#include "ui_info.h"
#include "movesquare.h"
#include <QMessageBox>
#include <QDebug>
Info::Info(QWidget *parent) :
    QWidget(parent),
    ui2(new Ui::Info)
{
    ui2->setupUi(this);
}
Quadrate* Info:: obj=nullptr;
Info::~Info()
{
    delete ui2;
}

void Info::on_save_information_clicked()
{
    if(obj==nullptr){
        QMessageBox::warning(this,"The Object wasn't selected","Select It!\n");
        close();
    }
    else{
  QString Xcor=ui2->X_coordinate->text();
  QString Ycor=ui2->Y_coordinate->text();
  QString WidthVal=ui2->lineWidth->text();
  QString HeightVal=ui2->lineHeight->text();
  qDebug()<<Xcor<<" "<<Ycor<<'\n';

qDebug()<<WidthVal<<" "<<HeightVal<<'\n';

int xcor=Xcor.toInt(nullptr,10);
int ycor=Ycor.toInt(nullptr,10);
int Wv=WidthVal.toInt(nullptr,10);
int Hv=HeightVal.toInt(nullptr,10);


  obj->X=Xcor.toInt(nullptr,10);
 obj->Y=Ycor.toInt(nullptr,10);
if(!Wv||!Hv){
    QMessageBox::information(this,"Error","Please enter a size");
}
else{
 obj->Width=Wv;
 obj->Height=Hv;
}
 //qDebug()<<obj->Width<<" "<<obj->Height<<'\n';
  obj->setPos(obj->X,obj->Y);
    }
}

