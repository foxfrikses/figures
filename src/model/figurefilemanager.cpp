#include "figurefilemanager.h"

FigureFileManager::FigureFileManager()
{

}

void FigureFileManager::loadFromFIG(QString path, QLinkedList<Figure *>& figures,
                                    QLinkedList<Line> &lines) const
{
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    int nf, nl;
    in >> nf >> nl;
    QChar ch;
    int a, b, c, d;
    for (int i = 0; i < nf; ++i){
        in >> ch;
        if (ch == 'r' || ch == 'e' || ch == 't')
            in >> a >> b >> c >> d;

        if (ch == 'r')
            figures << new Rectangle(QRect(a, b, c-a, d-b));
        else if (ch == 'e')
            figures << new Ellipse(QRect(a, b, c-a, d-b));
        else if (ch == 't')
            figures << new Triangle(QRect(a, b, c-a, d-b));
    }

    for (int i = 0; i < nl; ++i){
        in >> ch >> a >> b;
        auto it_1 = figures.begin();
        auto it_2 = figures.begin();
        std::advance(it_1, a);
        std::advance(it_2, b);
        lines << Line(it_1, it_2);
    }
    file.close();
}

void FigureFileManager::saveAsPNG(QString path, const QPixmap& pixmap) const
{
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    pixmap.save(&file, "PNG");
    file.close();
}

void FigureFileManager::saveAsFIG(QString path, const QLinkedList<Figure *>& figures,
                                  const QLinkedList<Line> &lines) const
{
    QFile file(path + ".fig");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << figures.count() << lines.count();

    QChar ch;
    for (auto figure : figures){
        ch = figure->ch();
        if (ch == 'r'){
            auto f = (Rectangle*)figure;
            out << ch << f->left() << f->top() << f->right() << f->bottom();
        } else if (ch == 'e'){
            auto f = (Ellipse*)figure;
            out << ch << f->left() << f->top() << f->right() << f->bottom();
        } else if (ch == 't'){
            auto f = (Triangle*)figure;
            out << ch << f->left() << f->top() << f->right() << f->bottom();
        }
    }

    for (auto line : lines)
        out << line.ch() << (int)std::distance(figures.begin(), line.getFrom())
            << (int)std::distance(figures.begin(), line.getTo());

    file.close();
}
