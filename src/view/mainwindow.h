#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QMainWindow>
#else
#include <QtGui/QMainWindow>
#endif

#include "instrument.h"
#include "picture.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void picturePressed(QMouseEvent*);
    void pictureMoved(QMouseEvent*);
    void pictureReleased(QMouseEvent*);

    void on_actionExit_triggered();
    void on_actionAbout_triggered();
    void on_actionLoad_triggered();
    void on_actionSave_as_picture_triggered();
    void on_actionSave_as_figures_triggered();
    void on_actionEllipse_triggered();
    void on_actionTriangle_triggered();
    void on_actionRectangle_triggered();
    void on_actionLine_triggered();
    void on_actionMove_triggered();

signals:
    void setInstrum(Instrument);
    void loadFromFile(QString);
    void newPicture();
    void saveAsPNG(QString);
    void saveAsFIG(QString);

    void pressed(QPoint);
    void moved(QPoint);
    void released(QPoint);
public slots:
    void setPixmap(const QPixmap &);

private:
    bool isMousePressed{false};
    QPoint mousePoint;

private:
    Picture *picture;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
