#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include<QDebug>
#include <QMainWindow>
#include <QRegExp>
#include <stdlib.h>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
   filename=QFileDialog::getOpenFileName(this,"Change Directory",QDir::currentPath(),"*.txt");
   QFile fs(filename);
   qDebug()<<filename;
;
//std::cmatch result;
//
   if (!fs.open(QIODevice::ReadWrite|QIODevice::Text)) {
       qDebug() << "Input Failed\n";

   }
int row=1;
while (!fs.atEnd()) {
     QString str;
 str=fs.readLine();
      global.push_back(str);
 check_funktions(str,row);
 check_var(str,row);
 check_class(str,row);
 check_struct(str,row);
 check_arrays(str,row);
 ++row;
    }
//print();
count_branching();
print_functions();
print_vars();
print_class();
print_struct();
print_arrays();
find_mistakes();
print_mistakes();
//print_branching();
filling();
}
Widget::~Widget()
{
    delete ui;
}

void Widget::check_funktions(QString &str,int row)
{
QRegExp rx("(byte|short|int|long long|double|long double|string)[\\*]?\\s\\w+\\(.*\\)");

int pos=0;
while((pos=rx.indexIn(str,pos))!=-1){
    FunkList.push_back(Function(rx.cap(0),row,pos));
    pos+=rx.matchedLength();
}
}
void Widget::check_var(QString &str,int row)
{
    //QRegExp rx("(byte|char|short|int|double|string)[\\s+]?[\\*]?[\\s+](\\w+)[^\\(]$");
    QRegExp rx("(byte|char|short|int|double|string|ifstream)(\\s+|\\*\\s|\\*&\\s|\\s\\*|\\s\\*&)([\\*]?\\w+[ ]?[,;=][ ]?)+");
    int pos=0;
    while((pos=rx.indexIn(str,pos))!=-1){
        VarList.push_back(Var(rx.cap(0),row,pos));
        pos+=rx.matchedLength();
    }
}

void Widget::check_class(QString &str,int row)
{
    QRegExp rx("(class (\\w+))");
    int pos=0;
    while((pos=rx.indexIn(str,pos))!=-1){
        ClassList.push_back(ClaSS(rx.cap(1),row,pos));
        pos+=rx.matchedLength();
    }
}
void Widget::check_struct(QString &str,int row)
{
    QRegExp rx("(struct (\\w+))");
    int pos=0;
    while((pos=rx.indexIn(str,pos))!=-1){
        StructList.push_back(Structure(rx.cap(1),row,pos));
        pos+=rx.matchedLength();
    }
}
void Widget::check_arrays(QString &str,int row)
{
    QRegExp rx("((\\w+)(\\*\\s\\w+|\\s\\w+\\[\\w+\\])[\\s]?=[\\s]?(new\\s(\\w+)\\[.+\\]|\\{.+\\}))");
    int pos=0;
    while((pos=rx.indexIn(str,pos))!=-1){
        ArrList.push_back(Array(rx.cap(0),row,pos));
        pos+=rx.matchedLength();
    }
}

void Widget::print_functions(){
    for(auto &now: FunkList){
        qDebug()<<now.str<<" "<<now.row<<" "<<now.pos<<'\n';
    }
}
void Widget::print_class()
{
    for(auto &now: ClassList){
        qDebug()<<now.str<<" "<<now.row<<" "<<now.pos<<'\n';
    }
}

void Widget::print_vars()
{
    for(auto &now: VarList){
       qDebug()<<now.str<<" "<<now.row<<" "<<now.pos<<'\n';
    }
}
void Widget::print_struct()
{
    for(auto &now: StructList){
        qDebug()<<now.str<<" "<<now.row<<" "<<now.pos<<'\n';
    }
}


void Widget::print_arrays()
{
    for(auto &now: ArrList){
        qDebug()<<now.str<<" "<<now.row<<" "<<now.pos<<'\n';
    }
}

void Widget::count_branching()
{
int deep=0,open=0;

for(int i=0;i<global.size();++i){
    if(global[i]=='{'){
        ++open;
        ++deep;
    }else if(global[i]=='}'){
        --open;
        if(open==0){
            Branching.push_back(deep);
            deep=0;
        }
    }
}
}

void Widget::print_branching()
{
    for(auto &now: Branching){
        qDebug()<<now<<'\n';
    }
}

void Widget::find_mistakes()
{
    QRegExp rx("(while\\(false\\))");
    int pos=0;
    while((pos=rx.indexIn(global,pos))!=-1){
        Mistake.push_back(rx.cap(0));
        pos+=rx.matchedLength();
    }

    QRegExp rx1("(\\/0)");
    int pos1=0;
    while((pos1=rx1.indexIn(global,pos1))!=-1){
        Mistake.push_back(rx1.cap(0));
        pos1+=rx1.matchedLength();
    }
    QRegExp rx2("(if\\(false\\))");
    int pos2=0;
    while((pos2=rx2.indexIn(global,pos2))!=-1){
        Mistake.push_back(rx2.cap(0));
        pos2+=rx2.matchedLength();
    }
    QRegExp rx3("(if\\(true\\))");
    int pos3=0;
    while((pos3=rx3.indexIn(global,pos3))!=-1){
        Mistake.push_back(rx3.cap(0));
        pos3+=rx3.matchedLength();
    }

}

void Widget::print_mistakes()
{
    for(auto &now: Mistake){
        qDebug()<<now<<'\n';
    }
}

void Widget::filling()
{
for(int i=0;i<VarList.size();++i){
    ui->listVar->addItem(VarList[i].str+" ("+QString::number(VarList[i].row)+", "+QString::number(VarList[i].pos)+")");
}
for(int i=0;i<FunkList.size();++i){
    ui->listFunctions->addItem(FunkList[i].str+" ("+QString::number(FunkList[i].row)+", "+QString::number(FunkList[i].pos)+")");
}
for(int i=0;i<ArrList.size();++i){
    ui->listArray->addItem(ArrList[i].str+" ("+QString::number(ArrList[i].row)+", "+QString::number(ArrList[i].pos)+")");
}
for(int i=0;i<ClassList.size();++i){
    ui->listClasses->addItem(ClassList[i].str+" ("+QString::number(ClassList[i].row)+", "+QString::number(ClassList[i].pos)+")");
}
for(int i=0;i<StructList.size();++i){
    ui->listClasses->addItem(StructList[i].str+" ("+QString::number(StructList[i].row)+", "+QString::number(StructList[i].pos)+")");
}
for(int i=0;i<Mistake.size();++i){
    ui->listMistake->addItem(Mistake[i]);
}
for(int i=0;i<Branching.size();++i){
    ui->BranchList->addItem(QString::number(Branching[i]));
}
}

void Widget::print()
{
    qDebug()<<global;
}






















