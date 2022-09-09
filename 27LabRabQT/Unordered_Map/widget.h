#ifndef WIDGET_H
#define WIDGET_H
#include"UMap.h"
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
    void on_earaze_button_clicked();

    void on_insert_button_clicked();

    void on_find_button_clicked();

    void on_clear_button_clicked();
    void fill_table();

private:
    Ui::Widget *ui;
    QString filename;
    UMap<int,QString,std::hash<int>> umap;
};
#endif // WIDGET_H
