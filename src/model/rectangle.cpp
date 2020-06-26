#include "rectangle.h"

Rectangle::Rectangle(QRect rect)
{
    this->rect = rect;
}

QPoint Rectangle::getCenter() const
{
    return QPoint(rect.left() + rect.width()/2, rect.top() + rect.height()/2);
}

void Rectangle::draw(QPaintDevice *paintDevice) const
{
    QPainter painter(paintDevice);
    painter.drawRect(rect);
}

bool Rectangle::includesPoint(QPoint p) const
{
    return p.x() <= rect.right()  && p.x() >= rect.left() &&
           p.y() <= rect.bottom() && p.y() >= rect.top();
}
