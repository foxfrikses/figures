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
    bool isDrawable() const override;
    QChar ch() const override {return 't';}
    int left()   const { return c.x(); }
    int right()  const { return b.x(); }
    int top()    const { return a.y(); }
    int bottom() const { return b.y(); }

    void setRect(QRect);

protected:
    QPoint a, b, c;
};

#endif // TRIANGLE_H
