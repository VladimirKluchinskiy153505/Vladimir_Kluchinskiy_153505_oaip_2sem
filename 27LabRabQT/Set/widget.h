#ifndef WIDGET_H
#define WIDGET_H
#include<QDebug>
#include <AVL_Set.h>
#include <QWidget>
#include<QTreeWidgetItem>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
 void on_eraze_range_button_clicked();

 void on_eraze_button_clicked();

 void on_insert_button_clicked();

 void on_find_button_clicked();

 void on_find_min_button_clicked();

 void on_find_min_rec_button_clicked();

 void on_find_max_button_clicked();

 void on_find_max_rec_button_clicked();

 void on_clear_button_clicked();

 void on_pre_travel_button_clicked();

 void on_in_travel_button_clicked();

 void on_pos_travel_button_clicked();

 void on_change_dir_button_clicked();

 void on_button_iterator_clicked();

 void on_rcons_button_clicked();

 void on_findLB_button_clicked();

 void on_FindUB_button_2_clicked();

private:
    Ui::Widget *ui;
    QString filename;
    avl_set<long long int> set;
    typedef decltype(set.get_root()) ptr_type;
    void fill_table();
    void fill_table2(ptr_type root_ptr, QTreeWidgetItem *root_item);
};
#endif // WIDGET_H
