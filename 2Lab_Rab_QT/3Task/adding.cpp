#include "adding.h"
#include "ui_adding.h"

Adding::Adding(Widget* ptr,int flag,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Adding)
{
    this->ptr=ptr;
    this->flag=flag;
    ui->setupUi(this);
}

Adding::~Adding()
{
    delete ui;
}

void Adding::on_save_clicked()
{
    QString expr=ui->lineExpression->text();
    double a=ui->lineA->text().toDouble(nullptr);
    double b=ui->lineB->text().toDouble(nullptr);
    double c=ui->lineC->text().toDouble(nullptr);
    double d=ui->lineD->text().toDouble(nullptr);
    double e=ui->lineE->text().toDouble(nullptr);
    if(flag){

    ptr->vec.push_back(Expression(expr,a,b,c,d,e));
    emit renew();
    }else{
        QString expression=Recovery::recovery(expr);
    ptr->vec.push_back(Expression(expression,a,b,c,d,e));
    emit renew_prw();
    }
    close();
}

