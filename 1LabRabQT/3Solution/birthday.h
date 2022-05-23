#ifndef BIRTHDAY_H
#define BIRTHDAY_H
#include "widget.h"
#include <QWidget>

namespace Ui {
class Birthday;
}
class Birthday : public QWidget
{
    Q_OBJECT

public:
    explicit Birthday(QWidget *parent = nullptr);
    ~Birthday();

private slots:

    void on_enter_day_clicked();

    void on_enter_month_clicked();

    void on_enter_year_clicked();

    void on_save_clicked();
signals:
    void save_birth_date();
protected:
    int d,m,y;
private:
    Ui::Birthday *ui;
};

#endif // BIRTHDAY_H
