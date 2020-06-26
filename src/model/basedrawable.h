#ifndef BASEDRAWABLE_H
#define BASEDRAWABLE_H

#include <QtCore/qglobal.h>
#include <QPoint>
#include <QPainter>

class BaseDrawable
{
public:
    BaseDrawable(){}
    virtual void draw(QPaintDevice*) = 0;
    virtual bool includesPoint(QPoint){return false;}
    virtual ~BaseDrawable(){}
};

#endif // BASEDRAWABLE_H
