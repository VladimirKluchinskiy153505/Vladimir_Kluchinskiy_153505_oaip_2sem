#ifndef WIDGET_H
#define WIDGET_H
#include<QDebug>
#include <QWidget>
#include<ultra_bit_set.h>
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
    void on_enter_button_clicked();

    void on_button_get_string_clicked();

    void on_button_get_ULong_clicked();

    void on_button_get_ULongLong_clicked();

    void on_button_get_bit_clicked();

    void on_all_button_clicked();

    void on_any_button_clicked();

    void on_count_button_clicked();

    void on_flip_button_clicked();

    void on_none_button_clicked();

    void on_reset_button_clicked();

    void on_set_button_clicked();

    void on_size_button_clicked();

    void on_test_button_clicked();

private:
    Ui::Widget *ui;
    QString filename;
    bit_set* set_ptr=nullptr;

};
#endif // WIDGET_H
