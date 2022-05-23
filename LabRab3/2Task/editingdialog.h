#ifndef EDITINGDIALOG_H
#define EDITINGDIALOG_H

#include <QWidget>
#include "widget.h"
#include "place.h"
class Widget;
namespace Ui {
class EditingDialog;
}

class EditingDialog : public QWidget
{
    Q_OBJECT

public:
    explicit EditingDialog(Widget* ptr,QWidget *parent = nullptr);
    ~EditingDialog();
signals:
    void edit_info();
private slots:
    void on_pushButton_clicked();

private:
    Ui::EditingDialog *ui;
    Widget* ptr;
    Date date;
    QString dest;
    Time time;
    int number;
};

#endif // EDITINGDIALOG_H
