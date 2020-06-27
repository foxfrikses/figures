#include "triangle.h"

Triangle::Triangle(QRect rect)
{
    setRect(rect);
}

QPoint Triangle::getCenter() const
{
    return QPoint(a.x(), (a.y() + b.y() * 2) / 3 );
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
    a = QPoint{a.x() + d.x(), a.y() + d.y()};
    b = QPoint{b.x() + d.x(), b.y() + d.y()};
    c = QPoint{c.x() + d.x(), c.y() + d.y()};
}

void Triangle::setRect(QRect rect)
{
    int lef = rect.left();
    int rig = rect.right();
    int top = rect.top();
    int bot = rect.bottom();
    if (lef > rig) qSwap(lef, rig);
    if (top > bot) qSwap(top, bot);

    this->a = {(lef + rig) / 2, top};
    this->b = {rig, bot};
    this->c = {lef, bot};
}

bool Triangle::isDrawable() const {
    if (b.x() < 0 ||
        b.y() < 0 ||
        a.y() == b.y() ||
        b.x() == c.x())
        return false;
    else return true;
}
