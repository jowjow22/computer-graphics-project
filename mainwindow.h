#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <iostream>
#include <QUndoView>
#include <QResizeEvent>
#include "appframe.h"
#include <QRect>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent * event);
    ~MainWindow();
    int a, b, c, d;
    int *w = &a, *h = &b, *wOld = &c, *hOld = &d;
    void setIntWH(int *w, int *h, int *wOld, int* hOld);

private slots:

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
