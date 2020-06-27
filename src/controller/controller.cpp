#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent)
{
    w = new MainWindow();
    b = new Whiteboard(w->getPictureSize());

    connect(w, SIGNAL(setInstrum(Instrument)),
            b, SLOT(setInstrument(Instrument)));
    connect(w, SIGNAL(loadFromFile(QString)),
            b, SLOT(load(QString)));
    connect(w, SIGNAL(newPicture()),
            b, SLOT(newBoard()));
    connect(w, SIGNAL(saveAsPNG(QString)),
            b, SLOT(saveAsPNG(QString)));
    connect(w, SIGNAL(saveAsFIG(QString)),
            b, SLOT(saveAsFIG(QString)));

    connect(w, SIGNAL(pressed(QPoint)),
            b, SLOT(startAction(QPoint)));
    connect(w, SIGNAL(moved(QPoint)),
            b, SLOT(tempAction(QPoint)));
    connect(w, SIGNAL(released(QPoint)),
            b, SLOT(finishAction(QPoint)));

    connect(b, SIGNAL(sendPixmap(const QPixmap&)),
            w, SLOT(setPixmap(const QPixmap&)));
}

Controller::~Controller()
{
    delete w;
    delete b;
}

void Controller::show()
{
    w->show();
}
