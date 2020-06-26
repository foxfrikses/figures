#include "rectangle.h"

Rectangle::Rectangle(QRect rect)
{
    this->rect = rect;
}

QPoint Rectangle::getCenter()
{
    return QPoint(rect.left() + rect.width()/2, rect.top() + rect.height()/2);
}

void Rectangle::draw(QPaintDevice *paintDevice)
{
    QPainter painter(paintDevice);
    painter.drawRect(rect);
}

bool Rectangle::includesPoint(QPoint p)
{
    return p.x() <= rect.right()  && p.x() >= rect.left() &&
           p.y() <= rect.bottom() && p.y() >= rect.top();
}
