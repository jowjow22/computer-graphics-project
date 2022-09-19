#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScreen>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

static int changed = 0;

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    AppFrame frame;
    QMainWindow::resizeEvent(event);
    if(changed == 0)
    {
        setIntWH(w, h, wOld, hOld);
    }
    std::cout << "\n" << *w << " " << *h << " " << *wOld << " " << *hOld << std::endl;
    *w = QWidget::width();
    *h = QWidget::height();
    std::cout << " "<< *w << " " << *h << " ";
    if(changed != 0){
        ui->frame->setGeometry(frame.x(),frame.y(), *w, *h);
        *wOld = *w;
        *hOld = *h;
    }

}

void MainWindow::setIntWH(int *w, int *h, int *wOld, int* hOld)
{
    *w = QWidget::width();
    *h = QWidget::height();
    *wOld =  QWidget::width();
    *hOld = QWidget::height();
    changed = 1;
}

