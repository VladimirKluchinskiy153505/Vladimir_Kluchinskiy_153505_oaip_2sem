#include "viewsquare.h"
#include "ui_viewsquare.h"
#include "movesquare.h"
#include <star5.h>
#include <QMessageBox>
#include <cmath>
ViewSquare::ViewSquare(QWidget *parent) :
    QWidget(parent),
    ui3(new Ui::ViewSquare)
{
    if(obj==nullptr){
         QMessageBox::warning(this,"The Object wasn't selected","Select It!\n");
        close() ;
        return;
    }
    else{
    ui3->setupUi(this);
    H=obj->Height;
    W=obj->Width;
     s=obj->size;
     rt=obj->root;
     tp=obj->type;
    }
}
Quadrate* ViewSquare::obj=nullptr;
ViewSquare::~ViewSquare()
{
    delete ui3;
}


void ViewSquare::on_see_square_clicked()
{
    if(obj==nullptr){
        QMessageBox::warning(this,"The Object wasn't selected","Select It!\n");
        close();
    }
    else{
        if(obj->type=='q'||obj->type=='r'){
        QMessageBox::information(this,"SQUARE","The Square is: "+QString::number(W*H*s*s));
        }
        else if(obj->type=='h'){
             QMessageBox::information(this,"SQUARE","The Square is: "+QString::number(W*H*s*s*0.5));
        }
        else if(obj->type=='c'){
            QMessageBox::information(this,"SQUARE","The Square is: "+QString::number(3.14159*H*H*s*s/4));
        }
        else if(obj->type=='x'){
            QMessageBox::information(this,"SQUARE","The Square is: "+QString::number(W*H*s*s*2/3));
        }
        else if(tp=='5'){
            double rad=dynamic_cast<Star5*>(obj)->r;
            QMessageBox::information(this,"SQUARE","The Square is: "+QString::number(3.14159*rad*rad*2*s*s));
        }
        else if(obj->type='t'){
              QMessageBox::information(this,"SQUARE","The Square is: "+QString::number(0.5*H*W*s*s));
        }
    }
}


void ViewSquare::on_see_perimetr_clicked()
{
    if(obj==nullptr){
        QMessageBox::warning(this,"The Object wasn't selected","Select It!\n");
    }
    else{
        if(tp=='q'||tp=='r'){
        QMessageBox::information(this,"Perimetr","The Perimetr is: "+QString::number((W+H)*2*s));
        }
        else if(tp=='h'){
             QMessageBox::information(this,"Perimetr","The Perimetr is: "+QString::number((rt)*2*s));
        }
        else if(tp=='c'){
             QMessageBox::information(this,"Perimetr","The Perimetr is: "+QString::number(3.14159*H*s));
        }
        else if(tp=='x'){

             QMessageBox::information(this,"Perimetr","The Perimetr is: "+QString::number((sqrt(4*H*H+9*W*W)+ H)*2/3*s));
        }
        else if(tp=='5'){
             double rad=dynamic_cast<Star5*>(obj)->R;
             QMessageBox::information(this,"Perimetr","The Perimetr is: "+QString::number(2*3.14159*rad*s));
        }
        else if(tp=='t'){
            double per=2*sqrt(W*W/4+H*H)+W;

             QMessageBox::information(this,"Perimetr","The Perimetr is: "+QString::number(per*s));
        }
    }
}

void ViewSquare::on_see_centroid_clicked()
{
    if(obj==nullptr){
        QMessageBox::warning(this,"The Object wasn't selected","Select It!\n");
    }
    else{
        if(tp=='q'||tp=='r'||tp=='h'||tp=='c'){
        QMessageBox::information(this,"Centroid","The Coordinates are: "+QString::number(obj->x()+(W*s)/2)+"; "+QString::number(obj->y()+(H*s)/2));
        }

    else if(tp=='t'){
         QMessageBox::information(this,"Centroid","The Coordinates are: "+QString::number(obj->x()+(W*s)/2)+"; "+QString::number(obj->y()+(H*s)/3*2));
    }
        else{
             QMessageBox::information(this,"Centroid","The Coordinates are: "+QString::number(obj->x()+(W*s)/2)+"; "+QString::number(obj->y()+(H*s)/2));
        }
}
}

