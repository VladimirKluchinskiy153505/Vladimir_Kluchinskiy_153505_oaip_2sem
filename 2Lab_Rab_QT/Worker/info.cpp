#include "info.h"
#include "ui_info.h"

Info::Info(Widget* ptr,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Info)
{
    ui->setupUi(this);
    this->ptr=ptr;
}

Info::~Info()
{
    delete ui;
}

void Info::on_pushButton_clicked()
{
    ptr->salary=ui->line_salary->text().toDouble(nullptr);
    ptr->hours=ui->line_hours->text().toDouble(nullptr);
    close();
    emit renew();
}

