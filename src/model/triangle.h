#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QtCore/qglobal.h>
#include "figure.h"

class Triangle : public Figure
{
public:
    Triangle(QRect);

    QPoint getCenter() override;
    void draw(QPaintDevice*) override;
    bool includesPoint(QPoint) override;

protected:
    QPoint a, b, c;
};

#endif // TRIANGLE_H
