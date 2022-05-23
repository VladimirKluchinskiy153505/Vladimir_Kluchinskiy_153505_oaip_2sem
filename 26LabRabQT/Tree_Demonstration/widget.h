#ifndef WIDGET_H
#define WIDGET_H
#include<AVL_Tree.h>
#include <QWidget>
#include<QTreeWidgetItem>
template<typename T,typename U>
class AVL_Tree;
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void fill_table();
private slots:
    void on_eraze_button_clicked();

    void on_insert_button_clicked();

    void on_find_button_clicked();

    void on_find_min_button_clicked();

    void on_find_min_rec_button_clicked();

    void on_find_max_button_clicked();

    void on_find_max_rec_button_clicked();

    void on_clear_button_clicked();

    void on_fill_button_clicked();

    void on_change_dir_button_clicked();

    void on_pre_travel_button_clicked();

    void on_in_travel_button_clicked();

    void on_pos_travel_button_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QString filename;
    AVL_Tree<int,QString> tree;
     typedef decltype(tree.get_root()) ptr_type;
     void fill_table2(ptr_type ptr,QTreeWidgetItem* root_item);
};
#endif // WIDGET_H
