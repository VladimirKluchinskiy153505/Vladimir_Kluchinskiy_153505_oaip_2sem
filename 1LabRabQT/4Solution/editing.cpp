#include "editing.h"
#include "ui_editing.h"

Editing::Editing(int gender,Widget* ptr,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Editing)
{
    ui->setupUi(this);
    this->gender=gender;
    this->ptr=ptr;
    ui->textEditb1->setText(QString::number(1));
    if(gender){
        ui->textEditb2->setText(QString::number(ptr->man_size));
    }else{
        ui->textEditb2->setText(QString::number(ptr->woman_size));
    }
}

Editing::~Editing()
{
    delete ui;
}

void Editing::on_pushButton_clicked()
{
   EditingDialog * blank=new EditingDialog(gender,ptr);
   if(gender){
       ptr->num_man_to_edit=(ui->line_num->text().toInt(nullptr,10))-1;
   }
   else{
         ptr->num_woman_to_edit=(ui->line_num->text().toInt(nullptr,10))-1;
   }
    blank->setWindowModality(Qt::ApplicationModal);
    blank->show();
    close();
}

