#ifndef LINE_H
#define LINE_H

#include <QtCore/qglobal.h>
#include <QLinkedList>

#include "basedrawable.h"
#include "figure.h"

typedef QLinkedList<Figure*>::const_iterator iterator;

class Line : public BaseDrawable
{
public:
    Line(iterator, iterator);
    void draw(QPaintDevice*) const override;
    iterator getFrom() const {return from;}
    iterator getTo() const {return to;}
    QChar ch() const override {return 'l';}

protected:
    iterator from, to;
};

#endif // LINE_H
