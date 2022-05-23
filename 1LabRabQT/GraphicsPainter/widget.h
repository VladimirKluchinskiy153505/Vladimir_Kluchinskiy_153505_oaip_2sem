#ifndef WIDGET_H
#define WIDGET_H
#include "graphicspainter.h"
#include "movesquare.h"
#include "info.h"
#include "centroid.h"
#include "viewsquare.h"
#include "triangle.h"
#include <QWidget>

#include<QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QGraphicsEllipseItem>
#include <QTimer>

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

    void on_openCanvas_clicked();

    void on_add_Square_clicked();

    void on_Enter_Information_clicked();

    void on_change_centroid_clicked();

    void on_See_Sq_Per_Centr_clicked();

   void on_add_rectangle_clicked();


    void on_del_last_clicked();

    void on_add_rhomb_clicked();

    void on_add_circle_clicked();

    void on_add_triangle_clicked();

    void on_add_hexagon_clicked();

    void on_add_5star_clicked();

    void on_add_6star_clicked();

    void on_add_8star_clicked();

private:
    QVector<QObject*> vec;
    Ui::Widget *ui;
    QGraphicsScene* scene;
    GraphicsPainter *canvas;
    QTimer* timer;
    Info* info;
    Centroid* centroid;
    ViewSquare* viewsquare;
};
#endif // WIDGET_H
