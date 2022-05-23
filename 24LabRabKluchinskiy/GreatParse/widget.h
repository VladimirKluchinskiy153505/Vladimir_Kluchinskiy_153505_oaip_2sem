#ifndef WIDGET_H
#define WIDGET_H
#include <QString>
struct Function{
    Function(){}
    Function(QString str,int row,int pos):str(str),row(row),pos(pos){}
    QString str;
    int row;
    int pos;
};
struct Var{
    Var(){}
    Var(QString str,int row,int pos):str(str),row(row),pos(pos){}
    QString str;
    int row;
    int pos;
};
struct ClaSS{
    ClaSS(){}
    ClaSS(QString str,int row,int pos):str(str),row(row),pos(pos){}
    QString str;
    int row;
    int pos;
};
struct Structure{
    Structure(){}
    Structure(QString str,int row,int pos):str(str),row(row),pos(pos){}
    QString str;
    int row;
    int pos;
};
struct Array{
    Array(){}
    Array(QString str,int row,int pos):str(str),row(row),pos(pos){}
    QString str;
    int row;
    int pos;
};

#include <QWidget>
#include<my_vec.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void check_funktions(QString&str,int row);
    void print_functions();
    void check_var(QString& str,int row);
    void print_vars();
    void check_class(QString& str,int row);
    void print_class();
    void check_struct(QString& str,int row);
    void print_struct();
    void check_arrays(QString& str,int row);
    void print_arrays();
    void count_branching();
    void print_branching();
    void find_mistakes();
    void print_mistakes();
    void filling();
void print();
private:
    Ui::Widget *ui;
     QString filename;
     my_vec<Function> FunkList;
     my_vec<Var>VarList;
     my_vec<ClaSS>ClassList;
     my_vec<Structure>StructList;
     my_vec<Array> ArrList;
     my_vec<int> Branching;
     int amount_of_global_vars;
     QString global;
     my_vec<QString> Mistake;
};
#endif // WIDGET_H
