#ifndef APPFRAME_H
#define APPFRAME_H

#include "QFrame"
#include <QPainter>
#include <iostream>


class AppFrame: public QFrame
{
public:
    AppFrame(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent *event);
    void plusWindowsX();
    void minusWindowsX();
    void plusWindowsY();
    void minusWindowsY();
};

#endif // APPFRAME_H
