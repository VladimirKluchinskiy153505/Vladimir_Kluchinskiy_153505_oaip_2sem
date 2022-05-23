#ifndef WIDGET_H
#define WIDGET_H
#include<Hash.h>
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
 int randomBetween(int num);
 void fill_table();
private slots:
 void on_eraze_button_clicked();

 void on_insert_button_clicked();

 void on_find_button_clicked();

 void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QString filename;
    HashTable<int,QString> hash_table;
};
#endif // WIDGET_H
