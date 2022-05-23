#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>
#include <QWidget>
#include <QMessageBox>
#include <QFileDialog>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
     // typedef decltype(tree.get_root()) ptr_type;
    ui->setupUi(this);
    filename=QFileDialog::getOpenFileName(this,"Change Directory",QDir::currentPath(),"*.txt");
 QFile fs(filename);
    if (!fs.open(QIODevice::ReadWrite|QIODevice::Text)) {
        qDebug() << "Input Failed\n";
    }
    else{
    QString str;
    size_t k=0;
    while (!fs.atEnd()) {
      str=fs.readLine();
     tree.insert(k,str);
     ++k;
    }
    fill_table();
    qDebug()<<tree.the_longest_way();
}
}

Widget::~Widget()
{
    delete ui;
}

void Widget::fill_table()
{
    ui->treeWidget->clear();
     ptr_type root_ptr=tree.get_root();
     if(root_ptr!=nullptr){
    QTreeWidgetItem* item=new QTreeWidgetItem();
    item->setText(0,QString::number(root_ptr->key)+root_ptr->data);
    item->setBackgroundColor(0,Qt::green);
    ui->treeWidget->addTopLevelItem(item);
fill_table2(root_ptr,item);
ui->line_deep->clear();
ui->line_deep->setText(QString::number(tree.the_longest_way()));
ui->list_nodes->clear();
tree.pre_travel(ui->list_nodes);
     }
}

void Widget::fill_table2(ptr_type root_ptr, QTreeWidgetItem *root_item)
{
    if(root_ptr->left==nullptr&&root_ptr->right==nullptr){
        return;
    }
    if(root_ptr->left!=nullptr){
    QTreeWidgetItem* child_left=new QTreeWidgetItem();
    child_left->setText(0,QString::number(root_ptr->left->key)+"."+root_ptr->left->data);
    child_left->setBackgroundColor(0,Qt::magenta);
    root_item->addChild(child_left);
    fill_table2(root_ptr->left,child_left);
    }
    if(root_ptr->right!=nullptr){
        QTreeWidgetItem* child_right=new QTreeWidgetItem();
        child_right->setText(0,QString::number(root_ptr->right->key)+"."+root_ptr->right->data);
        child_right->setBackgroundColor(0,Qt::red);
        root_item->addChild(child_right);
        fill_table2(root_ptr->right,child_right);
    }

}
void Widget::on_eraze_button_clicked()
{
    size_t key=ui->line_key_eraze->text().toInt(nullptr,10);
    tree.eraze(key);
    fill_table();
}
void Widget::on_insert_button_clicked()
{
    size_t key=ui->line_key_insert->text().toInt(nullptr,10);
    QString str=ui->line_data_insert->text();
    tree.insert(key,str);
    fill_table();
}
void Widget::on_find_button_clicked()
{
    size_t key=ui->line_key_find->text().toInt(nullptr,10);
    ptr_type ptr=tree.find(key);
   if(ptr!=nullptr){
    QMessageBox::information(this,"FIND",QString::number(ptr->key)+" "+ptr->data);
    }
}
void Widget::on_find_min_button_clicked()
{
    ptr_type ptr=tree.find_min();
    QMessageBox::information(this,"Minimun",QString::number(ptr->key)+"."+ptr->data);
}
void Widget::on_find_min_rec_button_clicked()
{
    ptr_type ptr=tree.find_min_rec();
    QMessageBox::information(this,"Minimun",QString::number(ptr->key)+"."+ptr->data);
}
void Widget::on_find_max_button_clicked()
{
    ptr_type ptr=tree.find_max();
    QMessageBox::information(this,"Minimun",QString::number(ptr->key)+"."+ptr->data);
}


void Widget::on_find_max_rec_button_clicked()
{
    ptr_type ptr=tree.find_max_rec();
    QMessageBox::information(this,"Minimun",QString::number(ptr->key)+"."+ptr->data);
}


void Widget::on_clear_button_clicked()
{
    tree.clear();
    ui->treeWidget->clear();
    ui->line_deep->clear();
}


void Widget::on_fill_button_clicked()
{
    fill_table();
}


void Widget::on_change_dir_button_clicked()
{
    tree.clear();
    filename=QFileDialog::getOpenFileName(this,"Change Directory",QDir::currentPath(),"*.txt");
 QFile fs(filename);
    if (!fs.open(QIODevice::ReadWrite|QIODevice::Text)) {
        qDebug() << "Input Failed\n";
    }
    else{
    QString str;
    size_t k=0;
    while (!fs.atEnd()) {
      str=fs.readLine();
     tree.insert(k,str);
     ++k;
    }
    fill_table();
    }
}


void Widget::on_pre_travel_button_clicked()
{
    ui->list_nodes->clear();
    tree.pre_travel(ui->list_nodes);
}


void Widget::on_in_travel_button_clicked()
{
    ui->list_nodes->clear();
    tree.in_travel(ui->list_nodes);
}


void Widget::on_pos_travel_button_clicked()
{
    ui->list_nodes->clear();
    tree.post_travel(ui->list_nodes);
}


void Widget::on_pushButton_clicked()
{
    size_t start=ui->line1->text().toInt(nullptr,10);
    size_t end=ui->line2->text().toInt(nullptr,10);
    for(int i=start;i<=end;++i){
        tree.eraze(i);
    }
    fill_table();
}

