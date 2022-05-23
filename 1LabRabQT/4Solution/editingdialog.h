#ifndef EDITINGDIALOG_H
#define EDITINGDIALOG_H

#include <QWidget>
#include "widget.h"
class Widget;
namespace Ui {
class EditingDialog;
}

class EditingDialog : public QWidget
{
    Q_OBJECT

public:
    explicit EditingDialog(int gender,Widget*ptr,QWidget *parent = nullptr);
    ~EditingDialog();
signals:
    void update_info();

private slots:
    void on_save_clicked();

private:
    Ui::EditingDialog *ui;
    int gender;
    int number;
    QString name;
    int age;
    int height;
    int weight;
    QString custom;
    QString hobby;
    Demands claim;
    Widget* ptr;
};

#endif // EDITINGDIALOG_H
