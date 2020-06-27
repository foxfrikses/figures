#include "figurefilemanager.h"

FigureFileManager::FigureFileManager()
{

}

void FigureFileManager::loadFromFIG(QString, QLinkedList<Figure *> &, QLinkedList<Line> &) const
{

}

void FigureFileManager::saveAsPNG(QString path, const QPixmap& pixmap) const
{
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    pixmap.save(&file, "PNG");
}

void FigureFileManager::saveAsFIG(QString, const QLinkedList<Figure *> &, const QLinkedList<Line> &) const
{

}
