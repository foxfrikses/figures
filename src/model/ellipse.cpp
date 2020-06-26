#include "ellipse.h"
#include <QtCore/qmath.h>

Ellipse::Ellipse(QRect rect)
{
    this->rect = rect;
}

QPoint Ellipse::getCenter() const
{
    return QPoint(rect.left() + rect.width()/2, rect.top() + rect.height()/2);
}

void Ellipse::draw(QPaintDevice *paintDevice) const
{
    QPainter painter(paintDevice);
    painter.drawEllipse(rect);
}

bool Ellipse::includesPoint(QPoint p) const
{
    QPoint center = getCenter();
    return qPow(((p.x() - center.x()) / (qreal)rect.width()), 2) +
           qPow(((p.y() - center.y()) / (qreal)rect.height()), 2) <= 1;
}
