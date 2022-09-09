#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#define ull unsigned long long int
#define ul unsigned long int
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
    delete set_ptr;
}


void Widget::on_enter_button_clicked()
{
    delete set_ptr;
  const size_t N=ui->line_N->text().toULong(nullptr,10);
    ull value=ui->line_value->text().toULongLong(nullptr,10);
    set_ptr=new bit_set(N,value);
    qDebug()<<N<<" "<<value<<'\n';

}


void Widget::on_button_get_string_clicked()
{
    QString res=QString::fromStdString(set_ptr->to_string());
    ui->line_string->setText(res);
}


void Widget::on_button_get_ULong_clicked()
{
    QString res=QString::number(set_ptr->to_ulong());
    ui->line_ulong->setText(res);
}


void Widget::on_button_get_ULongLong_clicked()
{
    QString res=QString::number(set_ptr->to_ullong());
    ui->line_ulonglong->setText(res);
}


void Widget::on_button_get_bit_clicked()
{
    size_t pos=ui->bit_line->text().toULong(nullptr,10);
    size_t bit=set_ptr->operator[](pos);
    ui->line_bit->setText(QString::number(bit));
}


void Widget::on_all_button_clicked()
{
    bool res=set_ptr->all();
    if(res){
        QMessageBox::information(this,"ALL","ALL bits are 1");
    }else{
        QMessageBox::information(this,"ALL","At least one bit is 0");
    }
}


void Widget::on_any_button_clicked()
{
    bool res=set_ptr->any();
    if(res){
        QMessageBox::information(this,"ANY","At least one bit is 1");
    }else{
        QMessageBox::information(this,"ANY","ALL bits are 0");
    }
}


void Widget::on_count_button_clicked()
{
    size_t count=set_ptr->count();
     QMessageBox::information(this,"Count","Your bitset has: "+QString::number(count)+" +bits");
}


void Widget::on_flip_button_clicked()
{
    size_t pos=ui->line_flip->text().toULong(nullptr,10);
    set_ptr->flip(pos);
}


void Widget::on_none_button_clicked()
{
    bool res=set_ptr->none();
    if(res){
        QMessageBox::information(this,"NONE","ALL bits are 0");
    }else{
        QMessageBox::information(this,"NONE","At least one bit is 1");
    }
}
void Widget::on_reset_button_clicked()
{
 size_t pos=ui->line_reset->text().toULong(nullptr,10);
 set_ptr->reset(pos);
}


void Widget::on_set_button_clicked()
{
    size_t pos=ui->line_set->text().toULong(nullptr,10);
    set_ptr->set(pos);
}


void Widget::on_size_button_clicked()
{
size_t size=set_ptr->size();
QMessageBox::information(this,"SIZE",QString::number(size));
}


void Widget::on_test_button_clicked()
{
    size_t pos=ui->line_test->text().toULong(nullptr,10);
bool res=set_ptr->test(pos);
if(res){
    QMessageBox::information(this,"TEST","This bit is 1");
}else{
    QMessageBox::information(this,"TEST","This bit is 0");
}
}

