#include "window.h"

Window::Window()
{

}

void setWindow() {
    painter.setWindow(-50, -50, 100, 100);
    int side = qMin(width(), height());
    int x = (width() - side / 2);
    int y = (height() - side / 2);

    painter.setViewport(x, y, side, side);
}
