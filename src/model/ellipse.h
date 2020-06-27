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
    QChar ch() const override {return 'e';}
    int left()   const { return rect.left(); }
    int right()  const { return rect.right(); }
    int top()    const { return rect.top(); }
    int bottom() const { return rect.bottom(); }

    void setRect(QRect);

protected:
    QRect rect;
};

#endif // ELLIPSE_H
