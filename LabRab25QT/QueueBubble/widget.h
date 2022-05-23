#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <Queue.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
void print_queue();
void fill_list();
private slots:
void on_pushButton_clicked();

void on_change_directory_clicked();

private:
    Ui::Widget *ui;
    QString filename;
    BuQueue<int> queue;
};
#endif // WIDGET_H
