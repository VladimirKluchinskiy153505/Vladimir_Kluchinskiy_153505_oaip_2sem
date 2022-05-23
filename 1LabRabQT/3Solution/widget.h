#ifndef WIDGET_H
#define WIDGET_H
#include "date.h"
#include "birthday.h"
#include "adding.h"
#include "editing.h"
#include "deleting.h"
#include <QFile>
#include <QTextStream>
#include <QWidget>
#include <QMessageBox>
class Adding;
class Editing;
class Deleting;
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
class Birthday;
class Widget : public QWidget
{
    friend Editing;
    friend Birthday ;
    friend Adding;
    friend Deleting;
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void push_back(Date& obj, Date*& arr, int& res_size, int& date_size);
    void init_current_day();
public slots:
    void on_enter_birthday_clicked();
    void save_new_birthday();
   // void save_new_birth_date();

private slots:
    void on_show_nextday_clicked();

    void on_show_prev_day_clicked();

    void on_is_leap_clicked();

    void on_week_number_clicked();

    void on_days_till_birth_clicked();

    void on_diff_with_prev_clicked();

    void on_duration_clicked();

    void on_add_newone_clicked();
    void add_new_date();
    void on_edit_one_clicked();
    void edit_existing_date();

    void on_delete_one_clicked();
    void delete_existing_date();

    void on_week_day_clicked();

private:
    Ui::Widget *ui;
    Birthday* blank;
    Adding* blank1;
    Editing* blank2;
    Deleting* blank3;
    int date_size;
     int res_size = 2;
     int num_to_edit0;
     int num_to_delete0;
      Date* arr;
      QString addinformation;
      QString editinformation;
      QString filename;
};
#endif // WIDGET_H
