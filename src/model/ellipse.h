#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QtCore/qglobal.h>
#include "figure.h"

class Ellipse : public Figure
{
public:
    Ellipse(QRect);

    QPoint getCenter() override;
    void draw(QPaintDevice*) override;
    bool includesPoint(QPoint) override;

protected:
    QRect rect;
};

#endif // ELLIPSE_H
