#ifndef HOUSE_H
#define HOUSE_H

#include <QLine>
#include <QList>

class House: public QLine
{
public:
    House(int x, int y);
    static int housesAmount;
    QString houseName;
    QList<QLine> houseBuilder();
    int getHouseIdentifier();
private:
    int x, y;
    int houseIdentifier;
};

#endif // HOUSE_H
