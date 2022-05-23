#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include "adding.h"
#include "Recovery.h"
#include "my_stack.h"
#include "Translate.h"
#include "Expression.h"
#include "Calculation.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
class Adding;
class Widget : public QWidget
{
    Q_OBJECT
friend Adding;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_add_new_clicked();
    void add_new();
    void add_new_prw();

    void on_add_new_pwr_clicked();

private:
    Ui::Widget *ui;
    QString filename;
    QVector<Expression> vec;
};
#endif // WIDGET_H
