#include "coordsengine.h"

CoordsEngine::CoordsEngine()
{

}

int CoordsEngine::getWindowWidth(){
    return MainWindow::width();
}
int CoordsEngine::getWindowHeight(){
    return MainWindow::height();
}
