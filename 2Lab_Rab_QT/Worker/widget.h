#ifndef WIDGET_H
#define WIDGET_H

#include "worker.h"
#include "info.h"
#include "my_deque.h"
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>
#include <QDebug>
#include <QWidget>
#include <QListWidget>
QT_BEGIN_NAMESPACE
class Info;
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
friend Info;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void on_list_work_itemClicked(QListWidgetItem *item);
    void fill_res_list();
    void on_enter_criteria_clicked();
    void fill_salary_list();
    void fill_hours_list();
    void fill_over_list();

    void on_pushButton_clicked();

    void on_add_one_clicked();
void fill_list();
private:
    Ui::Widget *ui;
    QString filename;
    my_deque <worker>dec;
    int index;
    double salary;
    double hours;
};
#endif // WIDGET_H
