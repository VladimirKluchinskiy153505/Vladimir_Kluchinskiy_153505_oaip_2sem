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
    explicit Adding(Widget* ptr,int flag,QWidget *parent = nullptr);
    ~Adding();
signals:
    void renew();
    void renew_prw();
private slots:
    void on_save_clicked();

private:
    Ui::Adding *ui;
    Widget* ptr;
    int flag;
};

#endif // ADDING_H
