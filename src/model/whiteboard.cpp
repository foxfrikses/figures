#include "whiteboard.h"

Whiteboard::Whiteboard(QSize size, QObject *parent, QColor color) :
    QObject(parent),
    pixmap{QPixmap(size)}
{
    pixmap.fill(color);
}

Whiteboard::~Whiteboard()
{
    for (auto figure : figures)
        delete figure;
}

void Whiteboard::startPoint(QPoint p)
{

}

void Whiteboard::tempPoint(QPoint p)
{

}

void Whiteboard::finishPoint(QPoint p)
{

}

void Whiteboard::setInstrument(Instrument instr)
{

}

void Whiteboard::load(QString path)
{

}

void Whiteboard::newBoard()
{

}

void Whiteboard::newBoard(QSize size)
{

}

void Whiteboard::saveAsPNG(QString path)
{

}

void Whiteboard::saveAsFIG(QString path)
{

}
