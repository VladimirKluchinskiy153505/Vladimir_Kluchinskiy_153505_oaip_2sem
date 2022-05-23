#ifndef CIRCLE_H
#define CIRCLE_H
#include "movesquare.h"

class Circle : public Quadrate
{
public:
    explicit Circle(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // CIRCLE_H
