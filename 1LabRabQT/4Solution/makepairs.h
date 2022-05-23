#ifndef MAKEPAIRS_H
#define MAKEPAIRS_H

#include <QWidget>
#include "widget.h"
namespace Ui {
class MakePairs;
}

class MakePairs : public QWidget
{
    Q_OBJECT

public:
    explicit MakePairs(Widget*ptr,QWidget *parent = nullptr);
    ~MakePairs();

private slots:
    void on_make_pair_clicked();

private:
    Ui::MakePairs *ui;
    Widget* ptr;
    QListWidget* select;
    QListWidget*  result;
};

#endif // MAKEPAIRS_H
