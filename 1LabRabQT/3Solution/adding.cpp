#include "adding.h"
#include "ui_adding.h"
#include <QDebug>
Adding::Adding(Widget* ptr,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Adding)
{
    ui->setupUi(this);
    this->ptr=ptr;
}

Adding::~Adding()
{
    delete ui;
}

void Adding::on_enter_clicked()
{
  QString info=ui->line_enter->text();
   ptr->addinformation=info;
   emit renew_info();
   qDebug()<<info;
}

