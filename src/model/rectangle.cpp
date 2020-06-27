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
    if (isDrawable()) {
        QPainter painter(paintDevice);
        painter.drawRect(rect);
    }
}

bool Rectangle::includesPoint(QPoint p) const
{
    return p.x() <= rect.right()  && p.x() >= rect.left() &&
           p.y() <= rect.bottom() && p.y() >= rect.top();
}

void Rectangle::move(QPoint d){
    rect.setCoords(rect.left()   + d.x(),
                   rect.top()    + d.y(),
                   rect.right()  + d.x(),
                   rect.bottom() + d.y());
}

void Rectangle::setRect(QRect rect)
{
    this->rect.setCoords(rect.left(), rect.top(), rect.right(), rect.bottom());
}

bool Rectangle::isDrawable() const {
    if (rect.top() == rect.bottom() ||
        rect.left() == rect.right() ||
        rect.bottom() < 0 ||
        rect.right() < 0)
        return false;
    else return true;
}
