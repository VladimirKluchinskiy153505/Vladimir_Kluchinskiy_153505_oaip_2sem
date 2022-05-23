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
        hash_table.insert(random(1000),str);

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

void Widget::fill_table()
{
    ui->table->clear();
     ui->table->setRowCount(hash_table.size());
    for(int i=0;i<hash_table.size();++i){
        QString information;
        for(int j=0;j<hash_table[i].size();++j){
            auto &temp=hash_table[i][j];
            information.push_back(QString::number(temp.key)+"."+QString(temp.data));
        }
        QTableWidgetItem* hash=new QTableWidgetItem(QString::number(hash_table[i].top().hashkey));
        QTableWidgetItem* info=new QTableWidgetItem(information);
        ui->table->setItem(i,0,hash);
        ui->table->setItem(i,1,info);
       // ui->table->add
       // QTableWidgetItem* item=new QTableWidgetItem(QString)
    }
}


void Widget::on_eraze_button_clicked()
{
    int num=ui->line_eraze_key->text().toInt(nullptr,10);
    hash_table.eraze(num);
    fill_table();

}


void Widget::on_insert_button_clicked()
{
    int num=ui->line_key_insert->text().toInt(nullptr,10);
    QString str=ui->line_data_insert->text();
    hash_table.insert(num,str);
    fill_table();
}


void Widget::on_find_button_clicked()
{
    int num=ui->line_key_find->text().toInt(nullptr,10);
    auto ptr=hash_table.find(num);
    if(ptr==nullptr){
        QMessageBox::information(this,"Find","Elemend doesn't exest");
    }else{
        QMessageBox::information(this,"Find","Key: "+QString::number(ptr->key)+"HashKey: "+QString::number(ptr->hashkey)+" Data: "+QString(ptr->data));
    }
}


void Widget::on_pushButton_clicked()
{
    auto ptr=hash_table.find_with_min_key();
    QMessageBox::information(this,"Element with min key","Key: "+QString::number(ptr->key)+" "+QString(ptr->data));
}

