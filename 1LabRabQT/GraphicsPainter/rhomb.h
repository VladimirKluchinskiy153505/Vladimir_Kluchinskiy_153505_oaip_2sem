#ifndef RHOMB_H
#define RHOMB_H

#include "rectangle.h"

class Rhomb : public Rectangle
{
public:
    explicit Rhomb(QObject *parent = nullptr);
      void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // RHOMB_H
