#ifndef VIEWSQUARE_H
#define VIEWSQUARE_H
#include "movesquare.h"
#include <QWidget>
class Quadrate;
namespace Ui {
class ViewSquare;
}

class ViewSquare : public QWidget
{
    Q_OBJECT

public:
    explicit ViewSquare(QWidget *parent = nullptr);
    ~ViewSquare();
static Quadrate* obj;
private slots:

void on_see_square_clicked();

void on_see_perimetr_clicked();

void on_see_centroid_clicked();

private:
    Ui::ViewSquare *ui3;
    int H;
    int W;
    double s;
    double rt;
    char tp;
};

#endif // VIEWSQUARE_H
