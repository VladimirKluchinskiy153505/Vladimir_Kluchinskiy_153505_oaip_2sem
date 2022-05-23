#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "movesquare.h"

class Triangle : public Quadrate
{
public:
    explicit Triangle(QObject *parent = nullptr);
         void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // TRIANGLE_H
