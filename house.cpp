#include "house.h"

int House::housesAmount = 0;

House::House(int x, int y)
{
    housesAmount += 1;
    this->houseIdentifier = housesAmount;
    this->x = x;
    this->y = y;
}

int House::getHouseIdentifier(){
    return this->houseIdentifier;
}

QList<QLine> House::houseBuilder(){

    return {
    QLine((x+50),(-50+y),(200+x),(-50+y)),
    QLine((x+200),(-100+y),(200+x),(-50+y)),
    QLine((x+50),(-100+y),(200+x),(-100+y)),
    QLine((x+80),(-60+y),(80+x),(-80+y)),
    QLine((x+80),(-60+y),(120+x),(-60+y)),
    QLine((x+80),(-80+y),(120+x),(-80+y)),
    QLine((x+120),(-60+y),(120+x),(-80+y)),
    QLine((x+150),(-100+y),(150+x),(-70+y)),
    QLine((x+150),(-70+y),(180+x),(-70+y)),
    QLine((x+50),(-50+y),(120+x),(-10+y)),
    QLine((x+120),(-10+y),(200+x),(-50+y)),
    QLine((x+50),(-100+y),(50+x),(-50+y)),
    QLine((x+180),(-70+y),(180+x),(-100+y))};

}
