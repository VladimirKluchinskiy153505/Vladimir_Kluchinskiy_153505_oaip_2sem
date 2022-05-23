#ifndef EDITING_H
#define EDITING_H

#include <QWidget>
#include "widget.h"
#include "editingdialog.h"
class Widget;
namespace Ui {
class Editing;
}

class Editing : public QWidget
{
    Q_OBJECT

public:
    explicit Editing(Widget*ptr,QWidget *parent = nullptr);
    ~Editing();
signals:
private slots:
       void on_ok_clicked();

private:
    Ui::Editing *ui;
    Widget*ptr;
};

#endif // EDITING_H
