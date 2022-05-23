#ifndef ADDING_H
#define ADDING_H
#include<widget.h>
#include <QWidget>
#include "place.h"
class Widget;
namespace Ui {
class Adding;
}

class Adding : public QWidget
{
    Q_OBJECT

public:
    explicit Adding(Widget* ptr,QWidget *parent = nullptr);
    ~Adding();
signals:
   void add_info();
private slots:
    void on_save_clicked();

private:
    Ui::Adding *ui;
    Widget* ptr;
    Date date;
    QString dest;
    Time time;
    int number;

};

#endif // ADDING_H
