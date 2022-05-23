#ifndef DELETING_H
#define DELETING_H

#include <QWidget>
#include <QWidget>
#include <widget.h>
class Widget;
namespace Ui {
class Deleting;
}
class Deleting : public QWidget
{
    friend Widget;
    Q_OBJECT

public:
    explicit Deleting(Widget* ptr,QWidget *parent = nullptr);
    ~Deleting();

private slots:
    void on_del_button_clicked();
signals:
    void del_info();
private:
    Ui::Deleting *ui;
    Widget* ptr;
};

#endif // DELETING_H
