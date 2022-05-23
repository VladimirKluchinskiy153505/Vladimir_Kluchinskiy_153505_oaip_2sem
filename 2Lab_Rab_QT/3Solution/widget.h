#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include "Recovery.h"
#include "my_stack.h"

class Expression{
public:
    Expression(QString expr,double a,double b,double c,double d,double e):expr(expr),a(a),b(b),c(c),d(d),e(e){};
    Expression(){};
    QString get_expr(){
        return expr;
    }
    QString expr;
    double a,b,c,d,e;
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

private:
    Ui::Widget *ui;
    QString filename;
    QVector<Expression> vec;
};
#endif // WIDGET_H
