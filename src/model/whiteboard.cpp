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
    if (pointSet) {
        finishAction(p);
    } else {
        if (instr != Instrument::None){
            if (instr == Instrument::Hand){
                for (auto f = figures.rbegin(); f != figures.rend(); ++f)
                    if ((*f)->includesPoint(p)){
                        curFigure = (*f);
                        pointSet = true;
                        curPoint = p;
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

        draw();
    }
}

void Whiteboard::tempAction(QPoint p)
{
    if (instr != Instrument::None && pointSet){
        switch (instr) {
        case Instrument::Ellipse:
            ((Ellipse*)curFigure)->setRect({curPoint, p});
            break;
        case Instrument::Triangle:
            ((Triangle*)curFigure)->setRect({curPoint, p});
            break;
        case Instrument::Rectangle:
            ((Rectangle*)curFigure)->setRect({curPoint, p});
            break;
        case Instrument::Hand:
            curFigure->move(p - curPoint);
            curPoint = p;
            break;
        case Instrument::Line:
        case Instrument::None:
            break;
        }
    }

    draw();
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
    newBoard(pixmap.size(), pixmapColor);
}

void Whiteboard::newBoard(QSize size)
{
    newBoard(size, pixmapColor);
}

void Whiteboard::newBoard(QSize size, QColor color)
{
    clear();
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
    switch (instr) {
    case Instrument::Ellipse:
    case Instrument::Triangle:
    case Instrument::Rectangle:
        if (curFigure)
            if (!curFigure->isDrawable()){
                figures.pop_back();
                delete curFigure;
            }
    case Instrument::Hand:
    case Instrument::Line:
    case Instrument::None:
        break;
    }
    pointSet = false;
    curFigure = nullptr;
}

void Whiteboard::clear()
{
    pixmap.fill(pixmapColor);
    for (auto figure : figures)
        delete figure;
    figures.clear();
    lines.clear();
}

void Whiteboard::draw()
{
    pixmap.fill(pixmapColor);
    for (auto line : lines)
        line.draw(&pixmap);
    for (auto figure : figures)
        figure->draw(&pixmap);
    emit sendPixmap(pixmap);
}
