#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>

#include "view/mainwindow.h"
#include "model/whiteboard.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    virtual ~Controller();
    void show();

    MainWindow *w;
    Whiteboard *b;
};

#endif // CONTROLLER_H
