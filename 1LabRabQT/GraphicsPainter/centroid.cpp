#include "centroid.h"
#include "ui_centroid.h"
#include <QMessageBox>
Centroid::Centroid(QWidget *parent) :
    QWidget(parent),
    ui1(new Ui::Centroid)
{
    ui1->setupUi(this);
}
Quadrate* Centroid::obj=nullptr;
Centroid::~Centroid()
{
    delete ui1;
}



void Centroid::on_Save_Centroid_Information_clicked()
{
    if(obj==nullptr){
        QMessageBox::warning(this,"The Object wasn't selected","Select It!\n");
        close();
        return;
    }
    else{
    QString Xshift=ui1->lineX_Shift->text();
    QString Yshift=ui1->lineY_Shift->text();

    obj->XShift=Xshift.toInt(nullptr,10);
    obj->YShift=Yshift.toInt(nullptr,10);
      obj->setPos(obj->x()+obj->XShift,obj->y()+obj->YShift);
    }
}

