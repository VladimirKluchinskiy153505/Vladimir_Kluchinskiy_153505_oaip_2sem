#include "widget.h"
#include "ui_widget.h"
#include <regex>
#include<fstream>
using namespace std;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
   filename=QFileDialog::getOpenFileName(this,"Change Directory",QDir::currentPath(),"*.txt");
   QFile fs(filename);
   qDebug()<<filename<<endl;
 std::cmatch result;
std::regex regular(R"(int|void|double)\s+\w+\(.*\)");

QString str;
while (!fs.atEnd()) {
 str=fs.readLine();
    }

    qDebug() << str << "1\n";
}

Widget::~Widget()
{
    delete ui;
}

