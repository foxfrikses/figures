#ifndef FIGUREFILEMANAGER_H
#define FIGUREFILEMANAGER_H

#include <QtCore/qglobal.h>
#include <QPixmap>
\
#include "figure.h"
#include "line.h"

class FigureFileManager
{
public:
    FigureFileManager();
    void loadFromFIG(QString, QLinkedList<Figure*>&, QLinkedList<Line>&) const;
    void saveAsPNG(QString, const QPixmap&) const;
    void saveAsFIG(QString, const QLinkedList<Figure*>&, const QLinkedList<Line>&) const;
};

#endif // FIGUREFILEMANAGER_H
