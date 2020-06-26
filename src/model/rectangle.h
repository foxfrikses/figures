#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QtCore/qglobal.h>
#include "figure.h"

class Rectangle : public Figure
{
public:
    Rectangle(QRect);

    QPoint getCenter() const override;
    void draw(QPaintDevice*) const override;
    bool includesPoint(QPoint) const override;
    void move(QPoint) override;

protected:
    QRect rect;
};

#endif // RECTANGLE_H
