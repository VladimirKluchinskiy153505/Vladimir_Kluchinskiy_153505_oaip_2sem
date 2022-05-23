#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>
#include <QDebug>
#include "my_stack.h"
struct ex_char{
public:
    ex_char(QChar symb,int num):symb(symb),num(num){};
    ex_char(){};
    QChar symb;
    int num;
    bool operator!=(const QChar& other){
        return (this->symb!=other);
    }
};
struct info_about_rows{
    info_about_rows(int number,int count):row_number(number),sum_symb(count){};
    info_about_rows(){};
    int row_number;
    int sum_symb;
};
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
bool check(QString& str);
private slots:
void on_change_dir_clicked();
void entering();
private:
    Ui::Widget *ui;
    QString filename;
    QString text;
     int failed_num;
     QVector<info_about_rows> vec;
     int amount_of_rows;
};
#endif // WIDGET_H
