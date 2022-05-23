#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
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
    }
    else{
    QString str;
    while (!fs.atEnd()) {
      str=fs.readLine();
      queue.push_back(str.toInt(nullptr,10));
        }
        fill_list();
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::print_queue()
{
    for(int i=0;i<queue.size()-1;++i){
        qDebug()<<queue[i]<<'\n';
    }
}

void Widget::fill_list()
{
    for(int i=0;i<queue.size();++i){
        ui->ListBox->addItem(QString::number(queue[i]));
    }
}

void Widget::on_pushButton_clicked()
{
    queue.bubble_sort();
    for(int i=0;i<queue.size();++i){
        ui->ListBox2->addItem(QString::number(queue[i]));
    }
}

void Widget::on_change_directory_clicked()
{
    ui->ListBox->clear();
    ui->ListBox2->clear();
    queue.clear();
    filename=QFileDialog::getOpenFileName(this,"Change Directory",QDir::currentPath(),"*.txt");
 QFile fs(filename);
    if (!fs.open(QIODevice::ReadWrite|QIODevice::Text)) {
        qDebug() << "Input Failed\n";
       // qWarning("Cannot open file");
    }
    else{
    QString str;
    while (!fs.atEnd()) {
      str=fs.readLine();
      queue.push_back(str.toInt(nullptr,10));
        }
        fill_list();

}
}

