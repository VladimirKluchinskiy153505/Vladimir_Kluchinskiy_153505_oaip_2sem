#include "deleting.h"
#include "ui_deleting.h"

Deleting::Deleting(int gender,Widget* ptr,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Deleting)
{
    ui->setupUi(this);
    this->gender=gender;
    this->ptr=ptr;
    ui->lineb1->setText(QString::number(1));
    if(gender){
        ui->lineb2->setText(QString::number(ptr->man_size));
    }
    else{
         ui->lineb2->setText(QString::number(ptr->woman_size));
    }

}

Deleting::~Deleting()
{
    delete ui;
}



void Deleting::on_pushButton_clicked()
{
    int num=(ui->line_num_to_del->text()).toInt(nullptr,10)-1;
    if(gender){
        ptr->num_man_to_del=num;
    }else{
        ptr->num_woman_to_del=num;
    }
    emit delete_info();
    close();
}

