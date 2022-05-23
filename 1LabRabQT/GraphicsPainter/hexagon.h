#ifndef HEXAGON_H
#define HEXAGON_H
#include "movesquare.h"

class Hexagon : public Quadrate
{
public:
    explicit Hexagon(QObject *parent = nullptr);
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // HEXAGON_H
