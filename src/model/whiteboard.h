#ifndef WHITEBOARD_H
#define WHITEBOARD_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>
#include <QLinkedList>

#include "instrument.h"
#include "figure.h"
#include "line.h"
#include "rectangle.h"
#include "ellipse.h"
#include "triangle.h"

class Whiteboard : public QObject
{
    Q_OBJECT
public:
    explicit Whiteboard(QSize size, QColor color = Qt::white, QObject *parent = nullptr);
    virtual ~Whiteboard();

protected:
    QLinkedList<Figure*> figures;
    QLinkedList<Line> lines;
    QPoint fstPoint;
    QPoint curPoint;
    bool actionStarted{false};
    bool figureAdded{false};
    Instrument instr = Instrument::None;
    QPixmap pixmap;
    QColor pixmapColor;
    Figure* movingFigure;

signals:
    void sendPixmap(const QPixmap&);

public slots:
    void startAction(QPoint);
    void tempAction(QPoint);
    void finishAction(QPoint);
public slots:
    void setInstrument(Instrument);
    void load(QString);
    void newBoard();
    void newBoard(QSize);
    void newBoard(QSize, QColor);
    void saveAsPNG(QString);
    void saveAsFIG(QString);
private:
    void clear();
    void draw();
};

#endif // WHITEBOARD_H
