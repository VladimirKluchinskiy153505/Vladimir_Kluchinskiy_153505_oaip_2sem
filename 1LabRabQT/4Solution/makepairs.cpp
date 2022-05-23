#include "makepairs.h"
#include "ui_makepairs.h"

MakePairs::MakePairs(Widget* ptr,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MakePairs)
{
    ui->setupUi(this);
    this->ptr=ptr;
    select=ui->selectionWidget;
    result=ui->resultWidget;
    for(int i=0;i<ptr->couple.size();i++){
        int m=ptr->couple[i].man_num;
        int w=ptr->couple[i].woman_num;
        select->addItem(QString::number(ptr->arrMan[m].number)+"."+ptr->arrMan[m].name+" and  "+QString::number(ptr->arrWoman[w].number)+"."+ptr->arrWoman[w].name);
    }
}

MakePairs::~MakePairs()
{
    delete ui;
}

void MakePairs::on_make_pair_clicked()
{
    result->addItem(select->currentItem()->text());
    int num=select->currentIndex().row();
    qDebug()<<num<<'\n';
    int m=ptr->couple[num].man_num;
    int w=ptr->couple[num].woman_num;
    for(int i=0;i<ptr->couple.size();i++){
        if((ptr->couple[i].man_num==m)||(ptr->couple[i].woman_num==w)){
            select->item(i)->setBackground(Qt::magenta);
        }
    }
}

