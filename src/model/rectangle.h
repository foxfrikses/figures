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
    bool isDrawable() const override;
    QChar ch() const override {return 'r';}
    int left()   const { return rect.left(); }
    int right()  const { return rect.right(); }
    int top()    const { return rect.top(); }
    int bottom() const { return rect.bottom(); }


    void setRect(QRect);

protected:
    QRect rect;
};

#endif // RECTANGLE_H
