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

//void MainWindow::resizeEvent(QResizeEvent *event)
//{
//    AppFrame frame;
//    QMainWindow::resizeEvent(event);
//    *w = QWidget::width();
//    *h = QWidget::height();
//    ui->frame->setGeometry(ui->frame->x(),ui->frame->y(), *w, *h);
//}


//XVP = (QWidget::x()/1012)*506;
//YVP = (1-QWidget::y()/550)*550;
