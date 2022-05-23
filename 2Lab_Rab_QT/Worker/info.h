#ifndef INFO_H
#define INFO_H

#include <QWidget>
#include "widget.h"
class Widget;
namespace Ui {
class Info;
}

class Info : public QWidget
{
    Q_OBJECT

public:
    explicit Info(Widget* ptr,QWidget *parent = nullptr);
    ~Info();
signals:
   void renew();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Info *ui;
    Widget* ptr;
};

#endif // INFO_H
