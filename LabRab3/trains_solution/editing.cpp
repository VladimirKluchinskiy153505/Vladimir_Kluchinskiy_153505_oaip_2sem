#include "editing.h"
#include "ui_editing.h"

Editing::Editing(Widget* ptr,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Editing)
{
    this->ptr=ptr;
    ui->setupUi(this);
    ui->textb1->setText(QString::number(1));
    ui->textb2->setText(QString::number(ptr->dec.count_nodes()));
}

Editing::~Editing()
{
    delete ui;
}



void Editing::on_ok_clicked()
{
    ptr->num_to_edit=(ui->line_num->text().toInt(nullptr,10))-1;
    EditingDialog * blank=new EditingDialog(ptr);

     blank->setWindowModality(Qt::ApplicationModal);
     blank->show();
     close();
}

