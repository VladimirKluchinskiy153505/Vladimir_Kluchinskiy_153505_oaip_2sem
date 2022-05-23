#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "movesquare.h"

class Rectangle : public Quadrate
{
public:
    explicit Rectangle(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // RECTANGLE_H
