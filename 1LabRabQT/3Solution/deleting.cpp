#include "deleting.h"
#include "ui_deleting.h"
Deleting::Deleting(Widget* ptr,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Deleting)
{
    ui->setupUi(this);
    this->ptr=ptr;
}

Deleting::~Deleting()
{
    delete ui;
}

void Deleting::on_del_button_clicked()
{
   int num=(ui->line_delete->text()).toInt();
   if((num<1)||(num>ptr->date_size)){
       QMessageBox::warning(this,"Error","Not_Found");
       close();
       return;
   }
     ptr->num_to_delete0=num-1;
     emit del_info();
     close();
}

