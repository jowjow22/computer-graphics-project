#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QUndoView>
#include <QResizeEvent>
#include <QRect>
#include <QPainter>
#include <QPen>
#include "window.h"
#include "genericobject.h"
#include "point.h"
#include "line.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QList<QList<QLine>> worldObjectList;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent *event);
    void coordsWindowToViewport(QList<GenericObject *> *displayFile, Window window, Point *p);
    void addPointToDisplayFile(QList<GenericObject *> *displayFile, Point *p);
    void plusWindowsX();
    void minusWindowsX();
    void plusWindowsY();
    void minusWindowsY();
    void plusWindowsScale();
    void downWindowsScale();
    void plusObjectAngle();
    void downObjectAngle();
    void plusObjectScale();
    void downObjectScale();
    void plusObjectPosX();
    void downObjectPosX();
    QLine transformLineToQLine(Line line);
    QList<QLine> transformListOfLinesToListOfQLines(QList<Line> list);

private slots:

    void on_comboBox_currentIndexChanged(int index);

    void on_verticalSlider_sliderMoved(int position);

    void on_horizontalSlider_sliderMoved(int position);

    void on_dial_sliderMoved(int position);

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_dial_2_sliderMoved(int position);

    void on_dial_3_sliderMoved(int position);

    void on_spinBox_3_valueChanged(int arg1);

    void on_spinBox_4_valueChanged(int arg1);

    void on_spinBox_5_valueChanged(int arg1);

    void on_spinBox_6_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
