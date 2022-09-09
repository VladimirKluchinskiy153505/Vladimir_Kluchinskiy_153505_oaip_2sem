#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
int random(int num)
 {
     return (qrand() %num );
 }
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    filename=QFileDialog::getOpenFileName(this,"Change Directory",QDir::currentPath(),"*.txt");
 QFile fs(filename);
    if (!fs.open(QIODevice::ReadWrite|QIODevice::Text)) {
        qDebug() << "Input Failed\n";
    }
    else{
    QString str;
    while (!fs.atEnd()) {
        str=fs.readLine();
        //qDebug() << str << "1\n";
        umap.insert(random(1000),str);

    }
     ui->table->setColumnCount(2);
      ui->table->horizontalHeader()->resizeSection(1,800);
    ui->table->setHorizontalHeaderLabels(QStringList()<<"Hashcode"<<"Information");
    fill_table();
}
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_earaze_button_clicked()
{
    int num=ui->key_eraze->text().toInt(nullptr,10);
    umap.eraze(num);
    fill_table();
}


void Widget::on_insert_button_clicked()
{
    int num=ui->key_insert->text().toInt(nullptr,10);
    QString str=ui->data_insert->text();
    umap.insert(num,str);
    fill_table();
}


void Widget::on_find_button_clicked()
{
    int num=ui->key_find->text().toInt(nullptr,10);
    auto ptr=umap.find(num);
    if(ptr==nullptr){
        QMessageBox::information(this,"Find","Elemend doesn't exest");
    }else{
        QMessageBox::information(this,"Find","Key: "+QString::number(ptr->block.key)+"HashKey: "+QString::number(ptr->hashkey)+" Data: "+QString(ptr->block.data));
    }
}


void Widget::on_clear_button_clicked()
{
    umap.clear();
    fill_table();
}

void Widget::fill_table()
{
    ui->table->clear();
     ui->table->setRowCount(umap.Capacity());
    for(int i=0;i<umap.Capacity();++i){
        QString information;
        auto cur_list=umap.at(i);
       for(auto now=cur_list.begin();now!=cur_list.end();++now){
           information.push_back(QString::number((*now).block.key)+"."+QString((*now).block.data));
       }
        if(!cur_list.empty()){
        QTableWidgetItem* hash=new QTableWidgetItem(QString::number(umap.at(i).top().hashkey));
        QTableWidgetItem* info=new QTableWidgetItem(information);
        ui->table->setItem(i,0,hash);
        ui->table->setItem(i,1,info);
        }

    }
}

