#include "triangle.h"

Triangle::Triangle(QRect rect)
{
    a = {rect.left() + rect.width()/2, rect.top()};
    b = {rect.right(), rect.bottom()};
    c = {rect.left(), rect.bottom()};
}

QPoint Triangle::getCenter()
{
    return QPoint(a.x(), a.y() + (b.y() - a.y())/2);
}

void Triangle::draw(QPaintDevice *paintDevice)
{
    QPainter painter(paintDevice);
    painter.drawLine(a,b);
    painter.drawLine(b,c);
    painter.drawLine(c,a);
}

bool Triangle::includesPoint(QPoint p)
{
    return (p.y() - a.y())*(a.x() - b.x()) - (p.x() - a.x()) * (a.y() - b.y()) <= 0 &&
           (p.y() - a.y())*(a.x() - c.x()) - (p.x() - a.x()) * (a.y() - c.y()) >= 0;
}
