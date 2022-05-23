#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    filename=QFileDialog::getOpenFileName(this,"Change Directory",QDir::currentPath(),"*.txt");
 QFile fs(filename);


  if (!fs.open(QIODevice::ReadWrite|QIODevice::Text)) {
      qDebug() << "Input Failed\n";
     // qWarning("Cannot open file");
  }else{
  QString str;
  while (!fs.atEnd()) {
      str=fs.readLine();
deque.push_back(str.toInt(nullptr,10));
      //qDebug() << str << "1\n";
  }
}
  fill_deque();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::fill_deque()
{
    ui->NuberList->clear();
    for(int i=0;i<deque.count();++i){
    ui->NuberList->addItem(QString::number(deque[i]));
    }
}

void Widget::on_push_back_clicked()
{
    int number=ui->NumLine->text().toInt(nullptr,10);
    deque.push_back(number);
    fill_deque();
}

void Widget::on_push_front_clicked()
{
    int number=ui->NumLine->text().toInt(nullptr,10);
    deque.push_front(number);
    fill_deque();
}
void Widget::on_pop_back_clicked()
{
    deque.pop_behind();
    fill_deque();
}
void Widget::on_pop_front_clicked()
{
    deque.pop_front();
    fill_deque();
}

void Widget::on_clear_clicked()
{
    deque.clear();
    fill_deque();
}
void Widget::on_empty_clicked()
{
    if(deque.empty()){
        QMessageBox::information(this,"Header","Deque is empty");
    }
    else{
        QMessageBox::information(this,"Header","Deque is not empty");
    }
}


void Widget::on_see_element_clicked()
{
    int num=ui->ItNum->text().toInt(nullptr,10);
    QMessageBox::information(this,"Your Number",QString::number(deque[num]));
}


void Widget::on_change_dir_clicked()
{
    deque.clear();
    ui->NuberList->clear();
    filename=QFileDialog::getOpenFileName(this,"Change Directory",QDir::currentPath(),"*.txt");
 QFile fs(filename);


  if (!fs.open(QIODevice::ReadWrite|QIODevice::Text)) {
      qDebug() << "Input Failed\n";
     // qWarning("Cannot open file");
  }else{
  QString str;
  while (!fs.atEnd()) {
      str=fs.readLine();
deque.push_back(str.toInt(nullptr,10));
      //qDebug() << str << "1\n";
  }
}
  fill_deque();
}

