#ifndef FIGURE_H
#define FIGURE_H

#include <QtCore/qglobal.h>
#include "basedrawable.h"

class Figure : public BaseDrawable
{
public:
    Figure(){}
    virtual QPoint getCenter() = 0;
};

#endif // FIGURE_H
