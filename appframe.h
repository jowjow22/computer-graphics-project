#ifndef APPFRAME_H
#define APPFRAME_H

#include "QFrame"
#include <QPainter>
#include <iostream>
#include <QResizeEvent>


class AppFrame: public QFrame
{
public:
    AppFrame(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
};

#endif // APPFRAME_H
