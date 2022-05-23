#ifndef CENTROID_H
#define CENTROID_H

#include <QWidget>
#include "movesquare.h"
class Quadrate;
namespace Ui {
class Centroid;
}

class Centroid : public QWidget
{
    Q_OBJECT

public:
    explicit Centroid(QWidget *parent = nullptr);
    ~Centroid();
  static Quadrate* obj;
private slots:

    void on_Save_Centroid_Information_clicked();

private:
    Ui::Centroid *ui1;
};

#endif // CENTROID_H
