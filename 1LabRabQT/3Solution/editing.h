#ifndef EDITING_H
#define EDITING_H

#include <QWidget>
#include "widget.h"
class Widget;
namespace Ui {
class Editing;
}

class Editing : public QWidget
{
    Q_OBJECT

public:
    explicit Editing(Widget* ptr,QWidget *parent = nullptr);
    ~Editing();

private slots:
    void on_enter_number_clicked();
    void on_save_update_clicked();

signals:
    void update_info();
private:
    Ui::Editing *ui;
    Widget* ptr;
};

#endif // EDITING_H
