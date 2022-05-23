#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include<QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QGraphicsEllipseItem>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
///////////////

 class Triangle:public QGraphicsItem{
public:
    Triangle(QGraphicsEllipseItem* parrent);
    ~Triangle();
protected:
      QRectF boundingRect() const override;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

 class Zrachok:public QGraphicsItem{
public:
    Zrachok(QGraphicsEllipseItem* parrent);
    ~Zrachok();
protected:
      QRectF boundingRect() const override;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    virtual ~Widget();
protected:
    Ui::Widget *ui;
    QGraphicsScene* scene;
    QTimer* animationTimer;
private:
};
//////////////
class Ellipse:public QGraphicsEllipseItem{
public:
    Ellipse(QPointF initPos,QColor color,int w,int h,int spread,QGraphicsItem* parent);
      void advance(int phase) override;
    void change1();
    void change2();


private:
    int xspeed;
    int yspeed;
    int w;
    int h;
    int Spread;
    bool flag1=true;
    bool flag2=true;
    QPointF InitPos;
    QColor Color;
};
////////////
class Eye:public Ellipse{
public:
    Eye(QPointF initPos,QColor color, int w, int h, int spread, QGraphicsItem *parent);
    // void advance(int phase) override;
     ~Eye();
};
///////
class UpLips:public Ellipse{
public:UpLips(QPointF initPos,QColor color, int w, int h, int spread, QGraphicsItem *parent);
    void advance(int phase) override;
  void change();
private:
    int xspeed;
    int yspeed;
    int w;
    int h;
    int Spread;
    bool flag=true;
    QPointF InitPos;
    QColor Color;
};
class LowLips:public Ellipse{
public:LowLips(QPointF initPos,QColor color, int w, int h, int spread, QGraphicsItem *parent);
    void advance(int phase) override;
  void change();
private:
    int xspeed;
    int yspeed;
    int w;
    int h;
    int Spread;
    bool flag=true;
    QPointF InitPos;
    QColor Color;
};


#endif // WIDGET_H
