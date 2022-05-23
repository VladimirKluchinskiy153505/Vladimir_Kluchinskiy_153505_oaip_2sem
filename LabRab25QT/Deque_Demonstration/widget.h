#ifndef WIDGET_H
#define WIDGET_H
#include<Deque.h>
#include <QWidget>

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

    void on_push_front_clicked();

    void on_pop_back_clicked();

    void on_pop_front_clicked();

    void on_push_back_clicked();
    void fill_deque();

    void on_clear_clicked();

    void on_empty_clicked();

    void on_see_element_clicked();

    void on_change_dir_clicked();

private:
    Ui::Widget *ui;
    QString filename;
    GreatDeque<int> deque;
};
#endif // WIDGET_H
