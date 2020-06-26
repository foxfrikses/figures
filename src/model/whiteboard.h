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
    explicit Whiteboard(QSize size, QObject *parent = nullptr, QColor color = Qt::white);
    virtual ~Whiteboard();

protected:
    QLinkedList<Figure*> figures;
    QLinkedList<Line> lines;
    QPoint curPoint;
    bool curPointSet{false};
    Instrument instr = Instrument::None;
    QPixmap pixmap;

signals:
    void sendPixmap(const QPixmap&);

public slots:
    void startPoint(QPoint);
    void tempPoint(QPoint);
    void finishPoint(QPoint);
public slots:
    void setInstrument(Instrument);
    void load(QString);
    void newBoard();
    void newBoard(QSize);
    void saveAsPNG(QString);
    void saveAsFIG(QString);
};

#endif // WHITEBOARD_H
