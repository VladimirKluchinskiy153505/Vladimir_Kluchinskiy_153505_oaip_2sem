#ifndef WIDGET_H
#define WIDGET_H
#include <QDebug>
#include <QFileDialog>
#include <QWidget>
#include <QMessageBox>
#include <QTextStream>
#include <QListWidget>

#include "man.h"
#include "woman.h"
#include "pair.h"
#include "adding.h"
#include "deleting.h"
#include "editing.h"
#include "editingdialog.h"
#include "makepairs.h"

class Man;
class Woman;
class Adding;
class Deleting;
class Editing;
class EditingDialog;
class MakePairs;
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    friend Adding;
    friend Deleting;
    friend Editing;
    friend EditingDialog;
    friend MakePairs;
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_manBox_activated(int index);

    void on_womanBox_activated(int index);

    void on_show_coupes_clicked();

    void on_man_info_clicked();

    void on_women_info_clicked();

    void on_add_man_clicked();
      void add_new_man();

      void on_add_woman_clicked();
      void add_new_woman();

      void on_del_man_clicked();
      void del_man();

      void on_del_woman_clicked();
      void del_woman();


      void on_edit_man_clicked();
      void edit_man();

      void on_edit_woman_clicked();
      void edit_woman();
      void update_dream_vector();
      void update_man_box();
      void update_woman_info();

private:
    void push_back(Man obj, Man *&arr, int &man_size_reserved, int &man_size);
     void push_back(Woman obj, Woman *&arr, int &woman_size_reserved, int &woman_size);
     bool satisfy(const Man& man,const Woman& woman);
     bool satisfy(const Woman& woman, const Man& man);
     void print();
    Ui::Widget *ui;
    Man* arrMan;
    Woman* arrWoman;
    QString man_filename;
    QString woman_filename;
    int man_size;
    int woman_size;
    int man_size_reserved;
    int woman_size_reserved;
    int num_man_to_del;
    int num_woman_to_del;
    int num_man_to_edit;
    int num_woman_to_edit;
    QVector<Pair> couple;
};
#endif // WIDGET_H
