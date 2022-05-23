#include "widget.h"
#include "ui_widget.h"
#include "string"
#include <iostream>
using namespace std;
class Operator {
public:
    Operator(char symb) :symb(symb) {
        if (symb == '*' || symb == '/') {
            priority = 3;
        }
        else if (symb == '+' || symb == '-') {
            priority = 2;
        }
        else if (symb == '(' || symb == ')') {
            priority = 1;
        }
        else {
            priority = 0;
        }
    };
    Operator() {};
    int get_priority() {
        return priority;
    }
    char& get_char() {
        return symb;
    }
private:
    char symb;
    int priority;
};
int Priority(char symb) {
    if (symb == '*' || symb == '/') {
        return 3;
    }
    else if (symb == '+' || symb == '-') {
        return 2;
    }
    else if (symb == '(' || symb == ')') {
        return 1;
    }
    else {
        return 0;
    }
}
string rpw(string str_source) {
    string str_out;
    my_stack<Operator> stack;

    //cout << str_source<<'\n';
    int size = str_source.size();
    for (int i = 0; i < size; i++) {
        char s = str_source[i];
        if ((s == '(') || (s == ')') || (s == '+') || (s == '-') || (s == '*') || (s == '/')) {
            if (stack.empty() || s == '(') {
                stack.push(Operator(s));
            }
            else if (s == ')') {
                while (stack.top().get_char() != '(') {
                    str_out.push_back(stack.top().get_char());
                    stack.pop();
                }
                stack.pop();
            }
            else {
                while (stack.top().get_priority() >= Priority(s)) {
                    str_out.push_back(stack.top().get_char());
                    stack.pop();
                }
                stack.push(Operator(s));
            }
        }
        else {
            str_out.push_back(s);
        }
    }
    while (!stack.empty()) {
        str_out.push_back(stack.top().get_char());
        stack.pop();
    }
    return str_out;
}
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    string str1 = rpw("a+(b-c)*d");
    string str2 = rpw("a/(b-c)*(d+e)");
    cout << str1 << " " << str2;

    cout<<str2<<" "<<str2;
    ui->setupUi(this);
    filename=QFileDialog::getOpenFileName(this,"Change Directory",QDir::currentPath(),"*.txt");
 QFile fs(filename);


  if (!fs.open(QIODevice::ReadOnly|QIODevice::Text)) {
      qDebug() << "Input Failed\n";

return; }
  else{
      QString expr;
      double a,b,c,d,e;
      QString str;
      while (!fs.atEnd()) {
          str=fs.readLine();
          str.chop(1);
       expr=str;
       str=fs.readLine();
       a=str.toDouble(nullptr);
       qDebug()<<a;
       str=fs.readLine();
       b=str.toDouble(nullptr);
       str=fs.readLine();
       c=str.toDouble(nullptr);
       str=fs.readLine();
       d=str.toDouble(nullptr);
       str=fs.readLine();
       e=str.toDouble(nullptr);
       vec.push_back(Expression(expr,a,b,c,d,e));
          }

      }
  int vsize=vec.size();
  ui->table->setRowCount(vec.size());
  ui->table->setColumnCount(9);
      ui->table->horizontalHeader()->resizeSection(6,150);
  ui->table->setHorizontalHeaderLabels(QStringList()<<"Expression"<<"a"<<"b"<<"c"<<"d"<<"e"<<"Reverse_Polish_Write"<<"Resunt_in_RPW"<<"Result");
  for(int i=0;i<1;i++){
      QTableWidgetItem* itm=new QTableWidgetItem(vec[i].expr);
      ui->table->setItem(i,0,itm);

      QTableWidgetItem* itm1=new QTableWidgetItem(QString::number(vec[i].a));
      ui->table->setItem(i,1,itm1);

      QTableWidgetItem* itm2=new QTableWidgetItem(QString::number(vec[i].b));
      ui->table->setItem(i,2,itm2);

      QTableWidgetItem* itm3=new QTableWidgetItem(QString::number(vec[i].c));
      ui->table->setItem(i,3,itm3);

      QTableWidgetItem* itm4=new QTableWidgetItem(QString::number(vec[i].d));
      ui->table->setItem(i,4,itm4);

      QTableWidgetItem* itm5=new QTableWidgetItem(QString::number(vec[i].e));
      ui->table->setItem(i,5,itm5);


   //   QTableWidgetItem* itm6=new QTableWidgetItem(QString(str3));//Translate::rpw(vec[i].expr)
    // ui->table->setItem(i,6,itm6);
  }
  }
Widget::~Widget()
{
    delete ui;
}

