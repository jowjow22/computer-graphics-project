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
};

#endif // APPFRAME_H
