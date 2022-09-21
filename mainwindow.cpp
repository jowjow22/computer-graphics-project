#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScreen>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    AppFrame frame;
    QMainWindow::resizeEvent(event);
    *w = QWidget::width()/2;
    *h = QWidget::height()/2;
    ui->frame->setGeometry(frame.x(),frame.y(), *w, *h);
}


//XVP = (QWidget::x()/1012)*506;
//XVP = (1-QWidget::y()/550)*550;

