#ifndef ADDING_H
#define ADDING_H

#include <QWidget>
#include "widget.h"
class Widget;
namespace Ui {
class Adding;
}

class Adding : public QWidget
{
    Q_OBJECT

public:
    explicit Adding(int gender,Widget* ptr,QWidget *parent = nullptr);
    ~Adding();

private slots:
    void on_save_clicked();
    signals:
    void renew_info();

private:
    int gender;
    Ui::Adding *ui;
    int number;
    QString name;
    int age;
    int height;
    int weight;
    QString custom;
    QString hobby;
    Demands claim;
    Widget* ptr;
};

#endif // ADDING_H
