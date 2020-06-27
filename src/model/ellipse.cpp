#include "ellipse.h"
#include <QtCore/qmath.h>

Ellipse::Ellipse(QRect rect)
{
    setRect(rect);
}

QPoint Ellipse::getCenter() const
{
    return QPoint(rect.left() + rect.width()/2, rect.top() + rect.height()/2);
}

void Ellipse::draw(QPaintDevice *paintDevice) const
{
    if (isDrawable()) {
        QPainter painter(paintDevice);
        painter.drawEllipse(rect);
    }
}

bool Ellipse::includesPoint(QPoint p) const
{
    QPoint center = getCenter();
    return qPow(((p.x() - center.x()) / (qreal)rect.width()), 2) +
           qPow(((p.y() - center.y()) / (qreal)rect.height()), 2) <= 0.25;
}

void Ellipse::move(QPoint d)
{
    rect.setCoords(rect.left()   + d.x(),
                   rect.top()    + d.y(),
                   rect.right()  + d.x(),
                   rect.bottom() + d.y());
}

bool Ellipse::isDrawable() const
{
    if (rect.top() == rect.bottom() ||
        rect.left() == rect.right() ||
        rect.bottom() < 0 ||
        rect.right() < 0)
        return false;
    else return true;
}

void Ellipse::setRect(QRect rect)
{
    int lef = rect.left();
    int rig = rect.right();
    int top = rect.top();
    int bot = rect.bottom();
    if (lef > rig) qSwap(lef, rig);
    if (top > bot) qSwap(top, bot);

    this->rect.setCoords(lef, top, rig, bot);
}
