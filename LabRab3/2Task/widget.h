#ifndef WIDGET_H
#define WIDGET_H
#include "place.h"
#include "My_Deque.h"
#include "place.h"
#include "deleting.h"
#include "adding.h"
#include "editing.h"
#include "editingdialog.h"
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>
#include <QDebug>
#include <QWidget>
#include <QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
class Place;
class Deleting;
class Adding;
class EditingDialog;
class Editing;
class Widget : public QWidget
{
    friend Deleting;
    friend Adding;
    friend EditingDialog;
    friend Editing;
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
void print_dec(my_deque<Place>&dec1);
private slots:

void on_see_info_clicked();

void on_del_one_clicked();
void del_place();
void add_place();
void edit_place();
void fill_list();
void fill_suitable_list();

void on_add_one_clicked();

void on_edit_one_clicked();

void on_enter_date_clicked();

void on_dest_list_itemClicked(QListWidgetItem *item);

void on_open_directory_clicked();

void on_qsort1_clicked();

void on_qsort2_clicked();

private:
    Ui::Widget *ui;
      QString filename;
      my_deque<Place> dec;
      int num_to_del;
      int num_to_edit;
      int ind;
      Date departure;
};
#endif // WIDGET_H
