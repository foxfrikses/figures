#include "whiteboard.h"

Whiteboard::Whiteboard(QSize size, QColor color, QObject *parent) :
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
    if (actionStarted){
        finishAction(p);
        return;
    }

    switch (instr) {
    case Instrument::None:
        return;
    case Instrument::Ellipse:
        figures.append(new Ellipse(QRect(p, p)));
        figureAdded = true;
        actionStarted = true;
        break;
    case Instrument::Triangle:
        figures.append(new Triangle(QRect(p, p)));
        figureAdded = true;
        actionStarted = true;
        break;
    case Instrument::Rectangle:
        figures.append(new Rectangle(QRect(p, p)));
        figureAdded = true;
        actionStarted = true;
        break;
    case Instrument::Hand:
        for (auto f = figures.rbegin(); f != figures.rend(); ++f)
            if ((*f)->includesPoint(p)){
                movingFigure = (*f);
                actionStarted = true;
                break;
            }
        break;
    case Instrument::Line:
        for (auto f = figures.rbegin(); f != figures.rend(); ++f)
            if ((*f)->includesPoint(p)){
                actionStarted = true;
                break;
            }
        break;
    }

    fstPoint = curPoint = p;
    draw();
}

void Whiteboard::tempAction(QPoint p)
{
    if (!actionStarted)
        return;

    switch (instr) {
    case Instrument::None:
        return;
    case Instrument::Line:
        break;
    case Instrument::Ellipse:
        if (!figures.empty())
            ((Ellipse*)figures.back())->setRect({fstPoint, p});
        break;
    case Instrument::Triangle:
        if (!figures.empty())
            ((Triangle*)figures.back())->setRect({fstPoint, p});
        break;
    case Instrument::Rectangle:
        if (!figures.empty())
            ((Rectangle*)figures.back())->setRect({fstPoint, p});
        break;
    case Instrument::Hand:
        if (!figures.empty())
            movingFigure->move(p - curPoint);
        break;
    }

    curPoint = p;
    draw();
}

void Whiteboard::finishAction(QPoint p)
{
    if (!actionStarted)
        return;

    switch (instr) {
    case Instrument::None:
        return;
    case Instrument::Ellipse:
    case Instrument::Triangle:
    case Instrument::Rectangle:
        if ( figureAdded && !figures.back()->isDrawable() ){
            delete figures.back();
            figures.pop_back();
        }
        break;
    case Instrument::Hand:
        if (movingFigure)
            movingFigure->move(p - curPoint);
        break;
    case Instrument::Line:
        auto riter_1 = figures.rbegin();
        auto riter_2 = figures.rbegin();

        while (riter_1 != figures.rend()) {
            if ((*riter_1)->includesPoint(fstPoint))
                break;
            ++riter_1;
        }
        if (riter_1 == figures.rend()) break;

        while (riter_2 != figures.rend()) {
            if ((*riter_2)->includesPoint(p))
                break;
            ++riter_2;
        }
        if (riter_2 == figures.rend()) break;


        auto iter_1 = figures.begin();
        auto iter_2 = figures.begin();

        while (*iter_1 != *riter_1)
            ++iter_1;
        while (*iter_2 != *riter_2)
            ++iter_2;
        lines.append(Line(iter_1, iter_2));
        break;
    }

    actionStarted = false;
    figureAdded = false;

    draw();
}

void Whiteboard::setInstrument(Instrument instr)
{
    finishAction(curPoint);
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
    finishAction(curPoint);
    pixmapColor = color;
    pixmap = QPixmap(size);
    pixmap.fill(pixmapColor);
    emit sendPixmap(pixmap);
}

void Whiteboard::saveAsPNG(QString path)
{

}

void Whiteboard::saveAsFIG(QString path)
{

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

    if (instr == Instrument::Line && actionStarted){
        QPainter painter(&pixmap);
        painter.drawLine(fstPoint, curPoint);
    }

    for (auto figure : figures)
        figure->draw(&pixmap);

    emit sendPixmap(pixmap);
}
