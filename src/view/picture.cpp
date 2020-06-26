#include "picture.h"
#include <QMouseEvent>

Picture::Picture(QWidget *parent): QLabel(parent)
{
    this->setGeometry(0,0,parent->width(), parent->height());
}

void Picture::mouseMoveEvent(QMouseEvent *event)
{
    emit mouseMoved({event->x(), event->y()});
}

void Picture::mousePressEvent(QMouseEvent *event)
{
    emit mousePressed({event->x(), event->y()});
}

void Picture::mouseReleaseEvent(QMouseEvent *event)
{
    emit mouseReleased({event->x(), event->y()});
}

void Picture::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit mousePressed({event->x(), event->y()});
}
