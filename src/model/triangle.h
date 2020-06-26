#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QtCore/qglobal.h>
#include "figure.h"

class Triangle : public Figure
{
public:
    Triangle(QRect);

    QPoint getCenter() const override;
    void draw(QPaintDevice*) const override;
    bool includesPoint(QPoint) const override;
    void move(QPoint) override;

protected:
    QPoint a, b, c;
};

#endif // TRIANGLE_H
