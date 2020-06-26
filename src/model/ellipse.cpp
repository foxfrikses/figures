#include "ellipse.h"
#include <QtCore/qmath.h>

Ellipse::Ellipse(QRect rect)
{
    this->rect = rect;
}

QPoint Ellipse::getCenter()
{
    return QPoint(rect.left() + rect.width()/2, rect.top() + rect.height()/2);
}

void Ellipse::draw(QPaintDevice *paintDevice)
{
    QPainter painter(paintDevice);
    painter.drawEllipse(rect);
}

bool Ellipse::includesPoint(QPoint p)
{
    QPoint center = getCenter();
    return qPow(((p.x() - center.x()) / (qreal)rect.width()), 2) +
           qPow(((p.y() - center.y()) / (qreal)rect.height()), 2) <= 1;
}
