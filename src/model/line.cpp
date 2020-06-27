#include "line.h"
#include <QPoint>

Line::Line(iterator from, iterator to)
{
    this->from = from;
    this->to = to;
}

void Line::draw(QPaintDevice *paintDevice) const
{
    auto f = (*from)->getCenter();
    auto t = (*to)->getCenter();
    QPainter painter(paintDevice);
    painter.drawLine(f, t);
}
