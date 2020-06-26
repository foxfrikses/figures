#include "line.h"

Line::Line(iterator from, iterator to)
{
    this->from = from;
    this->to = to;
}

void Line::draw(QPaintDevice *paintDevice)
{
    QPainter painter(paintDevice);
    painter.drawLine((*from)->getCenter(), (*to)->getCenter());
}
