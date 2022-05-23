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
    explicit Deleting(Widget* ptr,QWidget *parent = nullptr);
    ~Deleting();
signals:
    void delete_info();

private slots:


    void on_save_button_clicked();

private:
    Ui::Deleting *ui;
    Widget* ptr;
};

#endif // DELETING_H
