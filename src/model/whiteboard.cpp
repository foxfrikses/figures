#include "whiteboard.h"

Whiteboard::Whiteboard(QSize size, QObject *parent, QColor color) :
    QObject(parent),
    pixmap{QPixmap(size)},
    pixmapColor{color}
{
    pixmap.fill(pixmapColor);
}

Whiteboard::~Whiteboard()
{
    for (auto figure : figures)
        delete figure;
}

void Whiteboard::startAction(QPoint p)
{
    if (instr != Instrument::None){
        if (instr == Instrument::Hand){
            for (auto f = figures.rbegin(); f != figures.rend(); ++f)
                if ((*f)->includesPoint(p)){
                    curFigure = (*f);
                    break;
                }
        } else if (instr == Instrument::Line) {

        } else {
            switch (instr) {
            case Instrument::Ellipse:
                curFigure = new Ellipse(QRect(p, p));   break;
            case Instrument::Triangle:
                curFigure = new Triangle(QRect(p, p));  break;
            case Instrument::Rectangle:
                curFigure = new Rectangle(QRect(p, p)); break;
            case Instrument::Hand:
            case Instrument::Line:
            case Instrument::None:
                return;
            }
            figures.append(curFigure);
            curPoint = p;
            pointSet = true;
        }
    }
}

void Whiteboard::tempAction(QPoint p)
{
    if (instr != Instrument::None){
        switch (instr) {
        case Instrument::Ellipse:
            ((Ellipse*)curFigure)->setRect({startPoint, p});
        case Instrument::Triangle:
            ((Triangle*)curFigure)->setRect({startPoint, p});
        case Instrument::Rectangle:
            ((Rectangle*)curFigure)->setRect({startPoint, p});
        case Instrument::Hand:
            curFigure->move(p - curPoint);
            curPoint = p;
        case Instrument::Line:
        case Instrument::None:
            break;
        }
    }
}

void Whiteboard::finishAction(QPoint p)
{
    tempAction(p);
    stopAction();
}

void Whiteboard::setInstrument(Instrument instr)
{
    stopAction();
    this->instr = instr;
}

void Whiteboard::load(QString path)
{

}

void Whiteboard::newBoard()
{
    stopAction();
    pixmap = QPixmap(pixmap.size());
    pixmap.fill(pixmapColor);
}

void Whiteboard::newBoard(QSize size)
{
    stopAction();
    pixmap = QPixmap(size);
    pixmap.fill(pixmapColor);
}

void Whiteboard::newBoard(QSize size, QColor color)
{
    stopAction();
    pixmapColor = color;
    pixmap = QPixmap(size);
    pixmap.fill(pixmapColor);
}

void Whiteboard::saveAsPNG(QString path)
{

}

void Whiteboard::saveAsFIG(QString path)
{

}

void Whiteboard::stopAction()
{
    pointSet = false;
    switch (instr) {
    case Instrument::Ellipse:
    case Instrument::Triangle:
    case Instrument::Rectangle:
        if (curFigure)
            if (!curFigure->isDrawable())
                figures.pop_back();
    case Instrument::Hand:
    case Instrument::Line:
    case Instrument::None:
        break;
    }
    curFigure = nullptr;
}
