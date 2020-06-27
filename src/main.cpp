

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QApplication>
#else
#include <QtGui/QApplication>
#endif

#include "controller/controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controller c;
    c.show();
    return a.exec();
}
