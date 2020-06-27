#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QtCore/qglobal.h>
#include "figure.h"

class Ellipse : public Figure
{
public:
    Ellipse(QRect);

    QPoint getCenter() const override;
    void draw(QPaintDevice*) const override;
    bool includesPoint(QPoint) const override;
    void move(QPoint) override;
    bool isDrawable() const override;

    void setRect(QRect);

protected:
    QRect rect;
};

#endif // ELLIPSE_H
