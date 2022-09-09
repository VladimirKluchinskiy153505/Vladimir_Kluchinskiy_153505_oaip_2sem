#include "widget.h"
#include "ui_widget.h"
#include <QWidget>
#include <QMessageBox>
#include <QFileDialog>
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
     set.insert(str.toLongLong(nullptr,10));
    }
    fill_table();
    qDebug()<<set.the_longest_way();
}
}

Widget::~Widget()
{
    delete ui;
}

void Widget::fill_table()
{
    ui->treeWidget->clear();
     ptr_type root_ptr=set.get_root();
     if(root_ptr!=nullptr){
    QTreeWidgetItem* item=new QTreeWidgetItem();
    item->setText(0,QString::number(root_ptr->key));
    item->setBackgroundColor(0,Qt::green);
    ui->treeWidget->addTopLevelItem(item);
fill_table2(root_ptr,item);
ui->line_deep->clear();
ui->line_deep->setText(QString::number(set.the_longest_way()));
ui->line_size_2->setText(QString::number(set.size()));
ui->list_nodes->clear();
set.pre_travel(ui->list_nodes);
     }
}

void Widget::fill_table2(ptr_type root_ptr, QTreeWidgetItem *root_item)
{
    if(root_ptr->left==nullptr&&root_ptr->right==nullptr){
        return;
    }
    if(root_ptr->left!=nullptr){
    QTreeWidgetItem* child_left=new QTreeWidgetItem();
    child_left->setText(0,QString::number(root_ptr->left->key));
    child_left->setBackgroundColor(0,Qt::magenta);
    root_item->addChild(child_left);
    fill_table2(root_ptr->left,child_left);
    }
    if(root_ptr->right!=nullptr){
        QTreeWidgetItem* child_right=new QTreeWidgetItem();
        child_right->setText(0,QString::number(root_ptr->right->key));
        child_right->setBackgroundColor(0,Qt::red);
        root_item->addChild(child_right);
        fill_table2(root_ptr->right,child_right);
    }
}


void Widget::on_eraze_range_button_clicked()
{
    size_t start=ui->line1_3->text().toInt(nullptr,10);
    size_t end=ui->line2_3->text().toInt(nullptr,10);
    for(int i=start;i<=end;++i){
        set.eraze(i);
    }
    fill_table();
}
void Widget::on_eraze_button_clicked()
{
    size_t key=ui->line_key_eraze_2->text().toInt(nullptr,10);
    set.eraze(key);
    fill_table();
}


void Widget::on_insert_button_clicked()
{
    long long int key=ui->line_key_insert_2->text().toLongLong(nullptr,10);
    set.insert(key);
    fill_table();
}


void Widget::on_find_button_clicked()
{
    size_t key=ui->line_key_find_2->text().toInt(nullptr,10);
    ptr_type ptr=set.find(key);
   if(ptr!=nullptr){
    QMessageBox::information(this,"FIND",QString::number(ptr->key));
    }else{
       QMessageBox::information(this,"FIND","Element doesn't exist");
   }
}


void Widget::on_find_min_button_clicked()
{
    ptr_type ptr=set.find_min();
    QMessageBox::information(this,"Minimun",QString::number(ptr->key));
}


void Widget::on_find_min_rec_button_clicked()
{
    ptr_type ptr=set.find_min_rec();
    QMessageBox::information(this,"Minimun",QString::number(ptr->key));
}


void Widget::on_find_max_button_clicked()
{
    ptr_type ptr=set.find_max();
    QMessageBox::information(this,"Minimun",QString::number(ptr->key));

}


void Widget::on_find_max_rec_button_clicked()
{
    ptr_type ptr=set.find_max_rec();
    QMessageBox::information(this,"Minimun",QString::number(ptr->key));
}


void Widget::on_clear_button_clicked()
{
    set.clear();
    ui->treeWidget->clear();
    ui->line_deep->clear();
}


void Widget::on_pre_travel_button_clicked()
{
    ui->list_nodes->clear();
    set.pre_travel(ui->list_nodes);
}


void Widget::on_in_travel_button_clicked()
{
    ui->list_nodes->clear();
    set.in_travel(ui->list_nodes);
}


void Widget::on_pos_travel_button_clicked()
{
    ui->list_nodes->clear();
    set.post_travel(ui->list_nodes);
}


void Widget::on_change_dir_button_clicked()
{
    set.clear();
    filename=QFileDialog::getOpenFileName(this,"Change Directory",QDir::currentPath(),"*.txt");
 QFile fs(filename);
    if (!fs.open(QIODevice::ReadWrite|QIODevice::Text)) {
        qDebug() << "Input Failed\n";
    }
    else{
    QString str;
    while (!fs.atEnd()) {
      str=fs.readLine();
     set.insert(str.toLongLong(nullptr,10));
    }
    fill_table();
    }
}


void Widget::on_button_iterator_clicked()
{
    QString str;
    for(auto now=set.begin();now!=set.end();++now){
        str.push_back(QString::number(*now)+",");
    }
    QMessageBox::information(this,"Consequence",str);
}


void Widget::on_rcons_button_clicked()
{
    QString str;
    for(auto now=set.rbegin();now!=set.rend();--now){
        str.push_back(QString::number(*now)+",");
    }
    QMessageBox::information(this,"Rev_Consequence",str);
}


void Widget::on_findLB_button_clicked()
{
    long long int key=ui->lb_key->text().toLongLong(nullptr,10);
    auto now=set.lower_bound(key);
    QMessageBox::information(this,"Lower_Bound",QString::number(*now));
}


void Widget::on_FindUB_button_2_clicked()
{
    long long int key=ui->ub_key_2->text().toLongLong(nullptr,10);
    auto now=set.upper_bound(key);
    QMessageBox::information(this,"Upper_Bound",QString::number(*now));
}
