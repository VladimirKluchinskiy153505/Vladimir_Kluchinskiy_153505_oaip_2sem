#include "deleting.h"
#include "ui_deleting.h"
#include <QMessageBox>
#include <QDebug>
Deleting::Deleting(Widget* ptr,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Deleting)
{
    ui->setupUi(this);
    this->ptr=ptr;
      ui->lineb1->setText(QString::number(1));
     ui->lineb2->setText(QString::number(ptr->dec.count_nodes()));

qDebug()<<ptr->dec.count_nodes();
}

Deleting::~Deleting()
{
    delete ui;
}






void Deleting::on_save_button_clicked()
{

    int num=((ui->line_num_to_del->text()).toInt(nullptr,10));
        if((num>0)&&(num<=(ptr->dec.count_nodes()))){
    ptr->num_to_del=num-1;
    emit delete_info();
        }else{
            QMessageBox::warning(this,"Error","Not Found");
        }
    close();
}

