#include "triangle.h"

Triangle::Triangle(QRect rect)
{
    int l = qMin(rect.left(), rect.right());
    int r = qMax(rect.left(), rect.right());
    int t = qMin(rect.top(),  rect.bottom());
    int b = qMax(rect.top(),  rect.bottom());

    this->a = {l + rect.width()/2, t};
    this->b = {r, b};
    this->c = {l, b};
}

QPoint Triangle::getCenter() const
{
    return QPoint(a.x(), a.y() + (b.y() - a.y())/2);
}

void Triangle::draw(QPaintDevice *paintDevice) const
{
    if (isDrawable()) {
        QPainter painter(paintDevice);
        painter.drawLine(a,b);
        painter.drawLine(b,c);
        painter.drawLine(c,a);
    }
}

bool Triangle::includesPoint(QPoint p) const
{
    return (p.y() - a.y())*(a.x() - b.x()) - (p.x() - a.x()) * (a.y() - b.y()) <= 0 &&
           (p.y() - a.y())*(a.x() - c.x()) - (p.x() - a.x()) * (a.y() - c.y()) >= 0;
}

void Triangle::move(QPoint d){
    a = {a.x() + d.x(), a.y() + d.y()};
    b = {b.x() + d.x(), b.y() + d.y()};
    c = {c.x() + d.x(), c.y() + d.y()};
}

void Triangle::setRect(QRect rect)
{
    int l = qMin(rect.left(), rect.right());
    int r = qMax(rect.left(), rect.right());
    int t = qMin(rect.top(),  rect.bottom());
    int b = qMax(rect.top(),  rect.bottom());

    this->a = {l + rect.width()/2, t};
    this->b = {r, b};
    this->c = {l, b};
}

bool Triangle::isDrawable() const {
    if (b.x() < 0 ||
        b.y() < 0 ||
        a.y() == b.y() ||
        b.x() == c.x())
        return false;
    else return true;
}
