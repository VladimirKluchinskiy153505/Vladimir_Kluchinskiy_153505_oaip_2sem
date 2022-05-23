#ifndef ADDING_H
#define ADDING_H

#include <QWidget>
#include <widget.h>
class Widget;
namespace Ui {
class Adding;
}

class Adding : public QWidget
{
    friend Widget ;
    Q_OBJECT

public:
    explicit Adding(Widget* ptr,QWidget *parent = nullptr);
    ~Adding();

private slots:
    void on_enter_clicked();
signals:
    void renew_info();
private:
    Ui::Adding *ui;
    Widget* ptr;
};

#endif // ADDING_H
