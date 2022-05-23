#include "adding.h"
#include "ui_adding.h"

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

void Adding::on_save_clicked()
{
    date.day=(ui->line_day->text()).toInt(nullptr,10);
    date.month=(ui->line_month->text()).toInt(nullptr,10);
    date.year=(ui->line_year->text()).toInt(nullptr,10);
    dest=(ui->line_dest->text());
    time.hours=(ui->line_hours->text()).toInt(nullptr,10);
    time.minuts=(ui->line_minuts->text()).toInt(nullptr,10);
    number=(ui->line_number->text()).toInt(nullptr,10);

    ptr->dec.push_back(Place(date,dest,time,number));
    emit add_info();
    close();
}

