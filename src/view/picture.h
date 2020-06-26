#ifndef PICTURE_H
#define PICTURE_H

#include <QtCore/qglobal.h>
#include <QLabel>

class Picture : public QLabel
{
    Q_OBJECT
public:
    Picture(QWidget *parent);

private:
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

signals:
    void mousePressed(QMouseEvent*);
    void mouseReleased(QMouseEvent*);
    void mouseMoved(QMouseEvent*);
};

#endif // PICTURE_H
