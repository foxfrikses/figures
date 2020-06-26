#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    picture = new Picture(ui->picture_frame);
    setWindowTitle("Figures");
    statusBar()->showMessage("No operation is selected");
    setFixedSize(this->size());

    connect(ui->actionNew, SIGNAL(triggered()),
            this, SIGNAL(newPicture()));
    connect(picture, SIGNAL(mousePressed(QMouseEvent*)),
            this, SLOT(picturePressed(QMouseEvent*)));
    connect(picture, SIGNAL(mouseMoved(QMouseEvent*)),
            this, SLOT(pictureMoved(QMouseEvent*)));
    connect(picture, SIGNAL(mouseReleased(QMouseEvent*)),
            this, SLOT(pictureReleased(QMouseEvent*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::picturePressed(QMouseEvent *event)
{
    if (!isMousePressed){
        isMousePressed = true;
        mousePoint = {event->x(), event->y()};
        emit pressed(mousePoint);
    } else {
        isMousePressed = false;
        QPoint newMousePoint = {event->x(), event->y()};
        emit released(newMousePoint);
    }
}

void MainWindow::pictureMoved(QMouseEvent *event)
{
    if (isMousePressed){
        QPoint newMousePoint = {event->x(), event->y()};
        emit moved(newMousePoint);
    }
}

void MainWindow::pictureReleased(QMouseEvent *event)
{
    if (isMousePressed){
        QPoint newMousePoint = {event->x(), event->y()};
        if (newMousePoint != mousePoint){
            isMousePressed = false;
            emit released(newMousePoint);
        }
    }
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Info");
    msgBox.setText("Developer - Artsiom Shut");
    msgBox.setInformativeText("This is my project for OMP system");
    msgBox.exec();
}

void MainWindow::on_actionLoad_triggered()
{
    QString filter = "Figure File (*.fig)";
    auto file_name = QFileDialog::getOpenFileName(
        this,
        "Open a figure project",
        QDir::homePath(),
        filter
        );

    if (!file_name.isEmpty())
        emit loadFromFile(file_name);

}

void MainWindow::on_actionSave_as_picture_triggered()
{
    QString filter = "PNG file (*.png)";
    auto file_name = QFileDialog::getSaveFileName(
        this,
        "Save as png",
        QDir::homePath(),
        filter
        );

    if (!file_name.isEmpty())
        emit saveAsPNG(file_name);
}

void MainWindow::on_actionSave_as_figures_triggered()
{
    QString filter = "Figure File (*.fig)";
    auto file_name = QFileDialog::getSaveFileName(
        this,
        "Save as fig",
        QDir::homePath(),
        filter
        );

    if (!file_name.isEmpty())
        emit saveAsFIG(file_name);
}

void MainWindow::setPixmap(const QPixmap &pix){
    picture->setPixmap(pix);
}

void MainWindow::on_actionEllipse_triggered()
{
    emit setInstrum(Instrument::Ellipse);
    statusBar()->showMessage("Ellipse is selected");
}

void MainWindow::on_actionTriangle_triggered()
{
    emit setInstrum(Instrument::Triangle);
    statusBar()->showMessage("Triangle is selected");
}

void MainWindow::on_actionRectangle_triggered()
{
    emit setInstrum(Instrument::Rectangle);
    statusBar()->showMessage("Rectangle is selected");
}

void MainWindow::on_actionLine_triggered()
{
    emit setInstrum(Instrument::Line);
    statusBar()->showMessage("Line is selected");
}

void MainWindow::on_actionMove_triggered()
{
    emit setInstrum(Instrument::Hand);
    statusBar()->showMessage("Move is selected");
}
