#ifndef FIGURE_H
#define FIGURE_H

#include <QtCore/qglobal.h>
#include "basedrawable.h"

class Figure : public BaseDrawable
{
public:
    Figure();
    const QPoint& getCenter(){return center;}
private:
    QPoint center;
};

#endif // FIGURE_H
