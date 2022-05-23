#ifndef EDITING_H
#define EDITING_H

#include <QWidget>
#include "widget.h"
namespace Ui {
class Editing;
}

class Editing : public QWidget
{
    Q_OBJECT

public:
    explicit Editing(int gender,Widget* widget,QWidget *parent = nullptr);
    ~Editing();

private slots:
    void on_pushButton_clicked();
signals:

private:
    Ui::Editing *ui;
    int gender;
    Widget* ptr;
};

#endif // EDITING_H
