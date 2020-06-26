#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QtCore/qglobal.h>
#include "figure.h"

class Rectangle : public Figure
{
public:
    Rectangle(QRect);

    QPoint getCenter() override;
    void draw(QPaintDevice*) override;
    bool includesPoint(QPoint) override;

protected:
    QRect rect;
};

#endif // RECTANGLE_H
