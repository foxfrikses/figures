#ifndef BASEDRAWABLE_H
#define BASEDRAWABLE_H

#include <QtCore/qglobal.h>
#include <QPoint>
#include <QPainter>

class BaseDrawable
{
public:
    BaseDrawable(){}
    virtual bool isDrawable() const {return true;}
    virtual void draw(QPaintDevice*) const = 0;
    virtual bool includesPoint(QPoint) const {return false;}
    virtual ~BaseDrawable(){}
};

#endif // BASEDRAWABLE_H
