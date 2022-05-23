#include "editing.h"
#include "ui_editing.h"

Editing::Editing(Widget* ptr,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Editing)
{
    ui->setupUi(this);
    this->ptr=ptr;
}

Editing::~Editing()
{
    delete ui;
}

void Editing::on_enter_number_clicked()
{
    int number=(ui->line_number->text()).toInt(nullptr,10);
    if((number<1)||(number>ptr->date_size)){
        QMessageBox::warning(this,"Error","Not_Found");
        close();
        return;
    }
    ptr->num_to_edit0=number-1;

}


void Editing::on_save_update_clicked()
{
     QString info=ui->line_update->text();
         ptr->editinformation=info;
           emit update_info();
}

