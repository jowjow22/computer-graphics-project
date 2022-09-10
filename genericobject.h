#ifndef GENERICOBJECT_H
#define GENERICOBJECT_H
#include "QPainter"
#include <iostream>


class GenericObject
{
public:
    GenericObject();
    virtual void drawObject(QPainter *painter);
    virtual ~GenericObject()
    { }
};

#endif // GENERICOBJECT_H
