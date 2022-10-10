#ifndef HOUSE_H
#define HOUSE_H

#include <QLine>
#include <QList>

class House
{
public:
    House(int x, int y);
    int x, y;
    QList<QLine> houseBuilder();
};

#endif // HOUSE_H
