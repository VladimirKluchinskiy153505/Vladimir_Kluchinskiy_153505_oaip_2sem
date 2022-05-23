#ifndef DELETING_H
#define DELETING_H

#include <QWidget>
#include "widget.h"
class Widget;
namespace Ui {
class Deleting;
}

class Deleting : public QWidget
{
    Q_OBJECT

public:
    explicit Deleting(int gender,Widget* ptr,QWidget *parent = nullptr);
    ~Deleting();
signals:
    void delete_info();

private slots:

    void on_pushButton_clicked();

private:
    Ui::Deleting *ui;
    int gender;
    Widget* ptr;
};

#endif // DELETING_H
