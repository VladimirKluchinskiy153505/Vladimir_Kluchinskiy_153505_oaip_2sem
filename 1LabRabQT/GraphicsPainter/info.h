#ifndef INFO_H
#define INFO_H
#include "movesquare.h"
#include <QWidget>
class Quadrate;
namespace Ui {
class Info;
}

class Info : public QWidget
{
    Q_OBJECT
    friend Quadrate;

public:
     static Quadrate* obj;
    explicit Info(QWidget *parent = nullptr);
    ~Info();

private slots:
    void on_save_information_clicked();

private:
    Ui::Info *ui2;


};

#endif // INFO_H
