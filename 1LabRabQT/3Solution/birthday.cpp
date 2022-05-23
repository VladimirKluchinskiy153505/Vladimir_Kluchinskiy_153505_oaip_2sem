#include "birthday.h"
#include "ui_birthday.h"
#include "date.h"
#include <QMessageBox>
Birthday::Birthday(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Birthday)
{
    ui->setupUi(this);
}

Birthday::~Birthday()
{
    delete ui;
}


void Birthday::on_enter_day_clicked()
{
    QString birthday=ui->line_day->text();
     d=birthday.toInt(nullptr,10);
}


void Birthday::on_enter_month_clicked()
{
    QString birthday=ui->line_month->text();
     m=birthday.toInt(nullptr,10);
}


void Birthday::on_enter_year_clicked()
{
    QString birthday=ui->line_year->text();
    y=birthday.toInt(nullptr,10);
}


void Birthday::on_save_clicked()
{
    Date::birth_date=Date(d,m,y);
     emit save_birth_date();
    QMessageBox::information(this,"Well Done","You birthday is: "+QString::number(Date::birth_date.day)+"."+QString::number(Date::birth_date.month)+"."+QString::number(Date::birth_date.year));

}

